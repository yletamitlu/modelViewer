#ifndef VIEWER_MATRIX_H
#define VIEWER_MATRIX_H

#include "array.h"

template <typename T>
class Matrix {
public:
    explicit Matrix(int s) {
        size = s;
        matrix = new Array<T>[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = Array<T>(size);
        }
    }

    ~Matrix() {
        delete[] matrix;
    }

    Array<T>& operator[](int index) {
        return matrix[index];
    }

    Array<T>& operator[](int index) const {
        return matrix[index];
    }

    Matrix operator* (const Matrix& factorM) {
        Matrix result(size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    result[i][j] += matrix[i][k] * factorM[k][j];
                }
            }
        }

        return result;
    }

    void print_matrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    Array<T>* matrix;
    int size = 0;

};

#endif //VIEWER_MATRIX_H
