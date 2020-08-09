#include "mesh.hpp"
#include "vertex.hpp"

using namespace std;

void Mesh::initVAO()
{
    /* Vertex Array Objects (VAO's) contain the pointers to VBO memory needed for draw commands
    for example (x0, y0, z0, color1, color2, color3, x1, y1, y2...) are stored in VBO
    But VAO's know where the positions begin, colors begin, etc
    */
    glGenVertexArrays(1, &this->VAO); // create a VAO to hold the triangle data
    glBindVertexArray(this->VAO); 

    /* As shown above, VBO's store the actual data in the gpu.
    They allow us to send large amounts of data to the gpu rather than sending them one at a time
    */
    glGenBuffers(1, &this->VBO); // allocate memory for one buffer (Vertex buffer object)
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO); // bind VBO to attach point GL_ARRAY_BUFFER
    glBufferData(GL_ARRAY_BUFFER, this->nrOfVertices*sizeof(Vertex), this->vertexArray, GL_STATIC_DRAW); // send the actual data in

    // Set VAO pointers so that the gpu knows how to split up the data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glEnableVertexAttribArray(0);

    // Not ready to bind 1 yet
    glBindVertexArray(0);
}

Mesh::Mesh(vector<Vertex*> vertices)
{
    this->nrOfVertices = vertices.size();

    this->vertexArray = new Vertex[this->nrOfVertices];
    for (size_t i = 0; i < nrOfVertices; i++)
    {
        this->vertexArray[i] = *vertices[i];
    } 

    // initialize functions
    this->initVAO();
}

Mesh::~Mesh()
{

}

void Mesh::render(Shader* shader)
{
    // update uniforms

    // need to use the shader as they get unbinded after updating uniforms

    // bind vertex array object 
    glBindVertexArray(this->VAO);

    // actually render the object
    glDrawArrays(  GL_TRIANGLE_STRIP, 0, this->nrOfVertices); 

    // Unbind everything after rendering
    glBindVertexArray(0);
    glUseProgram(0);
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}