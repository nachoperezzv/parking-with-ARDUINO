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

#include "button.h"

//Gestion del boton


//Constructor
Button::Button(){
  pinMode(pinButton,INPUT);
}

Button::~Button(){}

bool Button::getButton(){
  return digitalRead(pinButton);
}
