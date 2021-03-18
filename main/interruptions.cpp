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

volatile bool T = true;

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
  
  while(T){
    bool estate = but.getButton();
    if(estate or Serial.readString() == "0"){
      if(estate)
        Serial.print(0);
      if(Serial.readString() == "1")
        barE.barrierUp();

      /*
       * while(digitalRead(PinSensor) == 0){ //Sensor cuando detecta coche = 0
       *  //Do nothing
       * }
       * Serial.print("1",char); //Envia a Matlab señal de que ya no hay coche
       * 
       */      
      delay(1000);

      /*
       * Serial.print(1);
       */
      barE.barrierDown();
      
      screen.closeScreen();

      T = false;
    }
  }
  T = true;
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
