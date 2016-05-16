#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include<sys/timeb.h>

#include "scene.h"
#include "camera.h"
#include "light.h"
#include "plane.h"
#include "sphere.h"


void print (char *fName, int width, int heigth);


unsigned char **IMG; // Variable used to store the image color

/*
Read README.txt to know about the input format
*/
int main (int argc, char** argv)
{   
    int n, w, x, y, z;
    double a,b,c, d,e,f, g,h,i, j,k;
    char fName[50];
    Plane *pln;
    Sphere *sph;
    
    Scene scn;
    
// Read and add the lights to the scene
    scanf ("%d", &n);
    for (int u=0; u<n; u++)
    {
        scanf ("%lf %lf %lf %lf %lf %lf", &a,&b,&c, &d,&e,&f);
        Light lgh(a,b,c, d,e,f);
        scn.addLight(lgh);
    }

// Read and add the planes to the scene    
    scanf ("%d", &n);
    for (int u=0; u<n; u++)
    {
        scanf ("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &a,&b,&c, &d,&e,&f, &g,&h,&i, &j,&k);
        pln = new Plane(a,b,c, d,e,f, g,h,i, j,k);
        scn.addObject(pln);
    }

// Read and add the spheres to the scene    
    scanf ("%d", &n);
    for (int u=0; u<n; u++)
    {
        scanf ("%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &a,&b,&c, &d, &e,&f,&g, &h,&i);
        sph = new Sphere (a,b,c, d, e,f,g, h,i);
        scn.addObject(sph);
    }

double t_diff;
struct timeb start, current;

// Read the cameras information and run the Ray Tracer for them
    scanf ("%d", &n);
    for (int u=0; u<n; u++)
    {
        scanf ("%d %d %d %d %lf", &x, &y, &z, &w, &j);
        scanf ("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &a,&b,&c, &d,&e,&f, &g,&h,&i);
        scanf ("%s", fName);
        Camera cam(a,b,c, d,e,f, g,h,i, 0.78);
        scn.setCamera(cam);

// Allocate space for the global variable   
        IMG = (unsigned char**) malloc (y * sizeof(unsigned char*));
        for (int p=0; p<y; p++)
            IMG[p] = (unsigned char*) malloc (3 * x * sizeof(unsigned char));

// Run the Ray Tracer and calculate the time it takes to get the image
        ftime(&start);

        Matrix m = scn.getPicture(x, y, z, w, j);
        
        ftime(&current);
        t_diff = ((double) current.time + (double) current.millitm * 0.001) - ((double) start.time + (double) start.millitm * 0.001);
        printf("Img %d created in %3.3lf s\n", u, t_diff);

// Transfer the image color found in the ray tracer to the global variable IMG   
        for (int p=0; p<y; p++)
        {
            for (int q=0; q<x; q++)
            {
                IMG[p][3*q]   = (unsigned char) (floor(255 * m.M[p][3*q]  ));
                IMG[p][3*q+1] = (unsigned char) (floor(255 * m.M[p][3*q+1]));
                IMG[p][3*q+2] = (unsigned char) (floor(255 * m.M[p][3*q+2]));
            }
        }

// Save the image to disk
        print(fName, x, y);

    }
    
    return 0;
}

/*
Function: print
    Write the image (whose colors are allocated on the global variable IMG) to disk
Parameters:
    -> fName: name for the output file
    -> width: width of the image to be writen
    -> heigth: heigth of the image to be writen
Return:
Notes:
    Depends on the global variable IMG, where IMG is a matrix os size [heigth] x [3*width (r,g,b)]
    Based on: http://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
*/
void print (char *fName, int width, int heigth)
{
    FILE *f;

    unsigned char file[14] = {
        'B','M', // magic
        0,0,0,0, // size in bytes
        0,0, // app data
        0,0, // app data
        54,0,0,0 // start of data offset
    };
    unsigned char info[40] = {
        40,0,0,0, // info hd size
        0,0,0,0, // width
        0,0,0,0, // heigth
        1,0, // number color planes
        24,0, // bits per pixel
        0,0,0,0, // compression is none
        0,0,0,0, // image bits size
        0xC3,0x03,0,0, // horz resoluition in pixel / m
        0xC3,0x03,0,0, // vert resolutions (0x03C3 = 96 dpi, 0x0B13 = 72 dpi)
        0,0,0,0, // #colors in pallete
        0,0,0,0, // #important colors
        };
    
    int padSize  = (4-width % 4) %4;   // Makes row multiple of 4
    int sizeData = (width*4 + padSize) * heigth;   // Number of bytes per row * number of rows
    int sizeAll  = sizeData + 14 + 40;
    
    file[ 2] = (unsigned char)( sizeAll    );
    file[ 3] = (unsigned char)( sizeAll>> 8);
    file[ 4] = (unsigned char)( sizeAll>>16);
    file[ 5] = (unsigned char)( sizeAll>>24);
    
    info[ 4] = (unsigned char)( width   );
    info[ 5] = (unsigned char)( width>> 8);
    info[ 6] = (unsigned char)( width>>16);
    info[ 7] = (unsigned char)( width>>24);
    
    info[ 8] = (unsigned char)( heigth    );
    info[ 9] = (unsigned char)( heigth>> 8);
    info[10] = (unsigned char)( heigth>>16);
    info[11] = (unsigned char)( heigth>>24);
    
    info[24] = (unsigned char)( sizeData    );
    info[25] = (unsigned char)( sizeData>> 8);
    info[26] = (unsigned char)( sizeData>>16);
    info[27] = (unsigned char)( sizeData>>24);
    
    strcat(fName, ".bmp");
    f = fopen(fName,"wb");
    fwrite(file,1,14,f);
    fwrite(info,1,40,f);
    
    unsigned char pad[3] = {0,0,0};
    
    for ( int y=0; y<heigth; y++ )
    {
        for ( int x=0; x<width; x++ )
        {
            unsigned char pixel[3];
            pixel[0] = IMG[y][x*3 + 2];
            pixel[1] = IMG[y][x*3 + 1];
            pixel[2] = IMG[y][x*3];

            fwrite( pixel, 1, 3, f );
        }
        fwrite( pad, 1, padSize, f );
    }
}

