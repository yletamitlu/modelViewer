#include "Modifier.h"

void Modifier::set(BaseModel* m) {
    model = m;
    state = {{1, 0, 0, 0},
             {0, 1, 0, 0},
             {0, 0, 1, 0},
             {0, 0, 0, 1}};
}

void Modifier::move(double x, double y) {
    Matrix<double> moveMatrix = {{1, 0, 0, 0},
                                 {0, 1, 0, 0},
                                 {0, 0, 1, 0},
                                 {x, y, 0, 1}};

    state *= moveMatrix;

    changeModel();
}

void Modifier::scale(double k) {
    Matrix<double> scaleMatrix = {{k, 0, 0, 0},
                                  {0, k, 0, 0},
                                  {0, 0, k, 0},
                                  {0, 0, 0, 1}};

    state *= scaleMatrix;

    changeModel();
}

void Modifier::rotateX(double x) {
    x = x * M_PI / 180;

    Matrix<double> rotateMatrix = {{1, 0,       0,      0},
                                   {0, cos(x),  sin(x), 0},
                                   {0, -sin(x), cos(x), 0},
                                   {0, 0,       0,      1}};

    state *= rotateMatrix;

    changeModel();
}

void Modifier::rotateY(double y) {
    y = y * M_PI / 180;

    Matrix<double> rotateMatrix = {{cos(y), 0, -sin(y), 0},
                                   {0,      1, 0,       0},
                                   {sin(y), 0, cos(y),  0},
                                   {0,      0, 0,       1}};

    state *= rotateMatrix;

    changeModel();
}

void Modifier::changeModel() {
    auto& faces = model->getFaces();

    //итерируемся по фейсам
    for (auto& f : faces) {
        //для каждой вершины тек фейса
        for (auto& vertice : f.vertices) {
            //создаем вектор с вершиной {x, y, z, 1}
            std::vector<double> vrtc = {vertice.x,
                                        vertice.y,
                                        vertice.z,
                                        1};
            //умножаем его на матрицу преобразования
            auto newV = state * vrtc;

            //создаем из полученного вектора новую вершину v
            Vertice v(newV[0], newV[1], newV[2]);

            vertice = v;
        }
    }
    state = {{1, 0, 0, 0},
             {0, 1, 0, 0},
             {0, 0, 1, 0},
             {0, 0, 0, 1}};
}