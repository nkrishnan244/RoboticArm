#include "vertex.hpp"

Vertex::Vertex()
{
    
}

Vertex::Vertex(glm::vec3 position)
    : position(position)
{

}

Vertex::~Vertex()
{

}

void Vertex::setPosition(glm::vec3 position)
{
    this->position = position;
}