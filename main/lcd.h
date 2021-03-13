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

#ifndef LCD_H
#define LCD_H

#include "parking.h"

LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7); 

//setUp pantalla LCD:
void setUpLCD();

//Funciones LCD
void printWelcome();
void printNumCoches();
void printGoodbye();

#endif // LCD.H
