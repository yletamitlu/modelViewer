#ifndef FACE_H
#define FACE_H

#include <vector>
#include <iostream>

#include "vertice.h"

struct Face
{
    Face() = default;

    std::vector<Vertice> vertices;
};

#endif // FACE_H
