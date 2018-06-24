#include "homothecy.h"

Homothecy::Homothecy(double ratio)
    : Matrix(3, 3)
{
    std::vector<double> values = {
        ratio, 0, 0,
        0, ratio, 0,
        0, 0, ratio
    };
    setValues(values);
}

Homothecy::Homothecy(double ratio, const Point3D &center)
    : Matrix(3, 3)
{
    // TODO: Define matrix
}
