/*
 *                    Detectores industriales de presencia y proximidad
 * 
 * Cadavid Piñero, Leopoldo
 * Penalva Martínez, Franciso
 * Pérez Vilaplana, Ignacio
 * Salcedo Salcedo, Raquel
 * 
 *                                                                                    Marzo, 2021  
 */

//Librerias internas utilizadas
#include "parking.h"
#include "interruptions.h"

//Objetos creados
LCD screen;
Button but;
Barrier barE;
Barrier barS;

//Variables utilizadas
bool T = true;
bool Est = false;

volatile int numCoches = 0;

//SetUp del programa
void setup(){
  Serial.begin(19200);
  Serial.setTimeout(3200);
  setISR();
}

void loop() {
  
  if(ISRBE){     
    noInterrupts();   
    screen.printWelcome(); //Funcion LCD  
      
    while(T){            
      if(but.getButton() or (Serial.readString() == "0")){  //Lee si se ha pulsado boton 
                                                            //(tanto interfaz como placa)
        Serial.println("1");  //Le indica a Matlab que el sensor detecta coche                                                      
        if((maxCoches - numCoches) > 0){  
          if(Serial.readString() == "1" and maxCoches-numCoches>0){
            Serial.println("2");
            numCoches = numCoches + 1;
                        
            barE.barrierUp();     //Al caber, se levanta la barrera     
         
            while (digitalRead(pinISR1) == 0){
              //Bucle que espera mientras detecte presencia, para no bajar la barrera mientras 
              //el coche esta pasando
            }
          }
          barE.barrierDown();   //Se baja la barrera una vez no se detecta coche
          screen.closeScreen(); //Se apaga la pantalla LCD
        }
        T = false;              //Se sale del bucle principal
      }   
    }
    T = true;     //Se pone en True de nuevo para cuando se vuelva a detectar otro coche, que entre en 
                  //el bucle.(Volatile guarda el estado de una llamada a otra)
  
    ISRBE = false;
                  //Se cambia para que cuando el sensor deje de detectar, la interrupción no salte
                  //y no cambie el valor de la variable a true, impidiendo que entre en este
                  //segmento de codigo.
    interrupts();
  }

  if(ISRBS){
    noInterrupts();         //Se desactivan las interrupciones momentanemente para que no salte 
                            //mientras aun detecta el coche. Más tarde se vuelve a activar para 
                            //saber si continua habiendo o no coche.
    Serial.println("3");    //Le indica a Matlab que esta saliendo un coche para que aumente el
                            //contador de plazas libres
    screen.printGoodbye();
    barS.barrierUp();
    
    if(numCoches>0)
      numCoches = numCoches - 1;
    
    while(digitalRead(pinISR2) == 0){
      //Bucle que espera mientras detecte presencia, para no bajar la barrera mientras 
      //el coche esta pasando
    }
    
    barS.barrierDown();
    screen.closeScreen();
    
    ISRBS = false;
                  //Se cambia para que cuando el sensor deje de detectar, la interrupción no salte
                  //y no cambie el valor de la variable a true, impidiendo que entre en este
                  //segmento de codigo.
    interrupts();
  }

  Serial.flush();
  if((!ISRBE or !ISRBS) and Serial.readString() == "0")
    Serial.println("4");
                //En el caso en el que la interrupcion no se haya activado y se pulse el boton de la 
                //interfaz se mandará un mensaje a MatLab indicando una solicitud denegada
}
