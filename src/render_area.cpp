#include "render_area.h"

#include <QPainter>

#include "shapes.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent),
      pivot(Point3D(0, 0, 0))
{
    shape = new Cube();
    selectedShape = CUBE;
}

RenderArea::~RenderArea()
{
    delete shape;
}

void RenderArea::rotateShape(double xDeg, double yDeg, double zDeg)
{
    shape->rotate(xDeg, yDeg, zDeg, pivot);
}

void RenderArea::scaleShape(double ratio)
{
    // TODO: Use pivot as center when the homothecy constructor is defined
    shape->scale(ratio);
}

void RenderArea::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    const QPoint offset{this->geometry().center()};
    shape->paintPolygon(painter, offset);
}

void RenderArea::resetShape()
{
    setShape(selectedShape);
}

void RenderArea::setShape(Shape newShape)
{
    // First delete the current shape
    delete shape;
    // Now set the correct shape
    selectedShape = newShape;
    switch (newShape)
    {
    case CUBE:
        shape = new Cube();
        break;
    case PYRAMID:
        shape = new Pyramid();
        break;
    case OCTAHEDRON:
        shape = new Octahedron();
        break;
    }
}

void RenderArea::setPivot(double xPos, double yPos, double zPos)
{
    pivot = Point3D(xPos, yPos, zPos);
}
