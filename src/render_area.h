#ifndef RENDER_AREA_H
#define RENDER_AREA_H

#include <vector>

#include <QWidget>

#include "polygon3d.h"

class RenderArea : public QWidget
{
public:
    RenderArea(QWidget *parent = nullptr);
    virtual ~RenderArea();
    void rotateShape(double xDeg, double yDeg, double zDeg);

protected:
    void paintEvent(QPaintEvent *ev);

private:
    Polygon3D polygon;
};

#endif // RENDER_AREA_H
