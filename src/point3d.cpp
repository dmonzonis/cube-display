#include "point3d.h"

#include <math.h>
#include <stdexcept>

#include "homothecy.h"

Point3D::Point3D(double x, double y, double z)
    : Matrix(3, 1)
{
    setValues({x, y, z});
}

Point3D::Point3D(const Matrix &m)
    : Matrix(3, 1)
{
    if (m.getRows() != 3 || m.getColumns() != 1)
    {
        throw std::runtime_error("Can only initialize point from a 1x3 matrix.");
    }
    // Initialize data
    for (int i = 0; i < 3; ++i)
    {
        set(i, 0, m.get(i, 0));
    }
}

double Point3D::dot(const Point3D &other) const
{
    double result = 0;
    for (int i = 0; i < 3; ++i)
    {
        result += this->get(i, 0) * other.get(i, 0);
    }
    return result;
}

double Point3D::norm() const
{
    return std::sqrt(this->dot(*this));
}

Point3D Point3D::normalize()
{
    double dist = norm();
    // Divide each component by the norm
    for (int i = 0; i < 3; ++i)
    {
        set(i, 0, get(i, 0) / dist);
    }
    return *this;
}

double Point3D::x() const
{
    return get(0, 0);
}

double Point3D::y() const
{
    return get(1, 0);
}

double Point3D::z() const
{
    return get(2, 0);
}

double Point3D::distanceTo(const Point3D &point) const
{
    Point3D separation(*this - point);
    return separation.norm();
}

void Point3D::rotate(const Rotation3D &rot)
{
    // Obtain rotated coordinates
    Matrix rotated = rot * (*this);
    // Modify this point to the new coordinates
    for (int i = 0; i < 3; ++i)
    {
        set(i, 0, rotated.get(i, 0));
    }
}

void Point3D::rotate(const Rotation3D &rot, const Point3D &pivot)
{
    Point3D offset(*this - pivot);
    offset.rotate(rot);
    Point3D rotated(offset + pivot);
    // Modify this point to the new coordinates
    for (int i = 0; i < 3; ++i)
    {
        set(i, 0, rotated.get(i, 0));
    }
}

void Point3D::scale(double ratio)
{
    Homothecy homothety(ratio);
    Matrix scaled = homothety * (*this);
    for (int i = 0; i < 3; ++i)
    {
        set(i, 0, scaled.get(i, 0));
    }
}

void Point3D::scale(double ratio, const Point3D &center)
{
    // TODO: Implement
}

Point3D Point3D::project(double a, double b, double c) const
{
    // Get the unit vector representing the plane normal
    Point3D normal = Point3D(a, b, c).normalize();

    /*
     * If p is the point we want to project, q is a point in the plane, and n is the normal,
     * the projection is obtained as p - [(p - q)·n]n
     */
    Point3D projection(*this - (this->dot(normal)) * normal);
    return projection;
}

QPoint Point3D::getPixelCoordinates(double a, double b, double c) const
{
    Point3D projection = this->project(a, b, c);
    /*
     * projection is the projected point on the plane, but it's still in 3D coordinates.
     * Now we need to transform the 3D coordinates into 2D pixel coordinates.
     * For that, we need to choose an orthonormal basis in the plane.
     * The basis chosen is such that the positive y direction is given by the projection
     * of the point (0, 0, -1) normalized, and the positive x direction is obtained by
     * rotating counterclockwise the y direction 90 degrees.
     * Let's call these coordinates (u, v), that is, in pixel coordinates, the point is
     * represented as u*i + v*j
     */
    // FIXME: What happens when the camera plane is z=d ?
    Point3D j = Point3D(0, 0, -1).project(a, b, c);
    Point3D i = Point3D(Rotation3D(90, Point3D(a, b, c)) * j);

    /*
     * We need to project the point on the plane onto the axes defined by the basis i,j.
     * The distance from the origin to each of these projections will be the corresponding
     * coordinates u,v.
     */
    Point3D uVector = Point3D((projection.dot(i) / i.dot(i)) * i);
    Point3D vVector = Point3D((projection.dot(j) / j.dot(j)) * j);
    int uSign = uVector.dot(i) > 0 ? 1 : -1;
    int vSign = vVector.dot(j) > 0 ? 1 : -1;
    double u = std::round(uVector.norm() * uSign);
    double v = std::round(vVector.norm() * vSign);

    // Now we can finally create the QPoint, but first we truncate to int
    return QPoint((int)u, (int)v);
}

bool operator==(const Point3D &point1, const Point3D &point2)
{
    return (point1.x() == point2.x())
            && (point1.y() == point2.y())
            && (point1.z() == point2.z());
}
