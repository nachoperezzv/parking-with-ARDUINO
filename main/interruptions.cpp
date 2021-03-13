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

void setISR(){
  attachInterrupt(digitalPinToInterrupt(pinISR1),ISR_BE, RISING);
  attachInterrupt(digitalPinToInterrupt(pinISR2),ISR_BS, RISING);
}

void ISR_BE(){

  
}

void ISR_BS(){

  
}
