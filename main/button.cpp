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
//Destructor
Button::~Button(){}
//Lectura del estado del botón
bool Button::getButton(){
  return digitalRead(pinButton);
}
