#ifndef APPLICATION_H
#define APPLICATION_H

#include <QDebug>

#include "parser/carcasemodelparser.h"
#include "reader/filereader.h"
#include "model/carcasemodel.h"
#include "exceptions/readexception.h"
#include "drawer/basedrawer.h"
#include "modifier/Modifier.h"

class Application {
public:
    Application();
    ~Application() {
        delete model;
    }

    void loadModel(std::string filename);
    void drawModel(BaseDrawer& drawer);

    void move(double x, double y);
    void scale(double k);
    void rotateX(double x);
    void rotateY(double y);

private:
    BaseModel* model;
    Modifier modifier;
};

#endif // APPLICATION_H
