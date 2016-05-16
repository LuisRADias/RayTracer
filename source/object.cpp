#include "object.h"

Object::Object (double pX, double pY, double pZ)
{
    position = Vector3(pX, pY, pZ);
    r = 0.0;
    g = 0.0;
    b = 0.0;
    reflect = 0.0;
    refract = 0.0;
}
    
Object::Object (double pX, double pY, double pZ,
                double cR, double cG, double cB,
                double k, double j)
{
    position = Vector3 (pX, pY, pZ);
    r = cR;
    g = cG;
    b = cB;
    reflect = k;
    refract = j;
}

Vector3 Object::getColor ()
{
    return Vector3(r, g, b);
}
