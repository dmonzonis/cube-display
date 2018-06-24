#include "rotation3d.h"

#include <math.h>
#include <stdexcept>

#include "point3d.h"

#define PI 3.14159265

Rotation3D::Rotation3D(double angle, Axis axis)
    : Matrix(3, 3)
{
    std::vector<double> values;
    // Change degrees to radians since cos and sin take radians
    double radians = angle * PI / 180.0;
    double cos = std::cos(radians), sin = std::sin(radians);
    // Construct the appropriate matrix depending on the axis
    switch (axis)
    {
    case X_AXIS:
        values = {1, 0, 0, 0, cos, sin, 0, -sin, cos};
        break;
    case Y_AXIS:
        values = {cos, 0, -sin, 0, 1, 0, sin, 0, cos};
        break;
    case Z_AXIS:
        values = {cos, sin, 0, -sin, cos, 0, 0, 0, 1};
        break;
    }
    setValues(values);
}

Rotation3D::Rotation3D(double angle, const Point3D &point)
    : Matrix(3, 3)
{
    // Change degrees to radians since cos and sin take radians
    double radians = angle * PI / 180.0;
    double cos = std::cos(radians), sin = std::sin(radians);
    // Check that the point is not the origin
    if (point == Point3D(0, 0, 0))
    {
        throw std::runtime_error("Axis point can't be the origin.");
    }
    // Normalize the point if needed
    Point3D axis = Point3D(point).normalize();
    // Get coordinates
    double x = axis.x();
    double y = axis.y();
    double z = axis.z();
    std::vector<double> values = {
        cos + x * x * (1 - cos),
        x * y * (1 - cos) -  z * sin,
        x * z * (1 - cos) + y * sin,
        y * x * (1 - cos) + z * sin,
        cos + y * y * (1 - cos),
        y * z * (1 - cos) - x * sin,
        z * x * (1 - cos) - y * sin,
        z * y * (1 - cos) + x * sin,
        cos + z * z * (1 - cos)
    };
    setValues(values);
}
