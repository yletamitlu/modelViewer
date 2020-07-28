#include "parser/carcasemodelparser.h"

CarcaseModelParser::CarcaseModelParser(char* d)
    : BaseParser(d)
{
}

CarcaseModel* CarcaseModelParser::parse() {
    std::stringstream stream(data);
    std::string line;

    while (getline(stream, line)) {
        std::stringstream temp(line);

        std::string contentType;
        temp >> contentType;

        if (strcmp(contentType.c_str(), "v") == 0) {
            parseVertices(temp);
        } else if (strcmp(contentType.c_str(), "f") == 0) {
            parseFaces(temp);
        }
    }

    return createModel();
}

CarcaseModel* CarcaseModelParser::createModel() {
    return new CarcaseModel(this->fs);
}
