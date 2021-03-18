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
}
