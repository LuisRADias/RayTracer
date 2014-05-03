#ifndef PLANE_H
#define PLANE_H

#include "object.h"
#include "vector.h"

class Plane : public Object
{        
    public:
        Vector3 normal;
        
        /*
        Parameters:
            p -> A point in the plane
            n -> Normal vector of the plane
            c -> Object color
            k -> Reflective coefficient
            j -> Refracton coefficient
        Return:
            Create an object "Plane"
        */
        Plane  (double pX = 0.0, double pY = 0.0, double pZ = 0.0,
                double nX = 0.0, double nY = 0.0, double nZ = 0.0);
                
        Plane  (Vector3 p, Vector3 n);
        
        Plane  (double pX, double pY, double pZ,
                double nX, double nY, double nZ,
                double cR, double cG, double cB,
                double k, double j);
                
        Plane  (Vector3 p, Vector3 n,
                double cR, double cG, double cB,
                double k, double j);

        /*
        Parameters:
            r -> Ray to be intersected with the plane
        Return:
            double -> the distance from the ray origin and the plane
        Especial cases:
            Return a negative value if there is no intersection
        */
        double intersect (Ray r);
        
        /*
        Parameters:
           p -> Required by the superclass, but has no function
        Return:
            Vector3 -> The normal vector of the plane
        */
        Vector3 getNormal (Vector3 p = Vector3(0,0,0));
        
        
        
        Plane & operator = (const Plane & p)
        {
            if(this != & p)
            {
                position  = p.position;
                r         = p.r;
                g         = p.g;
                b         = p.b;
                reflect   = p.reflect;
                refract   = p.refract;
                
                normal    = p.normal;
            }
            return *this;
        }
};

#endif
