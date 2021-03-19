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

//Nombres de las funciones de las interrupciones
void setISR();

void ISR_BE();
void ISR_BS();


#endif // interruptions.h
