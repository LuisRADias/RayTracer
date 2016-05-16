#include "ray.h"

Ray::Ray (double pX, double pY, double pZ,
          double dX, double dY, double dZ)
{
    position  = Vector3 (pX, pY, pZ);
    direction = Vector3 (dX, dY, dZ);
    direction.normalize();
}

Ray::Ray (Vector3 p, Vector3 d)
{
    position = p;
    direction = d;
    direction.normalize();
}

Vector3 Ray::move (double d)
{
    return (position + d*direction);
}

double Ray::distance (Vector3 p)
{
    Vector3 aux;
    aux = position - p;
    
    return aux.getLength();
}
