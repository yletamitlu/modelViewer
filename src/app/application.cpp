#include "app/application.h"

Application::Application() : model(nullptr) {
}

void Application::loadModel(std::string filename) {
    auto reader = new FileReader(filename);

    auto data = reader->read();

    if (!data) {
        throw ReadException();
    }

    auto parser = new CarcaseModelParser(data);

    if (model) {
        delete model;
    }

    model = parser->parse();

    modifier.set(model);

    delete reader;
    delete parser;
}

void Application::drawModel(BaseDrawer& drawer) {
    drawer.drawModel(*model);
}

void Application::move(double x, double y) {
    auto a = model->getFaces();

    //std::cout << "do:    " << a[0].vertices[0].x << " " << a[0].vertices[0].y << " " << a[0].vertices[0].z << std::endl;
    modifier.move(x, y);

    a = model->getFaces();

    //std::cout << "posle: " << a[0].vertices[0].x << " " << a[0].vertices[0].y << " " << a[0].vertices[0].z << std::endl;
}
