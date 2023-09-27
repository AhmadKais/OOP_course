#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <algorithm>

template <int row, int col, typename T = int>
class Matrix {
private:
    T data[row][col];

public:
    // Default constructor that initializes the matrix with zeros
    explicit Matrix(T val = 0) {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j] = val;
    }

    // Accessor (for read and write)
    T& operator()(int i, int j) {
        return data[i][j];
    }

    // Getter for diagonal
    T* getDiag(int& number) {
        number = std::min(row, col);
        T* diag = new T[number];
        for (int i = 0; i < number; i++)
            diag[i] = data[i][i];
        return diag;
    }

    // Return identity matrix
    static Matrix<row, col, T> getIdentityMatrix() {
        Matrix<row, col, T> identity;
        for (int i = 0; i < std::min(row, col); i++)
            identity.data[i][i] = 1;
        return identity;
    }

    // Operator overloadings
    Matrix<row, col, T> operator+(const T& scalar)const {
        Matrix<row, col, T> result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] + scalar;
        return result;
    }
    
    Matrix<row, col, T> operator+(const Matrix<row, col, T>& rhs) {
        Matrix<row, col, T> result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] + rhs.data[i][j];
        return result;
    }

    Matrix<row, col, T> operator-(const T& scalar) const {
        Matrix<row, col, T> result = *this + (-scalar);
        return result;
    }

    Matrix<row, col, T> operator-(const Matrix<row, col, T>& rhs) {
        Matrix<row, col, T> result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] - rhs.data[i][j];
        return result;
    }
    Matrix<row, col, T> operator-() const {
        Matrix<row, col, T> result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = -data[i][j];
        return result;
    }




    Matrix<row, col, T> operator*(const T& scalar) {
        Matrix<row, col, T> result;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }
    
   


    // Unary ++ and -- operators
    Matrix<row, col, T>& operator++() {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j]++;
        return *this;
    }

    Matrix<row, col, T>& operator--() {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                data[i][j]--;
        return *this;
    }

    // Postfix ++ and -- operators
    Matrix<row, col, T> operator++(int) {
        Matrix<row, col, T> temp(*this);
        operator++();
        return temp;
    }

    Matrix<row, col, T> operator--(int) {
        Matrix<row, col, T> temp(*this);
        operator--();
        return temp;
    }

    // Convert to scalar type T
    explicit operator T() {
        T sum = 0;
        for (int i = 0; i < std::min(row, col); i++)
            sum += data[i][i];
        return sum;
    }

    // Friend function for printing
    friend std::ostream& operator<<(std::ostream& os, const Matrix<row, col, T>& mat) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                os << mat.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend Matrix<row, col, T> operator+(int val, const Matrix& mat) {
        Matrix result;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result.data[i][j] = val + mat.data[i][j];
            }
        }
        return result;
    }

    friend Matrix<row, col, T> operator-(int val, const Matrix<row, col, T>& mat);

    // TODO: Add other member functions and operator overloads as needed.
};

template <int row, int col, typename T>
Matrix<row, col, T> operator-(int val , const Matrix<row, col, T>& mat) {
    Matrix<row, col, T> result;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result.data[i][j] = val - mat.data[i][j];
        }
    }
    return result;
}

#endif // MATRIX_H
