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



        state *= moveMatrix;

        state.print();

//        model->StateMatrix().print_matrix();

//        for (int i = 0; i < 1; i++){
//            Matrix<double> f(1, 4);
//            f[0][0] = model->getFaces().at(i).vertices[i].x;
//            f[0][1] = model->getFaces().at(i).vertices[i].y;
//            f[0][2] = model->getFaces().at(i).vertices[i].z;
//            f[0][3] = 1;
//            f.print_matrix();
//        }
    }

private:
    BaseModel* model;
    Matrix<double> state;
};


#endif //VIEWER_MODIFIER_H
