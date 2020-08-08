#ifndef CARCASEMODEL_H
#define CARCASEMODEL_H

#include "basemodel.h"

class CarcaseModel : public BaseModel
{
public:
    explicit CarcaseModel(std::vector<Face>& _faces) {
        this->faces = _faces;
    }

    ~CarcaseModel() {}
};

#endif // CARCASEMODEL_H
