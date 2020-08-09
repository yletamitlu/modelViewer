#ifndef VIEWER_MATRIX_H
#define VIEWER_MATRIX_H

template <typename T>
class Matrix {
private:
    T** data;
    int size{};

public:
    Matrix() : data(nullptr), size(0) {}

    explicit Matrix(int size) {
        this->size = size;
        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
        }
    }

    Matrix(const std::initializer_list<std::initializer_list<T>>& list) {
        this->size = list.size();
        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
        }

        int k = 0, z = 0;
        for (auto i = list.begin(); i != list.end(); ++i) {
            for (auto j = i->begin(); j != i->end(); ++j) {
                data[k][z] = *j;
                z++;
            }
            k++;
            z = 0;
        }
    }

    Matrix(const Matrix<T>& m) {
        size = m.size;

        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                data[i][j] = m.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    Matrix<T>& operator=(const Matrix &other) {
        if (this->data) {
            for (int i = 0; i < size; i++) {
                delete[] data[i];
            }
            delete[] data;
        }

        this->size = other.size;

        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
        }

        for (int i = 0; i < other.size; i++) {
            for (int j = 0; j < other.size; j++) {
                this->data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    T& operator()(int i, int j) {
        if (i >= size || j >= size || i < 0 || j < 0) {
            throw std::exception();
        }

        return data[i][j];
    }

    Matrix<T> operator*(const Matrix<T>& m) {
        if (m.size != size) {
            throw std::exception();
        }

        Matrix<T> res(m.size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                res.data[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    res.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }

        return res;
    }

    Matrix<T>& operator*=(const Matrix<T>& m) {
        if (m.size != size) {
            throw std::exception();
        }

        Matrix<T> temp(*this);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                data[i][j] = 0;
                for (int k = 0; k < size; k++) {
                    data[i][j] += temp.data[i][k] * m.data[k][j];
                }
            }
        }

        return *this;
    }

    std::vector<T> operator*(const std::vector<T>& v) {
        if (size != v.size()) {
            throw std::exception();
        }

        std::vector<T> res(size);

        for (int i = 0; i < size; i++) {
            res[i] = 0;
            for (int j = 0; j < size; j++) {
                res[i] += v[j] * data[j][i];
            }
        }

        return res;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
     }
};

#endif //VIEWER_MATRIX_H
