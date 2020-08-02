#ifndef VERTEX_HEADER
#define VERTEX_HEADER

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class Vertex
{
private:
    glm::vec3 position; // position of vertex
    glm::vec3 color; // color of vertex
    // glm::vec2 texcoord; // texture coordinate of vertex
    // glm::vec3 normal; 

public:

    // Constructors/Destructors
    Vertex();
    Vertex(glm::vec3 position);
    ~Vertex();

    // Accessors

    // Modifiers
    void setPosition(glm::vec3 position);
};

#endif