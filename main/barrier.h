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

#ifndef BARRIER_H
#define BARRIER_H

#include <Arduino.h>

const int pinBU = 8;
const int pinBD = 9;

class barrier 
{
  public:
    barrier();
    ~barrier();

    bool barrierUp();
    bool barrierDown();
    
  protected:  
    bool barrier_status;    
  
};

#endif //BARRIER_H
