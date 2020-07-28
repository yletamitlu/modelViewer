#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QDebug>

#include "../model/vertice.h"
#include "../model/carcasemodel.h"
#include "../model/face.h"

class BaseParser
{
public:
    BaseParser(char* d) : data(d) {}
    virtual ~BaseParser() {}

    virtual BaseModel* parse() = 0;

protected:
    char* data;
    std::vector<Vertice> vs;
    std::vector<Face> fs;

    virtual void parseVertices(std::stringstream& data);
    virtual void parseFaces(std::stringstream& data);

private:
    virtual BaseModel* createModel() = 0;
};

#endif // PARSER_H
