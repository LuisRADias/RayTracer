#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "vector.h"
#include "matrix.h"
#include "camera.h"
#include "ray.h"
#include "light.h"
#include "object.h"
#include "sphere.h"
#include "plane.h"

using namespace std;

class Scene
{
    public:
        Camera camera;
        vector<Light> lights;
        vector<Object*> objects;
        
        /*
        Parameters:
            c -> camera
        Return:
            Create an object "Scene"
        */
        Scene (Camera c = Camera(0,0,0, 0,0,-1, 0,1,0));
        
        /*
        Parameters:
            c -> New camera for the scene
        Return:
            Change the camera of the scene for the camera given as parameter
        */
        void setCamera (Camera c);
        
        /*
        Parameters:
            l -> A light
        Return:
            Add the light to the scene
        */
        void addLight(Light l);
        
        /*
        Parameters:
            *o -> Pointer to a object (Plane or Sphere)
        Return:
            Add the object to the scene
        */
        void addObject(Object *o);
        
        /*
        Parameters:
            r -> Ray
            destiny -> Point in the ray
        Return:
            bool -> Inficate if there is any object between the ray origin and the point
        Error:
            If the point is not in the ray, the function will return if there is any object
            between the ray origin and the point in the ray at the same distance from the
            ray origin than "destiny"
        */
        bool hasIntersection (Ray r, Vector3 destiny);
        
        /*
        Parameters:
            *o <- indice of the object intersected by the ray
            r -> A ray 
        Return:
            double -> distance from the ray origin to the object
        Error:
            If no object in the scene is intersected by the ray, o = -1 and double < 0
            
        */
        double getIntersection (int *o, Ray r);
        
        /*      Ray tracer recursion
        Parameter:
            r -> Ray to be intersected
                Used in the recursion, must start with a ray from the camera
            intensity -> Intensity of the color to be returned
                Used in the recursion, must start with 1
            depth -> Depth of the recursion
            tolerance -> Tolerance of the recursion (minimum acceptable intensity)
        Return:
            Vector3 -> RGB color
        */
        Vector3 getColor (Ray r, double intensity, int depth, double tolerance);
        
        /*      Ray tracer base
        Parameter:
            width -> Image width
            height -> Image height
            raysSquare -> Antialias factor (raysSquare² rays per pixel)
            depth -> Depth of the ray tracer recursion
            tolerance -> Ray tracer tolerance of the recursion (minimum acceptable intensity)
        Return:
            Matrix -> Image colors Matrix[height][width * 3(RGB)]
        */
        Matrix getPicture (int width, int height, int raysSquare, int depth, double tolerance);
};

#endif
