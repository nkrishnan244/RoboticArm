#include "cylinder.hpp"
#include "vertex.hpp"

Cylinder::Cylinder()
{

}

Cylinder::~Cylinder()
{

}

void Cylinder::setVertices(double radius, double height)
{
    glm::vec3 vert1 = glm::vec3(-0.5f, -0.5f, 0.f);
    glm::vec3 vert2 = glm::vec3(0.5f, -0.5f, 0.f);
    glm::vec3 vert3 = glm::vec3(0.f, 0.5f, 0.f); 

    this->vertices.push_back(new Vertex(vert1));
    this->vertices.push_back(new Vertex(vert2));
    this->vertices.push_back(new Vertex(vert3));
}
