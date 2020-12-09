//
// Created by lijie on 9/6/18.
//

#ifndef ARGUS_DISTRIBUTION_SIMULATOR_H
#define ARGUS_DISTRIBUTION_SIMULATOR_H

#include <memory>
#include <integrators/integrator.h>
#include <display/timestep.h>

#ifndef WIN32
#	define ARGUS_SIMULATION_EXPORT_DYNAMIC_LIBRARY
#   define ARGUS_SIMULATION_IMPORT_DYNAMIC_LIBRARY
#else
#	define ARGUS_SIMULATION_EXPORT_DYNAMIC_LIBRARY __declspec( dllexport )
#   define ARGUS_SIMULATION_IMPORT_DYNAMIC_LIBRARY __declspec( dllimport )
#endif


#ifdef BUILD_ARGUS_SIMULATORS
#	define ARGUS_SIMULATION_API ARGUS_SIMULATION_EXPORT_DYNAMIC_LIBRARY
#else
#	define ARGUS_SIMULATION_API ARGUS_SIMULATION_IMPORT_DYNAMIC_LIBRARY
#endif

namespace simulators {

    class ARGUS_SIMULATION_API Simulator : public display::Timestep {
    protected:
        std::unique_ptr<Integrator> mIntegrator;

    public:
        Simulator(std::unique_ptr<Integrator> integrator);

        virtual void init() = 0;

        virtual void resetDrawable() = 0;

        virtual void step() = 0;

        virtual void saveScreenshot(int width, int height) = 0;

    };

}

#endif //ARGUS_DISTRIBUTION_SIMULATOR_H
