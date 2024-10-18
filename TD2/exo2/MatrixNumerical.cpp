#include "MatrixNumerical.h"

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical& other) const {
    MatrixNumerical result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) + other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical& other) const {
    MatrixNumerical result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) - other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical& other) const {
    MatrixNumerical result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) * other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical& other) const {
    MatrixNumerical result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) / other.getElement(i, j));
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(T scalar) const {
    MatrixNumerical result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) * scalar);
        }
    }
    return result;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(T scalar) const {
    MatrixNumerical result(this->rows, this->cols);
    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            result.addElement(i, j, this->getElement(i, j) / scalar);
        }
    }
    return result;
}

template <typename T>
T MatrixNumerical<T>::getDeterminant() const {
    return determinantHelper(*this, this->rows);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getCoFactor(size_t p, size_t q, size_t n) const {
    MatrixNumerical<T> result(n - 1, n - 1);
    size_t row = 0, col = 0;

    for (size_t i = 0; i < n; i++) {
        if (i == p) continue;
        col = 0;
        for (size_t j = 0; j < n; j++) {
            if (j == q) continue;
            result.addElement(row, col++, this->getElement(i, j));
        }
        row++;
    }
    return result;
}

template <typename T>
T MatrixNumerical<T>::determinantHelper(const MatrixNumerical& matrix, size_t n) const {
    if (n == 1) return matrix.getElement(0, 0);
    if (n == 2) return matrix.getElement(0, 0) * matrix.getElement(1, 1) - matrix.getElement(0, 1) * matrix.getElement(1, 0);

    T determinant = 0;
    int sign = 1;

    for (size_t f = 0; f < n; f++) {
        MatrixNumerical<T> cofactorMatrix = matrix.getCoFactor(0, f, n);
        determinant += sign * matrix.getElement(0, f) * determinantHelper(cofactorMatrix, n - 1);
        sign = -sign;
    }
    return determinant;
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    T det = this->getDeterminant();
    MatrixNumerical<T> adjugate(this->rows, this->cols);

    for (size_t i = 0; i < this->rows; ++i) {
        for (size_t j = 0; j < this->cols; ++j) {
            adjugate.addElement(i, j, (i + j) % 2 == 0 ? getCoFactor(i, j, this->rows).getDeterminant() : -getCoFactor(i, j, this->rows).getDeterminant());
        }
    }
    return adjugate * (1 / det);
}

template <typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(size_t size) {
    MatrixNumerical result(size, size);
    for (size_t i = 0; i < size; ++i) {
        result.addElement(i, i, 1);
    }
    return result;
}

template class MatrixNumerical<int>;
template class MatrixNumerical<float>;
template class MatrixNumerical<double>;
