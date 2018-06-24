#include "polygon3d.h"

#include <algorithm>

Polygon3D::Polygon3D()
{
}

void Polygon3D::addPoint(Point3D point)
{
    // Do not accept repeated points
    if (contains(point))
    {
        return;
    }
    points.push_back(point);
}

void Polygon3D::addEdge(Point3D point1, Point3D point2)
{
    // If some of the points are not part of the polygon, add them
    addPoint(point1);
    addPoint(point2);
    // Add the edge
    Edge edge = {find(point1), find(point2)};
    edges.push_back(edge);
}

std::vector<Point3D> Polygon3D::getPoints() const
{
    std::vector<Point3D> copy{points.begin(), points.end()};
    return copy;
}

void Polygon3D::rotate(const Rotation3D &rot)
{
    for (auto& point : points)
    {
        point.rotate(rot);
    }
}

void Polygon3D::rotate(const Rotation3D &rot, const Point3D &pivot)
{
    for (auto& point : points)
    {
        point.rotate(rot, pivot);
    }
}

void Polygon3D::rotate(double xDeg, double yDeg, double zDeg)
{
    rotate(Rotation3D(xDeg, Rotation3D::X_AXIS));
    rotate(Rotation3D(yDeg, Rotation3D::Y_AXIS));
    rotate(Rotation3D(zDeg, Rotation3D::Z_AXIS));
}

void Polygon3D::rotate(double xDeg, double yDeg, double zDeg, const Point3D &pivot)
{
    rotate(Rotation3D(xDeg, Rotation3D::X_AXIS), pivot);
    rotate(Rotation3D(yDeg, Rotation3D::Y_AXIS), pivot);
    rotate(Rotation3D(zDeg, Rotation3D::Z_AXIS), pivot);
}

bool Polygon3D::contains(const Point3D &point) const
{
    return std::find(points.begin(), points.end(), point) != points.end();
}

int Polygon3D::find(const Point3D &point) const
{
    for (int i = 0; i < points.size(); ++i)
    {
        if (points.at(i) == point)
        {
            return i;
        }
    }
    return -1;
}

void Polygon3D::paintPolygon(QPainter &painter, const QPoint &offset) const
{
    for (Edge edge : edges)
    {
        // Project the pair of points and draw the line on the projected plane
        // TODO: Change hardcoded plane into configurable camera view
        // For now, project onto plane x+y+z=0
        QPoint point1 = points.at(edge.at(0)).getPixelCoordinates(1, 1, 1) + offset;
        QPoint point2 = points.at(edge.at(1)).getPixelCoordinates(1, 1, 1) + offset;

        // Draw the line
        painter.drawLine(point1, point2);
    }
}

