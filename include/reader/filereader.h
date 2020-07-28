#ifndef FILEREADER_H
#define FILEREADER_H

#include "basereader.h"
#include "model/carcasemodel.h"
#include "parser/baseparser.h"

#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <QDebug>

class FileReader : public BaseReader
{
private:
    FILE* file;

    char* get_char_array();

public:
    FileReader(std::string filename);
    ~FileReader() override;

    char* read() override;

};

#endif // FILEREADER_H
