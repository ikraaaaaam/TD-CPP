#include "MatrixBase.h"

template <typename T>
MatrixBase<T>::MatrixBase(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, vector<T>(cols)) {}

template <typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T value) {
    data[row][col] = value;
}

template <typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const {
    return data[row][col];
}

template <typename T>
size_t MatrixBase<T>::getRows() const {
    return rows;
}

template <typename T>
size_t MatrixBase<T>::getCols() const {
    return cols;
}

template <typename T>
void MatrixBase<T>::display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

template class MatrixBase<int>;
template class MatrixBase<float>;
template class MatrixBase<double>;
