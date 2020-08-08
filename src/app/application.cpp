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

    model = parser->parse();

    modifier.set(model);

    delete reader;
}

void Application::drawModel(BaseDrawer& drawer) {
    drawer.drawModel(*model);
}

void Application::move(double x, double y) {
    modifier.move(x, y);
}
