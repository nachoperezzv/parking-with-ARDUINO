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

#include "barrier.h"


//Estado barrera igual a leds. Se crean dos objetos de la clase barrera, uno para barrara
//salida y el otro para barrera entrada. Los leds corresponden al estado abierta cerrada
//led verde -> barrera up    -> pin 8 (pinBU)
//led rojo  -> barrera down  -> pin 9 (pinBD)


Barrier::Barrier(){
  barrier_status = false;
  pinMode(pinBU,OUTPUT);    digitalWrite(pinBU, LOW);
  pinMode(pinBD,OUTPUT);    digitalWrite(pinBD, HIGH);
}

Barrier::~Barrier() {}

//Bajar barrera o barrera bajada
bool Barrier::barrierDown(){
  digitalWrite(pinBD,HIGH);
  digitalWrite(pinBU,LOW);

  return true;
}

//Subir barrera o barrera subida
bool Barrier::barrierUp(){
  digitalWrite(pinBD,LOW);
  digitalWrite(pinBU,HIGH);

  return true;
}
