#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray
{
    public:
        Vector3 position;
        Vector3 direction;
        
        /*
        Parameters:
            p -> Ray origin
            d -> Direction of the ray
        Return:
            Create an object "Ray"
        */
        Ray (double pX = 0, double pY = 0, double pZ = 0,
             double dX = 0, double dY = 0, double dZ = 0);
             
        Ray (Vector3 p, Vector3 d);
        
        /*
        Parameters:
            d -> Distance from the origin
        Return:
            Vector3 -> The point in the ray with distance d from the origin
        */
        Vector3 move (double d);
        
        /*
        Parameters:
            p -> Point in space
        Return:
            double -> The distance from the ray origin to the point
        */
        double distance (Vector3 p);
        
        
        
        Ray & operator = (const Ray & r)
        {
            if(this != & r)
            {
                position  = r.position;
                direction = r.direction;
            }
            return *this;
        }
};

#endif

