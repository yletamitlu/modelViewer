#ifndef VERTICE_H
#define VERTICE_H


struct Vertice
{
    Vertice() = default;
    Vertice(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    double x = 0;
    double y = 0;
    double z = 0;
};

#endif // VERTICE_H
