#include "shapes.h"

Cube::Cube()
{
    /*
     * Create centered cube
     */
    // Front edges
    addEdge(Point3D(100, -100, -100), Point3D(100, 100, -100));
    addEdge(Point3D(100, -100, 100), Point3D(100, 100, 100));
    addEdge(Point3D(100, -100, -100), Point3D(100, -100, 100));
    addEdge(Point3D(100, 100, -100), Point3D(100, 100, 100));
    // Back edges
    addEdge(Point3D(-100, -100, -100), Point3D(-100, 100, -100));
    addEdge(Point3D(-100, -100, 100), Point3D(-100, 100, 100));
    addEdge(Point3D(-100, -100, -100), Point3D(-100, -100, 100));
    addEdge(Point3D(-100, 100, -100), Point3D(-100, 100, 100));
    // Lateral edges
    addEdge(Point3D(100, -100, -100), Point3D(-100, -100, -100));
    addEdge(Point3D(100, 100, -100), Point3D(-100, 100, -100));
    addEdge(Point3D(100, -100, 100), Point3D(-100, -100, 100));
    addEdge(Point3D(100, 100, 100), Point3D(-100, 100, 100));
}

Pyramid::Pyramid()
{
    // Base
    addEdge(Point3D(100, -100, -100), Point3D(100, 100, -100));
    addEdge(Point3D(-100, -100, -100), Point3D(-100, 100, -100));
    addEdge(Point3D(100, -100, -100), Point3D(-100, -100, -100));
    addEdge(Point3D(100, 100, -100), Point3D(-100, 100, -100));
    // Connect all base vertices to top
    addEdge(Point3D(100, -100, -100), Point3D(0, 0, 100));
    addEdge(Point3D(-100, -100, -100), Point3D(0, 0, 100));
    addEdge(Point3D(-100, 100, -100), Point3D(0, 0, 100));
    addEdge(Point3D(100, 100, -100), Point3D(0, 0, 100));
}
