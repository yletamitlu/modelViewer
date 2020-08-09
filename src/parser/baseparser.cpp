#include "parser/baseparser.h"


void BaseParser::parseVertices(std::stringstream& data) {
    Vertice v;

    data >> v.x;
    data >> v.y;
    data >> v.z;

    vs.push_back(v);
}

void BaseParser::parseFaces(std::stringstream& data) {
    Face f;

    int a, b, c;

    data >> a;
    //так как в obj файлах индексирование с 1
    f.vertices.push_back(vs[a - 1]);

    data >> b;
    f.vertices.push_back(vs[b - 1]);

    data >> c;
    f.vertices.push_back(vs[c - 1]);

    fs.push_back(f);
}
