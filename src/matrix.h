#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

/**
 * @brief Represents a numerical matrix.
 */
class Matrix
{
public:

    /**
     * @brief Creates a matrix of zeroes with the given dimensions.
     * @param rows Number of rows.
     * @param columns Number of columns.
     */
    Matrix(unsigned rows, unsigned columns);

    /**
     * @brief Creates a matrix with the given values.
     * @param rows Number of rows of the matrix.
     * @param values Array of numbers to initialize the matrix.
     */
    Matrix(int rows, std::vector<double> values);

    /**
     * @brief Copy constructor.
     * @param m Matrix to copy data from.
     */
    Matrix(const Matrix &m);

    /**
     * @return true if the matrix is quare, false otherwise.
     */
    bool isSquare() const;

    /**
     * @brief Implements matrix product.
     * @param m1 Matrix multiplied by the left.
     * @param m2 Matrix multiplied by the right
     */
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);

    /**
     * @brief Implements product by a scalar.
     */
    friend Matrix operator*(const double &k, const Matrix &m);

    /**
     * @brief Implements matrix sum.
     */
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);

    /**
     * @brief Implements matrix substraction.
     */
    friend Matrix operator-(const Matrix &m1, const Matrix &m2);

    /**
     * @return The number of rows of the matrix.
     */
    unsigned getRows() const;

    /**
     * @return The number of columns of the matrix.
     */
    unsigned getColumns() const;

    /**
     * @return The element of the matrix at the given row and column.
     */
    double get(unsigned row, unsigned column) const;

    /**
     * @brief Set the value at a given row and column.
     */
    void set(unsigned row, unsigned column, double value);

    /**
     * @brief Change the matrix data for the values in the argument vector.
     * @param values Vector with the new values for the matrix.
     * The vector must contain the same number of elements as the matrix.
     */
    void setValues(std::vector<double> values);

private:
    unsigned rows, columns;
    std::vector<double> data;
};

#endif // MATRIX_H
