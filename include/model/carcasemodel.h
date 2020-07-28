#ifndef CARCASEMODEL_H
#define CARCASEMODEL_H

#include "basemodel.h"

class CarcaseModel : public BaseModel
{
public:
    CarcaseModel(std::vector<Face>& _faces) {
        this->faces = _faces;
    }
};

#endif // CARCASEMODEL_H
