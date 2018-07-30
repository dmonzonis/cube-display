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
    enum Shape {CUBE, PYRAMID, OCTAHEDRON};

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

    /**
     * @brief Resets all transformations on the currently selected shape.
     */
    void resetShape();

    /**
     * @brief Sets a new type of shape and resets all transformations.
     * @param shape The type of shape that will be used.
     */
    void setShape(Shape newShape);

    /**
     * @brief Sets the pivot point with respect to which the rotations and homothecys will
     * be computed.
     * @param xPos x coordinate of the pivot point.
     * @param yPos y coordinate of the pivot point.
     * @param zPos z coordinate of the pivot point.
     */
    void setPivot(double xPos, double yPos, double zPos);

protected:
    void paintEvent(QPaintEvent *ev);
    Shape selectedShape;

private:
    Polygon3D *shape;
    Point3D pivot;
};

#endif // RENDER_AREA_H
