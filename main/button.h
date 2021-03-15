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

#include "parking.h"

const int pinButton = 10;

class Button 
{
   public:
    Button();
    ~Button();
    
    bool getButton();
    bool getButtonStatus();

   protected:
    bool button_status;
   
};


#endif // BUTTON_H
