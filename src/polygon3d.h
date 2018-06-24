#ifndef POLYGON3D_H
#define POLYGON3D_H

#include <array>
#include <vector>

#include <QPainter>
#include <QPoint>

#include "point3d.h"
#include "rotation3d.h"

class Polygon3D
{
private:
    // Edge contains the indices in the points vector of 2 connected points
    typedef std::array<int, 2> Edge;

public:
    Polygon3D();
    void addPoint(Point3D point);
    void addEdge(Point3D point1, Point3D point2);
    std::vector<Point3D> getPoints() const;
    void rotate(const Rotation3D &rot);
    void rotate(const Rotation3D &rot, const Point3D &pivot);
    void rotate(double xDeg, double yDeg, double zDeg);
    void rotate(double xDeg, double yDeg, double zDeg, const Point3D &pivot);
    bool contains(const Point3D &point) const;
    int find(const Point3D &point) const;
    void paintPolygon(QPainter &painter, const QPoint &offset) const;

private:
    std::vector<Point3D> points;
    std::vector<Edge> edges;
};

#endif // POLYGON3D_H
