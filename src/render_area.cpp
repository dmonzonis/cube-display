#include "render_area.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    /*
     * Create centered cube
     */
    // Front edges
    polygon.addEdge(Point3D(100, -100, -100), Point3D(100, 100, -100));
    polygon.addEdge(Point3D(100, -100, 100), Point3D(100, 100, 100));
    polygon.addEdge(Point3D(100, -100, -100), Point3D(100, -100, 100));
    polygon.addEdge(Point3D(100, 100, -100), Point3D(100, 100, 100));
    // Back edges
    polygon.addEdge(Point3D(-100, -100, -100), Point3D(-100, 100, -100));
    polygon.addEdge(Point3D(-100, -100, 100), Point3D(-100, 100, 100));
    polygon.addEdge(Point3D(-100, -100, -100), Point3D(-100, -100, 100));
    polygon.addEdge(Point3D(-100, 100, -100), Point3D(-100, 100, 100));
    // Lateral edges
    polygon.addEdge(Point3D(100, -100, -100), Point3D(-100, -100, -100));
    polygon.addEdge(Point3D(100, 100, -100), Point3D(-100, 100, -100));
    polygon.addEdge(Point3D(100, -100, 100), Point3D(-100, -100, 100));
    polygon.addEdge(Point3D(100, 100, 100), Point3D(-100, 100, 100));
}

RenderArea::~RenderArea()
{
}

void RenderArea::rotateShape(double xDeg, double yDeg, double zDeg)
{
    polygon.rotate(xDeg, yDeg, zDeg);
}

void RenderArea::scaleShape(double ratio)
{
    polygon.scale(ratio);
}

void RenderArea::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    const QPoint offset{this->geometry().center()};
    polygon.paintPolygon(painter, offset);
}
