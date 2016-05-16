#include "scene.h"

#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

//----------------------------------------------------------------------------------------------------
Scene::Scene (Camera c)
{
    camera = c;
}

void Scene::setCamera (Camera c)
{
    camera = c;
}

//----------------------------------------------------------------------------------------------------
void Scene::addLight(Light l)
{
    lights.push_back(l);
}

//----------------------------------------------------------------------------------------------------
void Scene::addObject(Object *o)
{
    objects.push_back(o);
}

//----------------------------------------------------------------------------------------------------
bool Scene::hasIntersection (Ray r, Vector3 destiny)
{
    double aux;
    int i, n;
    
    // Get distance from ray origin to the destiny point
    Vector3 a = r.position - destiny;
    double b = a.getLength();
    
    n = objects.size();
    
    // For each object verify if the ray intersect it
    for (i = 0; i < n; i++)
    {
        aux = objects[i]->intersect(r);
        
        // No intersection
        if (aux < 0)
            continue;
        
        // Has intersection, and the intersection is between the origin and the destination
        if (aux < b)
            return true;
    }

    return false;
}

//----------------------------------------------------------------------------------------------------
double Scene::getIntersection (int *o, Ray r)
{
    double aux, min = -1;
    int i, n;
    
    n = objects.size();
    
    // For each object
    for (i = 0; i < n; i++)
    {
        // Verify intersection
        aux = objects[i]->intersect(r);
        
        // Tolerance (avoid self shadowing)
        if (aux > 0.0001)
        {
            if (min == -1)
            {
                min = aux;
                *o = i;
            }
            else if (aux < min)
            {
                min = aux;
                *o = i;
            }
        }
    }
    
    return min;
}

//----------------------------------------------------------------------------------------------------
Vector3 Scene::getColor (Ray r, double intensity, int depth, double tolerance)
{
    Vector3 ret;
    Vector3 color;
    Object *obj;
    Vector3 normal;
    Vector3 intersection;

    int objIndex;
    
    Vector3 diffuse, phong;
    Ray lightR;
    
    double d = getIntersection(&objIndex, r);
    
    // Ray has no intersection
    if (d <= 0.0)
        return Vector3(0.0, 0.0, 0.0);

    // Get intersection point
    intersection = r.move(d);
    
    obj = objects[objIndex];
    color = obj->getColor();
    normal = obj->getNormal(intersection);

    // Ambient color
    ret = 0.15 * color;

    // For each light
    int n = lights.size();
    for (int i=0; i<n; i++)
    {
        lightR = Ray( intersection, lights[i].position - intersection );
        
        // Verify if object is not in the shadow
        if ( !hasIntersection(lightR, lights[i].position) )
        {
            Vector3 lightColor = lights[i].getColor();
            
            // Calculate diffuse illumination
            diffuse = color * max(normal * lightR.direction, 0.0);
            diffuse = Vector3(lightColor.x * diffuse.x, lightColor.y * diffuse.y, lightColor.z * diffuse.z);
            
            // Calculate specular illumination
            Vector3 h = (lights[i].position - intersection) + (camera.position - intersection);
            h.normalize();
            phong += lightColor * pow(max(h * normal, 0.0), 128);
            
            ret += diffuse;
        }
    }

    
    Vector3 refColor;
    double reflect = obj->reflect;
    
    // Test base cases for recursion
    if ((depth > 1) && (intensity*reflect > tolerance))
    {
        Ray refRay(intersection, r.direction - 2*(r.direction * normal) * normal);

        refColor = getColor(refRay, reflect*intensity, --depth, tolerance);
    }
    
    // Sum all color and check for overflows
    ret = intensity * ( (1 - reflect) * (0.9 * ret) + reflect * refColor + phong);
    
    if (ret.x > 1)
        ret.x = 1;
    if (ret.y > 1)
        ret.y = 1;
    if (ret.z > 1)
        ret.z = 1;
    
    return ret;
}

//----------------------------------------------------------------------------------------------------
Matrix Scene::getPicture (int width, int height, int raysSquare, int depth, double tolerance)
{
    int i, j;
    Matrix m(height, 3*width);
    Vector3 c;
    double **M;
    M = new double*[height];
    for (i=0; i<height; i++)
        M[i] = new double[3*width];
    
    Ray ray;
    
    // Run for each pixel
    for (i=0; i<height; i++)
    {
        for (j=0; j<width; j++)
        {
            c = Vector3(0.0,0.0,0.0);
            
            // Verify anti-alias factor
            for (int u=0; u<raysSquare; u++)
            {
                for (int v=0; v<raysSquare; v++)
                {
                    // Generate the ray from the camera through the pixel and get the color for the pixel
                    ray = camera.generateRay(width*raysSquare, height*raysSquare, raysSquare*i + u, raysSquare*j + v);
                    c += (1.0 / (double)raysSquare / (double)raysSquare) * getColor(ray, 1.0, depth, tolerance);
                }
            }

            m.M[i][3*j]     = c.x;
            m.M[i][3*j + 1] = c.y;
            m.M[i][3*j + 2] = c.z;
        }
    }
    
    return m;
}
