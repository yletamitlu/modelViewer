#ifndef VIEWER_MODIFIER_H
#define VIEWER_MODIFIER_H

#include "model/basemodel.h"
#include "tools/matrix.h"

class Modifier {
public:
    Modifier() : model(nullptr) {}
    ~Modifier() = default;

    void set(BaseModel* m) {
        model = m;
        state = {{1, 0, 0, 0},
                 {0, 1, 0, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 1}};
    }

    void move(double x, double y) {
        Matrix<double> moveMatrix = {{1, 0, 0, 0},
                                     {0, 1, 0, 0},
                                     {0, 0, 1, 0},
                                     {x, y, 0, 1}};



        state = {{1, 0, 0, 0},
                 {0, 1, 0, 0},
                 {0, 0, 1, 0},
                 {0, 0, 0, 1}};

        state *= moveMatrix;

        state.print();

        auto& faces = model->getFaces();

        //итерируемся по фейсам
        for (auto & f : faces){
            //для каждой вершины тек фейса
            for (auto & vertice : f.vertices) {
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
    }

private:
    BaseModel* model;
    Matrix<double> state;
};


#endif //VIEWER_MODIFIER_H
