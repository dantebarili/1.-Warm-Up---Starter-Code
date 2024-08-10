/**
 * @brief Orbital simulation
 * @author Marc S. Ressl
 *
 * @copyright Copyright (c) 2022-2023
 */

#ifndef ORBITALSIM_H
#define ORBITALSIM_H

<<<<<<< HEAD
/**
 * @brief Orbital body definition
 */
struct OrbitalBody
{
    // Fill in your code here...


};
=======
#include "raymath.h"
#include <stdint.h>

/**
 * @brief Orbital body definition
 */
typedef struct{

    const char *nombre; // Name
    Vector3 posicion;
    Vector3 velocidad;
    float masa;
    float radio;
    Color color;

}OrbitalBody;
>>>>>>> a655075 (con error de inclusion)

/**
 * @brief Orbital simulation definition
 */
<<<<<<< HEAD
struct OrbitalSim
{
    // Fill in your code here...


};
=======
typedef struct{
    
    uint64_t time_step;
    uint8_t cantidadCuerpos;
    OrbitalBody** cuerposCel;   // ** ya que cuerposCel esta definido en el Heap. 
                                // Crear los OrbitalBody con una funcion.

}OrbitalSim;
>>>>>>> a655075 (con error de inclusion)

OrbitalSim *constructOrbitalSim(float timeStep);
void destroyOrbitalSim(OrbitalSim *sim);

void updateOrbitalSim(OrbitalSim *sim);

#endif
