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

#ifndef BUTTON_H
#define BUTTON_H 

#include <Arduino.h>

const int pinButton = 10;

class button 
{
   public:
    button();
    ~button();
    
    bool getButton();

   protected:
    bool button_status;
   
};


#endif // BUTTON_H
