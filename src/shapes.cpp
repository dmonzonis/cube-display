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
