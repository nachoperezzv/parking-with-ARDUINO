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

#include "interruptions.h"

const int pinISR1 = 2;
const int pinISR2 = 3;

const int waiting_time = 5000;

volatile bool T = true;


void setISR(){
  attachInterrupt(digitalPinToInterrupt(pinISR1),ISR_BE, RISING);
  attachInterrupt(digitalPinToInterrupt(pinISR2),ISR_BS, RISING);
}

void ISR_BE(){
  LCD screen;
  Button but;
  Barrier barE;
  
  screen.printWelcome(); //Funcion LCD
  
  while(T){
    bool estate = but.getButton();
    
    if(estate or (Serial.readString() == "0")){ //Lee si se ha pulsado boton (tanto interfaz como placa)
      Serial.println("2");            //Le indica a Matlab que el sensor detecta coche. Sensor activado

      if(Serial.readString() == "1")  //Matlab indica que si caben coches
        barE.barrierUp();

      /*
       * while(digitalRead(PinSensor) == 0){ //Sensor cuando detecta coche = 0
       *  //Do nothing
       * }
       * Serial.print("1",char); //Envia a Matlab señal de que ya no hay coche
       * 
       */      
      while (digitalRead(pinISR1) == 0){
        //Bucle que espera mientras detecte presencia
      }
      
      barE.barrierDown();   //Se baja la barrera
      
      screen.closeScreen(); //Se apaga la pantalla LCD

      T = false;            //Se sale del bucle
    }
  }
  T = true;     //Se pone en True de nuevo para cuando se vuelva a detectar otro coche, que entre en 
                //el bucle.(Volatile guarda el estado de una llamada a otra)
}

void ISR_BS(){
  LCD screen;
  Barrier barS;
  
  unsigned long time_;

  screen.printGoodbye();
  barS.barrierUp();
  
  time_ = millis();
  while(millis()- time_ <= waiting_time){ /*Tiempo espera coche salga*/ }

  barS.barrierDown();

  screen.closeScreen();
}
