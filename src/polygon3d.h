#ifndef POLYGON3D_H
#define POLYGON3D_H

#include <array>
#include <vector>

#include <QPainter>
#include <QPoint>

#include "point3d.h"
#include "rotation3d.h"

/**
 * @brief Represents a 3D polygon, defined by a set of points and edges connecting them.
 */
class Polygon3D
{
private:
    // Edge contains the indices in the points vector of 2 connected points
    typedef std::array<int, 2> Edge;

public:
    /**
     * @brief Default constructor. Creates a polygon without any points.
     */
    Polygon3D();

    /**
     * @brief Adds a point to the polygon, if it's not already in it.
     * @param point Point to be added to the polygon's list of points.
     */
    void addPoint(Point3D point);

    /**
     * @brief Adds an edge by adding the two given points, if they're not already
     * in the polygon, and connecting them.
     */
    void addEdge(Point3D point1, Point3D point2);

    /**
     * @brief Returns a list of the points that form the polygon, in no specific order.
     *
     * The list returned is a deep copy of the polygon's internal list, so any
     * modifications done to the points in the returned list will not affect the
     * polygon.
     */
    std::vector<Point3D> getPoints() const;

    /**
     * @brief Rotates all the points in the polygon using the given rotation matrix, and
     * using the origin as pivot.
     * @param rot Rotation matrix to use for the rotation of all points.
     */
    void rotate(const Rotation3D &rot);

    /**
     * @brief Rotates all the points in the polygon using the given rotation matrix, and
     * using the given pivot.
     * @param rot Rotation matrix to use for the rotation of all points.
     * @param pivot Pivot for the rotation.
     */
    void rotate(const Rotation3D &rot, const Point3D &pivot);

    /**
     * @brief Rotates all the points in the polygon using the given degrees for rotations
     * along each of the axes (X, Y and Z), using the origin as pivot.
     * @param xDeg Degrees to rotate along the X axis.
     * @param yDeg Degrees to rotate along the Y axis.
     * @param zDeg Degrees to rotate along the Z axis.
     */
    void rotate(double xDeg, double yDeg, double zDeg);

    /**
     * @brief Rotates all the points in the polygon using the given degrees for rotations
     * along each of the axes (X, Y and Z), using the given pivot.
     * @param xDeg Degrees to rotate along the X axis.
     * @param yDeg Degrees to rotate along the Y axis.
     * @param zDeg Degrees to rotate along the Z axis.
     * @param pivot Pivot for the rotation.
     */
    void rotate(double xDeg, double yDeg, double zDeg, const Point3D &pivot);

    /**
     * @brief Scales all the points in the polygon by a given ratio.
     */
    void scale(double ratio);

    /**
     * @brief Returns whether or not a given point is part of the polygon.
     * @param point Point to look up in the polygon.
     * @return A boolean that indicates whether the point is in the polygon or not.
     */
    bool contains(const Point3D &point) const;

    /**
     * @brief Projects the polygon onto a view plane and paints it on the screen.
     * @param painter Previously initialized QPainter object which will paint the points
     * and lines.
     * @param offset Position of the origin in the widget, so that the point's origin
     * coincides with the widget's origin.
     */
    void paintPolygon(QPainter &painter, const QPoint &offset) const;

private:
    /**
     * @brief Finds the given point in the polygon and returns its index in the polygon list.
     * @param point Point to look up in the polygon.
     * @return The index of the point in the polygon list, or -1 if it was not found.
     */
    int find(const Point3D &point) const;

private:
    std::vector<Point3D> points;
    std::vector<Edge> edges;
};

#endif // POLYGON3D_H
