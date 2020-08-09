#ifndef VIEWER_MODIFIER_H
#define VIEWER_MODIFIER_H

#include "model/basemodel.h"
#include "tools/matrix.h"

#include <cmath>

class Modifier {
public:
    Modifier() : model(nullptr) {}
    ~Modifier() = default;

    void set(BaseModel* m);

    void move(double x, double y);

    void scale(double k);

    void rotateX(double x);

    void rotateY(double y);

private:
    BaseModel* model;
    Matrix<double> state;

    void changeModel(Matrix<double>& transformation);
};


#endif //VIEWER_MODIFIER_H
