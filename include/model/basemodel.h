#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <vector>
#include <string>
#include <iostream>

#include "face.h"
#include "vertice.h"
#include "tools/matrix.h"


class BaseModel {
public:
    virtual ~BaseModel() {}

    std::vector<Face>& getFaces() {
        return faces;
    };

    void setFaces(std::vector<Face>& f) {
        faces = f;
    };

protected:
    std::vector<Face> faces;
};

#endif // BASEMODEL_H
