#ifndef SIMULATION_HEADER
#define SIMULATION_HEADER

#include "model.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "camera.hpp"

class Simulation
{
private:
    // window
    GLFWwindow* window; 
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;

    // Shaders
    std::vector<Shader*> shaders;

    // Model params
    std::vector<Model*> models;
    float modelScale; 

    // Model matrix
    glm::mat4 ModelMatrix; 

    // Camera
    Camera camera;  

    // Initialize OpenGL window
    bool initGLFW();
    bool initGLFWWindow(const char* title);
    bool initGLEW();
    void initOpenGLOptions();
    void initUniforms();

    // Initialize Model
    void initShaders();
    void initModel();

    // Updates
    void updateKeyboardInput();
    void updateUniforms();

public:
    Simulation();
    ~Simulation();

    // Accessors
    int getWindowShouldClose() const;

    // Modifiers
    void setWindowShouldClose();

    // Public Functions
    void update();
    void render();

};

#endif