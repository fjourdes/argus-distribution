//
// Created by lijie on 9/6/18.
//

#ifndef ARGUS_DISTRIBUTION_INTEGRATOR_H
#define ARGUS_DISTRIBUTION_INTEGRATOR_H

#include <collision.hpp>

#ifndef WIN32
#	define ARGUS_INTEGRATOR_EXPORT_DYNAMIC_LIBRARY
#   define ARGUS_INTEGRATOR_IMPORT_DYNAMIC_LIBRARY
#else
#	define ARGUS_INTEGRATOR_EXPORT_DYNAMIC_LIBRARY __declspec( dllexport )
#   define ARGUS_INTEGRATOR_IMPORT_DYNAMIC_LIBRARY __declspec( dllimport )
#endif


#ifdef BUILD_ARGUS_INTEGRATORS
#	define ARGUS_INTEGRATOR_API ARGUS_INTEGRATOR_EXPORT_DYNAMIC_LIBRARY
#else
#	define ARGUS_INTEGRATOR_API ARGUS_INTEGRATOR_IMPORT_DYNAMIC_LIBRARY
#endif

class ARGUS_INTEGRATOR_API Integrator {
public:
    virtual vector<pair<arcsim::Vec3, arcsim::Vec3> >  solve(const arcsim::SpMat<arcsim::Mat3x3> &A, const vector<arcsim::Vec3> &b, vector<arcsim::Vec3> &linear_v,
                                     const vector<arcsim::ArgusImpact> &argusImpacts,  arcsim::Mesh &mesh, const double dt) = 0;

    virtual vector<pair<arcsim::Vec3, arcsim::Vec3> > solve(const arcsim::SpMat<arcsim::Mat3x3> &A, const vector<arcsim::Vec3> &b, vector<arcsim::Vec3> &linear_v,
                                    const vector<arcsim::Impact> &impacts,  arcsim::Mesh &mesh, const double dt) = 0;
};

#endif //ARGUS_DISTRIBUTION_INTEGRATOR_H
