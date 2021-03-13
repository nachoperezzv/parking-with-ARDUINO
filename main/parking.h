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
#include <LiquidCrystal.h>

#include "barrier.h"
#include "button.h"
#include "lcd.h"

//MACROS
#define maxCoches 100
#define minCoches 0

#define PIN_RS 2
#define PIN_EN 3
#define PIN_D4 4
#define PIN_D5 5
#define PIN_D6 6
#define PIN_D7 7

//VARIABLES: 
volatile int numCoches;

const int pinBU = 8;
const int pinBD = 9;
const int pinButton = 10;

//FUNCIONES:
void setUp();

#endif // parking.h
