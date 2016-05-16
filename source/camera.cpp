#include "camera.h"

Camera::Camera (double pX, double pY, double pZ,
                double dX, double dY, double dZ,
                double uX, double uY, double uZ,
                double angle)
{
    position  = Vector3 (pX, pY, pZ);
    direction = Vector3 (dX, dY, dZ);
    up        = Vector3 (uX, uY, uZ);
    
    direction.normalize();
    
    right = Vector3::CrossProduct(direction, up);
    right.normalize();
    
    up = Vector3::CrossProduct(right, direction);
    up.normalize();
    
    fov = angle;
    tg = tan(angle);
}

Camera::Camera (Vector3 p, Vector3 d, Vector3 u, double angle)
{
    position  = p;
    direction = d;
    up        = u;
    
    direction.normalize();
    
    right = Vector3::CrossProduct(direction, up);
    right.normalize();
    
    up = Vector3::CrossProduct(right, direction);
    up.normalize();
    
    fov = angle;
    tg = tan(angle);
}

Ray Camera::generateRay (double w, double h, double i, double j)
{
    Vector3 rayDirection = direction;
    
    rayDirection += (tg * (2*j-w) / w) * w/h * right +
                    (tg * (2*i-h) / h) * up;
                    
    rayDirection.normalize();
    
    return Ray(position, rayDirection);
}

