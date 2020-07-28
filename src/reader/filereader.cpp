#include "reader/filereader.h"

FileReader::FileReader(std::string filename)
{
    //file = std::ifstream(filename);
    file = fopen(filename.c_str(), "r");

}

char* FileReader::read() {
    return get_char_array();
}

char* FileReader::get_char_array() {
    if (!file) {
        return nullptr;
    }

    fseek(file , 0 , SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = new char[size + 1];

    if (!buffer) {
        return nullptr;
    }

    size_t result = fread(buffer, 1, size, file);
    buffer[result] = '\0';

    return buffer;
}

FileReader::~FileReader() {
}
