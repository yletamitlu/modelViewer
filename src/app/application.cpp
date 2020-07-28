#include "app/application.h"

Application::Application() : model(nullptr) {
}

void Application::loadModel(std::string filename) {
    std::cout << "FILENAME: " << filename << std::endl;
    auto reader = new FileReader(filename);

    auto data = reader->read();

    if (!data) {
        throw ReadException();
    }

    auto parser = new CarcaseModelParser(data);

    model = parser->parse();

    delete reader;

}

void Application::drawModel(BaseDrawer& drawer) {
    auto f = model->getFaces();
    drawer.drawPolygon(f[0]);
    drawer.drawPolygon(f[1]);
    drawer.drawPolygon(f[2]);
}
