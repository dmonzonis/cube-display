#ifndef HOMOTHECY_H
#define HOMOTHECY_H

#include "point3d.h"

/**
 * @brief Represents a homothetic transformation in 3D space, defined by the matrix
 * corresponding to its affinity.
 */
class Homothecy : public Matrix
{
public:
    /**
     * @brief Constructs a homothecy with the origin as its center and a given ratio.
     * @param ratio Ratio for the homothecy, which determines how much each point will
     * be scaled with respect to the center.
     */
    Homothecy(double ratio);

    /**
     * @brief Constructs a homothecy with a given center and ratio.
     * @param ratio Ratio for the homothecy, which determines how much each point will
     * be scaled with respect to the center.
     * @param center Center point of the homothecy.
     */
    Homothecy(double ratio, const Point3D &center);
};

#endif // HOMOTHECY_H
