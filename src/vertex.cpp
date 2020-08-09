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

glm::vec3 Vertex::getPosition() const
{
    return this->position;
}

void Vertex::setPosition(glm::vec3 position)
{
    this->position = position;
}