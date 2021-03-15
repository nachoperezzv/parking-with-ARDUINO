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

#include "interruptions.h"

const int pinISR1 = 2;
const int pinISR2 = 3;

void setISR(){
  attachInterrupt(digitalPinToInterrupt(pinISR1),ISR_BE, RISING);
  attachInterrupt(digitalPinToInterrupt(pinISR2),ISR_BS, RISING);
}

void ISR_BE(){
  unsigned long time_;
  
  printWelcome(); //Funcion LCD
  
  while(true){
    if(but.getButton()){
      barE.barrierUp();

      time_ = millis();
      while(millis()- time_ <= waiting_time){ /*Tiempo espera coche entra*/ }

      BE.barrierDown();
      closeScreen();

      if(getButtonStatus())
        break;
    }
  }
}

void ISR_BS(){
  unsiegned long time_;

  printGoodbye();
  barS.barrierUp();
  
  time_ = millis();
  while(millis()- time_ <= waiting_time){ /*Tiempo espera coche salga*/ }

  barS.barrierDown();

  closeScreen();
}
