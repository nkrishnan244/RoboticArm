#ifndef MESH_HEADER
#define MESH_HEADER

#include "vertex.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "shader.hpp"

class Mesh
{
private:
    Vertex* vertexArray; 
    unsigned int nrOfVertices;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO; 

    // Initializers
    void initVAO();

public:

    // Constructors, Destructors
    Mesh(std::vector<Vertex*> vertices);
    ~Mesh();

    // Public functions
    void render(Shader* shader); 
};

#endif