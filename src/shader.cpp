#include "shader.hpp"
#include <fstream>

using namespace std;

// Private Functions

/*
Shaders are read in by opengl as a string
Therefore, this function basically takes our glsl file and turns it into a compatible string
*/
string Shader::loadShaderSource(char* fileName)
{
    string temp;
    string src;

    ifstream in_file;

    in_file.open(fileName);

    if (in_file.is_open())
    {
        while (getline(in_file, temp)) // read next line into temp
        {
            src += temp + "\n"; // add next line to our string src
        }
    }
    else 
    {
        cout << "ERROR::SHADER::LOAD_SHADER_SOURCE::COULD_NOT_OPEN_FILE: " << fileName << "\n";
    }
    in_file.close();

    return src;
}

/*
This function takes a type and file name of a shader and loads it in as a GLuint
*/
GLuint Shader::loadShader(GLenum type, char* fileName)
{
    char infoLog[512]; // information if program can't link or shader can't compile
    GLint success;

    GLuint shader = glCreateShader(type); // type can be vertex, fragment
    string str_src = this->loadShaderSource(fileName);

    const GLchar* src = str_src.c_str(); // string to c string
    glShaderSource(shader, 1, &src, NULL); // set the source string as the shader
    glCompileShader(shader); // compile the code that we loaded in for the shader

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success); // See if shader succesfully compiled (-1 or 1)

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog); // see what happened
        cout << "ERROR::SHADER::LOAD_SHADER::COULD_NOT_COMPILE_SHADER: " << fileName << "\n";
        cout << infoLog << "\n";
    }

    return shader; // return a compiled shader
}

// Actually move the shaders to a program and link it
void Shader::linkProgram(GLuint vertexShader, GLuint fragmentShader)
{
    GLint success = true;
    char infoLog[512];

    this->id = glCreateProgram(); // A program object is an object to which shader objects can be attached

    glAttachShader(this->id, vertexShader); // Attach shader to program
    glAttachShader(this->id, fragmentShader);

    /* will be used to create an executable that will run on the programmable vertex processor
    essentially runs this program every time we send in a vertex
    */
    glLinkProgram(this->id); 

    glGetProgramiv(this->id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(this->id, 512, NULL, infoLog);
        cout << infoLog << "\n";
        cout << "ERROR::SHADER::LINK_PROGRAM::COULD_NOT_LINK_PROGRAM" << "\n";
    }

    glUseProgram(0); // we are not ready to use the current program yet
}

// Constructors/Destructors
Shader::Shader()
{
    // load in vertex shader (essentially you can manipulate the position of vertices) 
    char* vertex_file_name = "shaders/vertex_core.glsl";
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertex_file_name);

    // load in fragment shader (essentially you can manipulate the color distribution)
    char* fragment_file_name = "shaders/fragment_core.glsl";
    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragment_file_name);

    this->linkProgram(vertexShader, fragmentShader);

    // delete shaders and free up memory
    glDeleteShader(vertexShader);
}

Shader::~Shader()
{
    glDeleteProgram(this->id);
}

// Public Functions
void Shader::use()
{
    glUseProgram(this->id); // let's use this program
}

void Shader::unuse()
{
    glUseProgram(0);
}