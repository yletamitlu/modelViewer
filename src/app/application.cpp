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
    for (int i = 0; i < f.size(); i++) {
        drawer.drawPolygon(f[i]);
    }
}
