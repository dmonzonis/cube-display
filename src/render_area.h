#ifndef RENDER_AREA_H
#define RENDER_AREA_H

#include <vector>

#include <QWidget>

#include "polygon3d.h"

/**
 * @brief Widget which contains a 3D shape (polygon) and draws its projection on the screen
 * when updated.
 */
class RenderArea : public QWidget
{
public:
    /**
     * @brief Constructor.
     * @param parent Parent widget.
     */
    RenderArea(QWidget *parent = nullptr);

    /**
     * @brief Default destructor.
     */
    virtual ~RenderArea();

    /**
     * @brief Rotates the shape by the given angles along each axis.
     * @param xDeg Degrees to rotate the shape along the X axis.
     * @param yDeg Degrees to rotate the shape along the Y axis.
     * @param zDeg Degrees to rotate the shape along the Z axis.
     */
    void rotateShape(double xDeg, double yDeg, double zDeg);

    /**
     * @brief Scale the shape by a given ratio from the origin.
     * @param ratio Ratio to scale the shape from the origin.
     */
    void scaleShape(double ratio);

protected:
    void paintEvent(QPaintEvent *ev);

private:
    Polygon3D polygon;
};

#endif // RENDER_AREA_H
