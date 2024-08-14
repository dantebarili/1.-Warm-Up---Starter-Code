/**
 * @brief Orbital simulation
 * @author Marc S. Ressl
 *
 * @copyright Copyright (c) 2022-2023
 */

#ifndef ORBITALSIM_H
#define ORBITALSIM_H

#include "raylib.h"
#include "raymath.h"

#include <stdlib.h>
#include <string.h>

//para calculos
#include <math.h>
#include <stdint.h>

#define SOLARSYSTEM_BODYNUM 9

/**
 * @brief Orbital body definition
 */
typedef struct{

    const char *nombre;
    float masa;
    float radio; 
    Color color;
    Vector3 posicion;
    Vector3 velocidad;
    /*
    //atributos espciales
    int8_t anillos; // flag para saber si tiene anillos
    //opcional: puede hacer alto bardo
    uint8_t cantidadSatelites;
    struct OrbitalBody_s** satelites; // habria q poner TAG
    */

}OrbitalBody;

/**
 * @brief Orbital simulation definition
 */
typedef struct{
    
    float timeStep;
    uint8_t cantidadCuerpos;
    OrbitalBody** cuerposCel;   // ** ya que cuerposCel esta definido en el Heap. 
                                // Crear los OrbitalBody con una funcion.

}OrbitalSim;

OrbitalSim *constructOrbitalSim(float timeStep);
void destroyOrbitalSim(OrbitalSim *sim);

void updateOrbitalSim(OrbitalSim *sim);

OrbitalBody * crearSistemaSolar();

#endif
