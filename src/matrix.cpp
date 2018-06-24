#include "matrix.h"

#include <stdexcept>

Matrix::Matrix(unsigned rows, unsigned columns)
    : rows(rows),
      columns(columns),
      data(rows * columns, 0.0)
{}

Matrix::Matrix(int rows, std::vector<double> values)
    : rows(rows)
{
    // Check that we have the right amount of values in the data
    if (values.size() % rows != 0)
    {
        throw std::runtime_error("Size of data doesn't correspond to the matrix dimensions.");
    }

    columns = values.size() / rows;
    data = values;
}

Matrix::Matrix(const Matrix &m)
    : rows(m.getRows()),
      columns(m.getColumns())
{
    std::vector<double> newData;

    // Reconstruct data from the matrix
    for (unsigned i = 0; i < getRows(); ++i)
    {
        for (unsigned j = 0; j < getColumns(); ++j)
        {
            newData.push_back(m.get(i, j));
        }
    }

    // Use the reconstructed data as this matrix's data
    data = newData;
}

bool Matrix::isSquare() const
{
    return rows == columns;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    // Check that matrices are dimensionally right for multiplication
    if (m1.getColumns() != m2.getRows())
    {
        throw std::runtime_error("Dimensions of matrices don't match for multiplication.");
    }
    // If A is nxm and B is mxp, then AxB is nxp
    Matrix result(m1.getRows(), m2.getColumns());

    // Compute elements of the product matrix
    for (unsigned i = 0; i < result.getRows(); ++i)
    {
        for (unsigned j = 0; j < result.getColumns(); ++j)
        {
            double element = 0.0;
            for (unsigned k = 0; k < m1.getColumns(); ++k)
            {
                element += m1.get(i, k) * m2.get(k, j);
            }
            result.set(i, j, element);
        }
    }

    return result;
}

Matrix operator*(const double &k, const Matrix &m)
{
    Matrix result(m);
    // Multiply every element for the scalar
    for (unsigned i = 0; i < result.getRows(); ++i)
    {
        for (unsigned j = 0; j < result.getColumns(); ++j)
        {
            result.set(i, j, result.get(i, j) * k);
        }
    }

    return result;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    if (m1.getRows() != m2.getRows()
            || m1.getColumns() != m2.getColumns())
    {
        throw std::runtime_error("Dimensions of matrices need to match for addition.");
    }

    Matrix result(m1.getRows(), m1.getColumns());
    for (unsigned i = 0; i < result.getRows(); ++i)
    {
        for (unsigned j = 0; j < result.getColumns(); ++j)
        {
            result.set(i, j, m1.get(i, j) + m2.get(i, j));
        }
    }

    return result;
}

Matrix operator-(const Matrix &m1, const Matrix &m2)
{
    return m1 + (-1 * m2);
}

unsigned Matrix::getRows() const
{
    return rows;
}

unsigned Matrix::getColumns() const
{
    return columns;
}

double Matrix::get(unsigned row, unsigned column) const
{
    return data[row * columns + column];
}

void Matrix::set(unsigned row, unsigned column, double value)
{
    data[row * columns + column] = value;
}

void Matrix::setValues(std::vector<double> values)
{
    if (values.size() != data.size())
    {
        throw std::runtime_error("Number of elements don't match.");
    }
    data = values;
}
