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

#include "parking.h"

const int pinBU = 8;
const int pinBD = 9;

class Barrier 
{
  public:
    Barrier();
    ~Barrier();

    bool barrierUp();
    bool barrierDown();

    bool getBarrierStatus();
    
  protected:  
    bool barrier_status;    
  
};

#endif //BARRIER_H
