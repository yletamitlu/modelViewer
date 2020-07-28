#ifndef VIEWER_BASEDRAWER_H
#define VIEWER_BASEDRAWER_H

#include "model/face.h"
#include "model/basemodel.h"

class BaseDrawer {
public:
    virtual ~BaseDrawer() {}

    virtual void drawPolygon(Face& face) = 0;

    virtual void drawModel(BaseModel& model) = 0;
};

#endif //VIEWER_BASEDRAWER_H
