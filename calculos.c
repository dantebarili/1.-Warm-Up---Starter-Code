#include "calculos.h"

// brief provisorio: la funcion tiene que hacer los calculos para que varie la posicion
// y velocidad de todos los cuerpos y almacenarlo denuevo en los orbital bodys
void avanzaTiempo(OrbitalSim* sim, int64_t tiempo){
    
    int i, j;
    
    for(i = 0; i<sim->cantidadCuerpos;i++){
        
        for(j=0; j<sim->cantidadCuerpos;j++){
            
            if(i==j)
                continue;

            Vector3 aceleracion;

        }
        
    }

}