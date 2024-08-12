/**
 * @brief Orbital simulation main module
 * @author Marc S. Ressl
 *
 * @copyright Copyright (c) 2022-2023
 */

#include "OrbitalSim.h"
#include "View.h"
#include<time.h>

#define SECONDS_PER_DAY 86400
#define FPS 60
#define time TIME_MULT ((SECONDS_PER_DAY)*(100)/FPS)

int main()
{
    
    unsigned long int timeStep = ((clock())*TIME_MUlT);

    OrbitalSim *sim = constructOrbitalSim(timeStep);
    View *view = constructView(fps);

    while (isViewRendering(view))
    {
        updateOrbitalSim(sim);

        renderView(view, sim);
    }

    destroyView(view);
    destroyOrbitalSim(sim);

    return 0;
}
