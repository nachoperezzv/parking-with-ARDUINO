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
 
#ifndef INTERRUPTIONS_H
#define INTERRUPTIONS_H

#include "parking.h"    //Se tiene acceso a button.h, barrier.h y lcd.h

//Pines de interrupción
const int pinISR1 = 2;
const int pinISR2 = 3;

//Variables que pueden cambiar su estado
volatile bool ISRBE = false;
volatile bool ISRBS = false;

//Nombres de las funciones de las interrupciones
void ISR_BE();
void ISR_BS();

void setISR(){
  attachInterrupt(digitalPinToInterrupt(pinISR1),ISR_BE, RISING);
  attachInterrupt(digitalPinToInterrupt(pinISR2),ISR_BS, RISING);
}

void ISR_BE(){
  ISRBE = true;    
}

void ISR_BS(){
  ISRBS = true;  
}

#endif // interruptions.h
