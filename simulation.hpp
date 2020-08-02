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

    // Initializations
    bool initGLFW();
    bool initGLFWWindow(const char* title);
    bool initGLEW();
    void initOpenGLOptions();

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

};

#endif