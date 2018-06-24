#ifndef POINT3D_H
#define POINT3D_H

#include "rotation3d.h"

#include <QPoint>

/**
 * @brief Represents a single point in 3D space as a column matrix.
 */
class Point3D : public Matrix
{
public:
    /**
     * @brief Construct a 3D point with coordinates (x, y, z).
     */
    Point3D(double x, double y, double z);

    /**
     * @brief Construct a point from a 3x1 matrix.
     */
    Point3D(const Matrix &m);

    /**
     * @brief Compute the dot product between the vectors pointing to two points.
     */
    double dot(const Point3D &other) const;

    /**
     * @brief Compute the norm of the vector pointing to the point from the origin.
     */
    double norm() const;

    /**
     * @brief Makes the distance of the point to the origin 1, maintaining the direction.
     *
     * The vector pointing to the point from the origin is shrunk into a unit vector.
     */
    Point3D normalize();

    /**
     * @brief Return the x coordinate of the point.
     */
    double x() const;

    /**
     * @brief Return the y coordinate of the point.
     */
    double y() const;

    /**
     * @brief Return the z coordinate of the point.
     */
    double z() const;

    /**
     * @brief Compute the distance between this point and another point in 3D space.
     * @param point Point to which the distance is calculated.
     * @return A scalar representing the distance.
     */
    double distanceTo(const Point3D &point) const;

    /**
     * @brief Perform a rotation of the point using the origin as pivot.
     * @param rot Rotation matrix.
     */
    void rotate(const Rotation3D &rot);

    /**
     * @brief Perform a rotation of the point using a given pivot.
     * @param rot Rotation matrix.
     * @param pivot Pivot point for the rotation.
     */
    void rotate(const Rotation3D &rot, const Point3D &pivot);

    /**
     * @brief Scales the point by a given ratio from the origin.
     * @param ratio Determines the scale amount, e.g, a ratio of 2 means the point will
     * be twice as far from the center.
     */
    void scale(double ratio);

    /**
     * @brief Scales the point by a given ratio from the given center.
     * @param ratio Determines the scale amount, e.g, a ratio of 2 means the point will
     * be twice as far from the center.
     * @param center Point from which to scale the point.
     */
    void scale(double ratio, const Point3D &center);

    /**
     * @brief Project the point onto the plane ax+by+cz=0.
     *
     * @return The 3D coordinates of the projected point, which is contained in the plane.
     */
    Point3D project(double a, double b, double c) const;

    /**
     * @brief Projects the point onto the plane ax+by+cz=0 and changes the basis to
     * a one suitable for pixel positioning on the screen.
     *
     * Once we have it on the plane, we define a new set of coordinates (x, y)
     * different from the 3D ones in the plane, using the new bound and defining
     * as origin the origin in the plane (since it is contained in it).
     * Then a QPoint object is created in the new coordinate system, with the
     * values truncated to integers since QPoint only has integer precision.
     *
     * @return A QPoint representing the pixel coordinates of the point to be drawn.
     */
    QPoint getPixelCoordinates(double a, double b, double c) const;

    friend bool operator==(const Point3D &point1, const Point3D &point2);
};

#endif // POINT3D_H
