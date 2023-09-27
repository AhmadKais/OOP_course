#pragma once
#include "Matrix.h"
#include <iostream>

template<int row, int col, typename T = int>
class MatrixContainer
{
private:
    int _size = 0;
    int index = 0;
    Matrix<row, col, T>** Container = new Matrix<row, col, T>* [1];
    int limit = 1;

public:
    void addMatrix(Matrix<row, col, T>& mat) {
        Container[index] = &mat;
        index++;
        _size++;
        if (_size == limit) {
            moveToBiggerContainer();
        }
    }

    int size() const {
        return _size;
    }

    void moveToBiggerContainer() {
        int newLimit = 2 * limit;
        Matrix<row, col, T>** newContainer = new Matrix<row, col, T>* [newLimit];
        for (int i = 0; i < limit; i++) {
            newContainer[i] = Container[i];
        }
        delete[] Container;
        limit = newLimit;
        Container = newContainer;
    }

    void moveToSmallerContainer() {
        if (limit > 1) { // Ensuring we don't shrink below the initial size
            int newLimit = limit / 2;
            Matrix<row, col, T>** newContainer = new Matrix<row, col, T>* [newLimit];
            for (int i = 0; i < newLimit; i++) {
                newContainer[i] = Container[i];
            }
            delete[] Container;
            limit = newLimit;
            Container = newContainer;
        }
    }

    void removeLastMatrix() {
        if (index > 0) {
            index--;
            _size--;
            if (_size <= limit / 4) {
                moveToSmallerContainer();
            }
        }
        else {
            std::cout << " there are no elements to remove !" << std::endl;
        }
    }

    Matrix<row, col, T> addMatricesAtIndexes(int index1, int index2) const {
        return *Container[index1] + *Container[index2];
    }

    Matrix<row, col, T> mulMatAtIndexByScalar(int index, T Scalar) const {
        return *Container[index] * Scalar;
    }

    friend std::ostream& operator<<(std::ostream& os, const MatrixContainer& mc) {
        os << "There are " << mc._size << " matrices in the container. The matrices:" << std::endl;
        for (int i = 0; i < mc._size; i++) {
            os << *mc.Container[i] << std::endl;
        }
        return os;
    }

    ~MatrixContainer() {
        delete[] Container;
    }
};
