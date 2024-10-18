#pragma once
#include "MatrixBase.h"
#include <stdexcept>

template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    using MatrixBase<T>::MatrixBase;

    MatrixNumerical<T> operator+(const MatrixNumerical& other) const;
    MatrixNumerical<T> operator-(const MatrixNumerical& other) const;
    MatrixNumerical<T> operator*(const MatrixNumerical& other) const;
    MatrixNumerical<T> operator/(const MatrixNumerical& other) const;

    MatrixNumerical<T> operator*(T scalar) const;
    MatrixNumerical<T> operator/(T scalar) const;

    T getDeterminant() const;
    MatrixNumerical<T> getInverse() const;

    static MatrixNumerical<T> getIdentity(size_t size);

private:
    MatrixNumerical<T> getCoFactor(size_t p, size_t q, size_t n) const;
    T determinantHelper(const MatrixNumerical& matrix, size_t n) const;
};
