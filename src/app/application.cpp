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
    modifier.move(x, y);
}

void Application::scale(double k) {
    modifier.scale(k);
}

void Application::rotateX(double x) {
    modifier.rotateX(x);
}

void Application::rotateY(double y) {
    modifier.rotateY(y);
}
