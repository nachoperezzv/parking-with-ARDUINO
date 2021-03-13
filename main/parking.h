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
 
#ifndef PARKING_h
#define PARKING_H

#include <Arduino.h>
#include "barrier.h"
#include "button.h"
#include "lcd.h"

//MACROS
#define maxCoches 100
#define minCoches 0

//VARIABLES: 
volatile int numCoches;

//FUNCIONES:
void setUp();

#endif // parking.h
