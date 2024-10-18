#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class MatrixBase {
protected:
    vector<vector<T>> data;
    size_t rows, cols;

public:
    MatrixBase(size_t rows, size_t cols);

    void addElement(size_t row, size_t col, T value);
    T getElement(size_t row, size_t col) const;
    size_t getRows() const;
    size_t getCols() const;
    void display() const;
};
