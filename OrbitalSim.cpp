/**
 * @brief Orbital simulation
 * @author Marc S. Ressl
 *
 * @copyright Copyright (c) 2022-2023
 */

// Enables M_PI #define in Windows
#define _USE_MATH_DEFINES

#include "OrbitalSim.h"

#define GRAVITATIONAL_CONSTANT 6.6743E-11F
#define ASTEROIDS_MEAN_RADIUS 4E11F

/**
 * @brief Gets a uniform random value in a range
 *
 * @param min Minimum value
 * @param max Maximum value
 * @return The random value
 */
float getRandomFloat(float min, float max)
{
    return min + (max - min) * rand() / (float)RAND_MAX;
}

/**
 * @brief Configures an asteroid
 *
 * @param body An orbital body
 * @param centerMass The mass of the most massive object in the star system
 */
void configureAsteroid(OrbitalBody *body, float centerMass)
{
    // Logit distribution
    float x = getRandomFloat(0, 1);
    float l = logf(x) - logf(1 - x) + 1;

    // https://mathworld.wolfram.com/DiskPointPicking.html
    float r = ASTEROIDS_MEAN_RADIUS * sqrtf(fabsf(l));
    float phi = getRandomFloat(0, 2.0F * (float)M_PI);

    // Surprise!
    // phi = 0;

    // https://en.wikipedia.org/wiki/Circular_orbit#Velocity
    float v = sqrtf(GRAVITATIONAL_CONSTANT * centerMass / r) * getRandomFloat(0.6F, 1.2F);
    float vy = getRandomFloat(-1E2F, 1E2F);

    // Fill in with your own fields:
    // body->mass = 1E12F;  // Typical asteroid weight: 1 billion tons
    // body->radius = 2E3F; // Typical asteroid radius: 2km
    // body->color = GRAY;
    // body->position = {r * cosf(phi), 0, r * sinf(phi)};
    // body->velocity = {-v * sinf(phi), vy, v * cosf(phi)};
}

/**
 * @brief Constructs an orbital simulation
 *
 * @param float The time step
 * @return The orbital simulation
 */
OrbitalSim *constructOrbitalSim(float timeStep)
{
    //return NULL;
    static OrbitalSim sim;
    // perdon franco que avance aca pero lo necesito
    // para hacer la prueba para saber si funciona viewrender (aerchivo view)
    sim.cuerposCel = (OrbitalBody**)malloc(sizeof(OrbitalBody*));
    sim.cuerposCel[0] = (OrbitalBody*)malloc(sizeof(OrbitalBody));
    sim.cuerposCel[0]->nombre = (char*)malloc(sizeof(char)*4);

    sim.cuerposCel[0]->nombre = "Sol";
    sim.cuerposCel[0]->masa = 1988500E24F;
    sim.cuerposCel[0]->radio = 0.005F*logf(695700E3F);
    sim.cuerposCel[0]->color = GOLD;
    sim.cuerposCel[0]->posicion = (Vector3){-1.283674643550172E+09F*1E-11, 2.589397504295033E+07F*1E-11, 5.007104996950605E+08F*1E-11};
    sim.cuerposCel[0]->velocidad = (Vector3){0, 0, 0};
    sim.cantidadCuerpos = 1;
    sim.timeStep = timeStep;

    return &sim;
  
    /*
    OrbitalBody** cuerposCelestes;

    int i, j;

    if((cuerposCelestes = (OrbitalBody**)malloc(sizeof(OrbitalBody*)*SOLARSYSTEM_BODYNUM)) == NULL){
        // error en la asignacion de memoria en el heap
        exit(1);
    }

    for(i = 0; i<SOLARSYSTEM_BODYNUM; i++){
        if(cuerposCelestes[i] = (OrbitalBody*)malloc(sizeof(OrbitalBody))){
            exit(1);
        }
    }

    // Hardcodeamos los atributos de los planetas del sistema solar
    crearSistemaSolar(cuerposCelestes);

    sim.cuerposCel = cuerposCelestes;

    return &sim; // This should return your orbital sim
    */
    
}

/**
 * @brief Destroys an orbital simulation
 */
void destroyOrbitalSim(OrbitalSim *sim)
{
    
    // free del malloc

}

/**
 * @brief Simulates a timestep
 *
 * @param sim The orbital simulation
 */
void updateOrbitalSim(OrbitalSim *sim)
{
    // Se le indica a la funcion encargada de mover los cuerpos celestes cual es 
    // la struct de la simulacion y cuanto el tiempo que queremos que pase(campo de sim).

    //avanzaTiempo(sim, sim->timeStep);

}

void crearSistemaSolar(OrbitalBody** cuerposCelestes){
    
    int i, c;

    /*
    for(i=0; i<SOLARSYSTEM_BODYNUM; i++){
        // Copio todos los atributos

        // -------NOMBRE-------
        // reservo espacio en el Heap para el nombre
        if(((cuerposCelestes[i]->nombre = (char*)malloc(sizeof(sistemaSolar[i].name))) == NULL)){
            // error en la asignacion de memoria en el heap
            exit(1);
        }

        for(c=0; sistemaSolar[i].name[c] != '\0'; c++){    
            cuerposCelestes[i]->nombre[c] = sistemaSolar[i].name[c];
        }

        cuerposCelestes[i]->nombre[c] = '\0';

        // -------DEMAS ATRIBUTOS PRESENTES EN EFEMERIDESBODY-------

        cuerposCelestes[i]->masa = sistemaSolar[i].mass;
        cuerposCelestes[i]->radio = sistemaSolar[i].radius;
        cuerposCelestes[i]->color = sistemaSolar[i].color;
        cuerposCelestes[i]->posicion = sistemaSolar[i].position;    //en C++ una struct es Lvalue
        cuerposCelestes[i]->velocidad = sistemaSolar[i].velocity;
        
        if(!strncmp(cuerposCelestes[i]->nombre,"Saturno",100)){
            cuerposCelestes[i]->anillos = 1;
        }else{
            cuerposCelestes[i]->anillos = 0;
        }

        //satelites (aun no configurado)
        cuerposCelestes[i]->cantidadSatelites = 0;
        cuerposCelestes[i]->satelites = NULL;

    }
    */

}

