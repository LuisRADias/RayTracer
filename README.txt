========================================== RAY TRACER ==========================================

========================================= DEVELOPED BY =========================================

University of Victoria
Luís Ricardo Araujo Dias
V00816055

Assignment 4 - Ray tracer

========================================== COMPILING ===========================================

Compile all .cpp files together using the g++ compiler.

1. Linux / Mac OS
    - Open the terminal
    - Access the project folder
    - Run the command "make -f makefile"
    - The executable "RayTracer" will be created
    
2. Windows
    2.1. GnuWin
        - Same steps then Linux / Mac OS
    2.2. Dev-Cpp
        - Open the project with the Dev-Cpp IDE and compile the project
        - The executable "RayTracer.exe" will be created

Notes:
    - Other compilers can be used, provided that all .cpp files are compiled together. However,
    no other compiler was tested, so there is no guarantee that they will work properly.


=========================================== RUNNING ============================================

The easiest way to run the program is from the terminal with the command:
    "./[ProgramName] < [InputFile]" on linux and mac (If the makefile provided was used, the
    ProgramName will be RayTracer).
    "[ProgramName] < [InputFile]" on windows.

The input file can be created following the rules explained. Moreover three input files are
provided with the project: scn1, sn2 and scn3 (They are in the img directory).

E.g.:
    ./RayTracer < scn1 (For project compiled on Linux or Mac using the given makefile)
    RayTracer.exe < scn2 (For project compiled on Windows using Dev-Cpp)

======================================== INPUT FORMAT =========================================

The input must be given as a formatted input, as the following.

The first line contain a integer lightNum indicating the number of lights in the scene
    The following linghtNum lines contain 6 float point numberm each, indicating, in order, the
    light position (X, Y, Z) and the color (cR, cG, cB)
    
The next line contain a integer planeNum indicating the number of planes in the scene
    The next planeNum lines contain 11 float point number, indicating, in order, a point in the
    plane (X, Y, Z), the plane normal (nX, nY, nZ), the plane color (cR, cG, cB), the
    reflection coefficient (kr) and the refraction coefficient (kt)

The next line contain a integer sphereNum indicating the number of spheres in the scene
    The next sphereNum lines contain 9 float point number each, indicating, in order, the
    center of the sphere (X, Y, Z), radius (r), the sphere color (cR, cG, cB), the reflection
    coefficient (kr) and the refraction coefficient (kt)

The next line contain a integer imgNum indicating the number of images to be taken drawn
    Each image is identified in two lines:
        The first contain 4 integers and a float point, indicating, in order, the width of the
        image (w), the height or the image(h), the number of rays per pixel (a), the recursion
        depth (d) and the tolerance of the recursion (t)
        The second contains 9 float points, indicating, in order, the camera position (X, Y, Z),
        the direction of the camera (dX, dY, dZ) and the up vector (uX, uY, uZ)

Restrictions:
    0 <= cR, cG, CB <= 1
    r > 0
    0 <= kr, kt <= 1 AND kr + kt <= 1
    
Obs:
    The depth of the recursion indicate the max of times a ray can be reflected
    The tolerance of the recursion indicate the minimum intensity for with colors will be calculated
    
    
======================================= GRADING CRITERIA =======================================

Following are the classes and methods where the criteria is implemented. For more information
about the methods, read the comments before the method on the header file or the comments
within the code on the corresponding .cpp file.

1 pt for code comments & README.txt file
    There is a comment after each method in the header files explaining it
    Most of the most complex functions also have code explaining the parts of the code
    You are reading the README.txt file. ^^

2 pt for writing an image to disc
    main
        The function "void print (char, int, int)" saves the image to disk

2 pt for generating the rays through each pixel and intersecting with a plane as floor
    Camera
        "Ray generateRay (double, double, double, double)" generates the ray for a pixel
    Plane
        "double intersect (Ray)" tests the intersection of a ray and a plane

4 pt for intersecting rays with a sphere
    Sphere
        "double intersect (Ray)" tests the intersection of a ray and a sphere

2 pt for calculating the diffuse and specular color
    Scene
        In "Vector3 getColor (Ray, double, int, double)" the colors for the pixel are
            calculated using both kind of color

1 pt for calculating if a surface point is in the shadow or not
    Scene
        In "Vector3 getColor (Ray, double, int, double)" the diffuse and specular color are
            only calculated if there is no intersection between the point and the light source

2 pt for calculating reflections with arbitrary recursion depth
    Scene
        In "void getPicture (Matrix*, int, int, int, int, double)" one of the parameter of the
            function is the depth of the recursion
        "Vector3 getColor (Ray, double, int, double)" is a recursive function that have as one
            of the base cases the depth of the recursion

1 pt for shooting an arbitrary number of rays per pixel (sampling)
    Scene
        In "void getPicture (Matrix*, int, int, int, int, double)" one of the parameters is
            the number of rays per square, but the number of rays per pixel is always a square
            value

3 pt for combining Phong illumination with shadowing and reflections
    Object
        The class have color and reflection coeficient as attributes 
    Scene
        Everything is implemented in "Vector3 getColor (Ray, double, int, double)"

Bonus points:

0.5 pt for adaptive super sampling
    Not implemented

0.5 pt for adding refractions
    Not implemented

1 pt for having boundary box for each object and ray-intersection check
    Not implemented

1 pt for multiple light sources with soft shadows
    Scene
        The class Scene store a list of light sources to be used for illumination
        In "Vector3 getColor (Ray, double, int, double)", all lights are considered, creating
            different "shadow levels".

1 pt for using mesh models (if you are using sphere models)
    Not implemented

========================================== RESOURCES ===========================================

Writing bitmap:
    Based on the code on present on the website:
    http://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
    
Vector class (vector.h and vector.cpp):
    Copied from the code given for assignments 2 and 3
