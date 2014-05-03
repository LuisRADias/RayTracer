#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"
#include "ray.h"

class Camera
{
    private:
        double tg;
        
    public:
        Vector3 position;
        Vector3 direction;
        Vector3 up;
        Vector3 right;
        double fov;
        
        
        /*
        Parameters:
            p -> Camera position
            d -> Camera direction
            u -> Camera up vector
            angle -> Field of view of the camer
        Return:
            Create an object "Camera"
        */
        Camera (double pX = 0.0, double pY = 0.0, double pZ = 0.0,
                double dX = 0.0, double dY = 0.0, double dZ = 0.0,
                double uX = 0.0, double uY = 0.0, double uZ = 0.0,
                double angle = 0.0);
                
        Camera (Vector3 p, Vector3 d, Vector3 u, double angle);
        
        /*
        Parameters:
            w -> Width of the image
            h -> Height of the image
            i -> Row number (down->top)
            j -> Collumn number (left->right)
        Return:
            Ray -> Ray from the camera to the given pixel
        */
        Ray generateRay (double w, double h, double i, double j);
        

        
        Camera & operator = (const Camera & c)
        {
            if(this != & c)
            {
                position  = c.position;
                direction = c.direction;
                up        = c.up;
                right     = c.right;
                
                fov       = c.fov;
                tg        = tan(c.fov);
            }
            return *this;
        }
};

#endif

