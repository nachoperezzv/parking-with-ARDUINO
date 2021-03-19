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

#include <LiquidCrystal.h>
#include "parking.h"

#define PIN_RS 12
#define PIN_EN 11
#define PIN_D4 4
#define PIN_D5 5
#define PIN_D6 6
#define PIN_D7 7 

class LCD
{
  public:
    LCD();
    ~LCD();

    void printWelcome();
    void printGoodbye();
    void closeScreen();
};

#endif // LCD.H
