#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "vector.h"

class Sphere : public Object
{
    public:
        double radius;
        
        /*
        Parameters:
            p -> The center of the sphere
            r -> Radius of the sphere
            c -> Object color
            k -> Reflective coefficient
            j -> Refracton coefficient
        Return:
            Create an object "Sphere"
        */
        Sphere (double pX = 0.0, double pY = 0.0, double pZ = 0.0, double r = 0.0);

        Sphere (double pX, double pY, double pZ,
                double r,
                double cR, double cG, double cB,
                double k, double j);

        /*
        Parameters:
            r -> Ray to be intersected with the sphere
        Return:
            double -> the distance from the ray origin and the sphere
        Especial cases:
            Return a negative value if there is no intersection
        */
        double intersect (Ray r);
        
        /*
        Parameters:
           p -> Point
        Return:
            Vector3 -> The normal vector of the sphere at the point given
        */
        Vector3 getNormal (Vector3 p);
        
        
        
        Sphere & operator = (const Sphere & s)
        {
            if(this != & s)
            {
                position  = s.position;
                r         = s.r;
                g         = s.g;
                b         = s.b;
                reflect   = s.reflect;
                refract   = s.refract;
                
                radius    = s.radius;
            }
            return *this;
        }
};

#endif
