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

const int waiting_time = 5000;

void setISR(){
  attachInterrupt(digitalPinToInterrupt(pinISR1),ISR_BE, RISING);
  attachInterrupt(digitalPinToInterrupt(pinISR2),ISR_BS, RISING);
}

void ISR_BE(){
  LCD screen;
  Button but;
  Barrier barE;
  
  unsigned long time_;
  
  screen.printWelcome(); //Funcion LCD
  
  while(true){
    if(but.getButton()){
      barE.barrierUp();

      time_ = millis();
      while(millis()- time_ <= waiting_time){ /*Tiempo espera coche entra*/ }

      barE.barrierDown();
      screen.closeScreen();

      if(but.getButtonStatus())
        break;
    }
  }
}

void ISR_BS(){
  LCD screen;
  Barrier barS;
  
  unsigned long time_;

  screen.printGoodbye();
  barS.barrierUp();
  
  time_ = millis();
  while(millis()- time_ <= waiting_time){ /*Tiempo espera coche salga*/ }

  barS.barrierDown();

  screen.closeScreen();
}
