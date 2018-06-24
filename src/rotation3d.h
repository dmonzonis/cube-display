#ifndef ROTATION3D_H
#define ROTATION3D_H

#include "matrix.h"

// Forward-declarations
class Point3D;

/**
 * @brief Represents a 3D rotation matrix.
 */
class Rotation3D : public Matrix
{
public:
    enum Axis { X_AXIS, Y_AXIS, Z_AXIS };

public:
    /**
     * @brief Constructs a rotation matrix on an axis.
     * @param angle Angle of the rotation matrix, in degrees.
     * @param axis Axis on which to rotate.
     */
    Rotation3D(double angle, Axis axis);

    /**
     * @brief Constructs a rotation matrix on an arbitrary axis given by
     * the point.
     * @param angle Angle of the rotation matrix, in degrees.
     * @param point Point different from the origin which has the direction of the
     * axis to rotate from.
     */
    Rotation3D(double angle, const Point3D &point);
};

#endif // ROTATION3D_H
