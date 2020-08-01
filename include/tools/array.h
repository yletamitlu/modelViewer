#ifndef VIEWER_ARRAY_H
#define VIEWER_ARRAY_H

template <typename T>
class Array {
public:
    Array() : data(nullptr), size(0) {};
    explicit Array(int s) {
        size = s;
        data = new T[size];
    }

    ~Array() {
        delete data;
    }

    T& operator[](int index) {
        return data[index];
    }

    Array& operator=(const Array& a) {
        delete data;

        data = new T[a.size];

        for (int i = 0; i < a.size; i++) {
            data[i] = a.data[i];
        }

        return *this;
    }


private:
    T* data;
    int size;
};


#endif //VIEWER_ARRAY_H
