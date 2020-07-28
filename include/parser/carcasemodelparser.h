#ifndef CARCASEMODELPARSER_H
#define CARCASEMODELPARSER_H

#include "baseparser.h"

class CarcaseModelParser : public BaseParser
{
public:
    CarcaseModelParser(char* d);
    CarcaseModel* parse() override;

private:
    CarcaseModel* createModel() override;
};

#endif // CARCASEMODELPARSER_H
