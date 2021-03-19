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

#include "parking.h"
#include "interruptions.h"

void setup(){
  Serial.begin(19200);
  Serial.setTimeout(1500);
  setISR();
}

void loop() {
  //Bucle vacío, mientras que no salten interrupciones el sistema en standby

//  Esto es solo en caso de que Arduino, al ser esclavo necesite ester mandando todo el rato
//  información a Matlab. Lo que se hace aquí es que si el boton es pulsado (en la interfaz)
//  pero no se ha detectado ningún coche (no ha saltado la interrupción), se le devuelve a
//  MatLab un valor que corresponde con: "NO HAY COCHE"
//    
//  OJO: da error escrito así por el uso de las variables ISR1 Y ISR2
//
//  if(!ISR1)
//    Serial.println("4");
//    
//  if(!ISR2)
//    Serial.println("4");

  if(Serial.readString() == "0")  //Si el boton de la interfaz de Matlab se pulsa pero el sensor no detecta
    Serial.println("4");    //presencia, se le envia un mensaje a Matlab (4 = No hay presencia de coche)

}
