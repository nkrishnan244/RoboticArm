#ifndef SHADER_HEADER
#define SHADER_HEADER

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
    // Member variables
    GLuint id; // program id

    // Private functions
    std::string loadShaderSource(char* fileName);
    GLuint loadShader(GLenum type, char* fileName);

    // Link shaders
    void linkProgram(GLuint vertexShader);

public:

    // Constructors/Destructors
    Shader();
    ~Shader();

    // Public functions
    void use();
    void unuse();
};

#endif