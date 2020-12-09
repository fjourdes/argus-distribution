//
// Created by lijie on 9/6/18.
//

#ifndef ARGUS_DISTRIBUTION_APPLICATION_H
#define ARGUS_DISTRIBUTION_APPLICATION_H

#include <simulators/simulator.h>
#include <display/interface.h>

#ifndef WIN32
#	define ARGUS_APPLICATION_EXPORT_DYNAMIC_LIBRARY
#   define ARGUS_APPLICATION_IMPORT_DYNAMIC_LIBRARY
#else
#	define ARGUS_APPLICATION_EXPORT_DYNAMIC_LIBRARY __declspec( dllexport )
#   define ARGUS_APPLICATION_IMPORT_DYNAMIC_LIBRARY __declspec( dllimport )
#endif


#ifdef BUILD_ARGUS_APPLICATIONS
#	define ARGUS_APPLICATION_API ARGUS_APPLICATION_EXPORT_DYNAMIC_LIBRARY
#else
#	define ARGUS_APPLICATION_API ARGUS_APPLICATION_IMPORT_DYNAMIC_LIBRARY
#endif

namespace applications {

    class ARGUS_APPLICATION_API Application {
    protected:
    public:
//    Application(int argc, char const *argv[]) {
////        mSimulator = std::make_shared<Simulator>(std::make_unique<Integrator>(), "meshes/sphere.obj");
//    }
        virtual void init() = 0;

    };

}

#endif //ARGUS_DISTRIBUTION_APPLICATION_H
