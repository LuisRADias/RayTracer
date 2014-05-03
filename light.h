#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"

class Light
{
    public:
        Vector3 position;
        double b, g, r;
        
        /*
        Parameters:
            p -> Light position
            c -> light color
        Return:
            Create an object "Light"
        */
        Light (double pX = 0.0, double pY = 0.0, double pZ = 0.0,
               double cR = 1.0, double cG = 1.0, double cB = 1.0);
               
        Light (Vector3 p, double cR, double cG, double cB);
        
        /*
        Parameters:

        Return:
            Vector3 -> RGB color of the light
        */
        Vector3 getColor ();
            
            
               
        Light & operator = (const Light & l)
        {
            if(this != & l)
            {
                position  = l.position;
                r         = l.r;
                g         = l.g;
                b         = l.b;
            }
            return *this;
        }
};

#endif

