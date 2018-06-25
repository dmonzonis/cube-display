#ifndef SHAPES_H
#define SHAPES_H

#include "polygon3d.h"

class Cube : public Polygon3D
{
public:
    Cube();
};

class Pyramid : public Polygon3D
{
public:
    Pyramid();
};

class Octahedron : public Polygon3D
{
public:
    Octahedron();
};

#endif // SHAPES_H
