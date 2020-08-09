#ifndef FACE_H
#define FACE_H

#include <vector>
#include <iostream>

#include "vertice.h"

struct Face
{
    Face() = default;
    Face(std::vector<Vertice>& v) : vertices(v) {}

    std::vector<Vertice> vertices;
};

#endif // FACE_H
