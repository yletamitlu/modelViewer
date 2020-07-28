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
    f.vertices.push_back(vs[a]);

    data >> b;
    f.vertices.push_back(vs[b]);

    data >> c;
    f.vertices.push_back(vs[c]);

    fs.push_back(f);
}
