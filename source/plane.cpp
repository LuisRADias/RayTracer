#include "plane.h"
#include <stdio.h>

Plane::Plane (  double pX, double pY, double pZ,
                double nX, double nY, double nZ) : Object(pX, pY, pZ)
{   
    normal = Vector3(nX, nY, nZ);
    normal.normalize();
}

Plane::Plane  (Vector3 p, Vector3 n) : Object(p.x, p.y, p.z)
{
    normal = n;
    normal.normalize();
}

Plane::Plane (  double pX, double pY, double pZ,
                double nX, double nY, double nZ,
                double cR, double cG, double cB,
                double k, double j)              : Object(pX, pY, pZ, cR, cG, cB, k, j)
{   
    normal = Vector3(nX, nY, nZ);
    normal.normalize();
}

Plane::Plane  ( Vector3 p, Vector3 n,
                double cR, double cG, double cB,
                double k, double j)              : Object(p.x, p.y, p.z, cR, cG, cB, k, j)
{
    normal = n;
    normal.normalize();
}

double Plane::intersect (Ray r)
{
    if (normal * r.direction > -0.0001 && normal * r.direction < 0.0001)
        return -1;
    
    double t = ((position - r.position) * normal) / (r.direction * normal);
    
    if (t < 0.0001)
        return -1;
    return t;
}

Vector3 Plane::getNormal (Vector3 p)
{
    return normal;
}

