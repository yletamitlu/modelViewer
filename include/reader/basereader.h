#ifndef BASEREADER_H
#define BASEREADER_H

#include "../model/basemodel.h"


class BaseReader {
public:
    virtual ~BaseReader() {};

    virtual char* read() = 0;

};

#endif // BASEREADER_H
