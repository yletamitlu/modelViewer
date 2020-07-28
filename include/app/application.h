#ifndef APPLICATION_H
#define APPLICATION_H

#include <QDebug>

#include "parser/carcasemodelparser.h"
#include "reader/filereader.h"
#include "model/carcasemodel.h"
#include "exceptions/readexception.h"
#include "drawer/basedrawer.h"

class Application {
public:
    Application();
    ~Application() {
        delete model;
    }

    void loadModel(std::string filename);
    void drawModel(BaseDrawer& drawer);

private:
    BaseModel* model;
};

#endif // APPLICATION_H
