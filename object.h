#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include "ray.h"

class Object
{
    public:
        Vector3 position;
        double b, g, r;
        double reflect;
        double refract;
        
        /*
        Parameters:
            p -> Object position
            c -> Object color
            k -> Reflective coefficient
            j -> Refracton coefficient
        Return:
            As a abstract class it cannot be initiated, it is used within the subclasses
        */
        Object (double pX = 0.0, double pY = 0.0, double pZ = 0.0);
    
        Object (double pX, double pY, double pZ,
                double cR, double cG, double cB,
                double k, double j);

        /*
        Parameters:

        Return:
            Vector3 -> RGB color of the Object
        */
        Vector3 getColor ();

        /*
        Abstract methods to be implemented on the subclasses
        */
        virtual double intersect (Ray) =0;
        virtual Vector3 getNormal (Vector3) =0;
};

#endif

