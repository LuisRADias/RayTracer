#include "light.h"

Light::Light (double pX, double pY, double pZ,
              double cR, double cG, double cB)
{
    position = Vector3 (pX, pY, pZ);
    r = cR;
    g = cG;
    b = cB;
}

Light::Light (Vector3 p,
              double cR, double cG, double cB)
{
    position = p;
    r = cR;
    g = cG;
    b = cB;
}

Vector3 Light::getColor()
{
    return Vector3(r, g, b);
}
