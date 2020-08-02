#ifndef SIMULATION_HEADER
#define SIMULATION_HEADER

#include "model.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

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

    // Initialize OpenGL window
    bool initGLFW();
    bool initGLFWWindow(const char* title);
    bool initGLEW();
    void initOpenGLOptions();

    // Initialize Model
    void initModel();

    // Updates
    void updateKeyboardInput();

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