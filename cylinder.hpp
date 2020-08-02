#ifndef CYLINDER_HEADER
#define CYLINDER_HEADER

#include "vertex.hpp"
#include <vector>

class Cylinder
{
private:
    std::vector<Vertex> vertices;

public:
    Cylinder();
    ~Cylinder();

    void setVertices(double radius, double height);
};

#endif