CC=g++
CFLAGS=-c -Wall

all: main clean

main: main.o camera.o light.o matrix.o object.o plane.o ray.o scene.o sphere.o vector.o
	$(CC) -Wall main.o camera.o light.o matrix.o object.o plane.o ray.o scene.o sphere.o vector.o -o RayTracer

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

camera.o: camera.cpp
	$(CC) $(CFLAGS) camera.cpp

light.o: light.cpp
	$(CC) $(CFLAGS) light.cpp

matrix.o: matrix.cpp
	$(CC) $(CFLAGS) matrix.cpp

object.o: object.cpp
	$(CC) $(CFLAGS) object.cpp

plane.o: plane.cpp plane.h
	$(CC) $(CFLAGS) plane.cpp

ray.o: ray.cpp
	$(CC) $(CFLAGS) ray.cpp

scene.o: scene.cpp
	$(CC) $(CFLAGS) scene.cpp

sphere.o: sphere.cpp
	$(CC) $(CFLAGS) sphere.cpp

vector.o: vector.cpp
	$(CC) $(CFLAGS) vector.cpp

clean:
	rm -rf *.o