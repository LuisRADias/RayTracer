#include "sphere.h"
#include <stdio.h>

Sphere::Sphere (double pX, double pY, double pZ, double r) : Object(pX, pY, pZ)
{   
    radius = r;
}

Sphere::Sphere (double pX, double pY, double pZ,
                double r,
                double cR, double cG, double cB,
                double k, double j)                 : Object (pX, pY, pZ, cR, cG, cB, k, j)
{
    radius = r;
}

double Sphere::intersect (Ray r)
{
    double a, b, c, delta, r1, r2;
    Vector3 aux;

    a = r.direction * r.direction;
    b = 2 * (r.position - position) * r.direction;
    c = ((r.position - position) * (r.position - position)) - (radius * radius);
    delta = b*b - 4 * a * c;
    if (delta < 0)
        return -1;
        
    r1 = (-b + sqrt(delta)) / (2 * a);
    r2 = (-b - sqrt(delta)) / (2 * a);
    
    if (r1 < 0.001 && r2 < 0.001)
        return -1;
    else if (r1 < 0.001)
        r1 = r2;
    else if (r2 < 0.001)
        r1 = r1;
    else
        r1 = r1 < r2 ? r1 : r2;

    return r1;

}

Vector3 Sphere::getNormal (Vector3 p)
{
    Vector3 n = p - position;
    n.normalize();
    return n;
}
