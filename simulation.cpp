#include "simulation.hpp"
#include <iostream>

using namespace std;

/*
GLFW provides a simple API for creating windows, contexts and surfaces, receiving input and events (using opengl)
*/
bool Simulation::initGLFW()
{
    // Init GLFW
    if (glfwInit() == GLFW_FALSE)
    {
        cout << "ERROR::SIMULATION::INIT_GLFW::GLFW_INIT_FAILED" << "\n";
        glfwTerminate();
        return false; 
    }
    return true; 
}

/*
Initialize the window that will be used
*/
bool Simulation::initGLFWWindow(const char* title)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // version of glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5); // version of glfw

    this->window = glfwCreateWindow(this->WINDOW_WIDTH, this->WINDOW_HEIGHT, title, NULL, NULL);

    if (this->window == nullptr)
    {
        std::cout << "ERROR::SIMULATION::INIT_GLFW_WINDOW::GLFW_WINDOW_INIT_FAILED" << "\n";
        glfwTerminate();
        return false; 
    }

    // Basically, use all the settings/drawings that we have changed since the last time we made the context current
    // (update the state)
    glfwMakeContextCurrent(window);

    return true;
}

/*
GLEW provides efficient run-time mechanisms for determining which OpenGL extensions are supported on the target platform.
*/
bool Simulation::initGLEW()
{
    // INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
    glewExperimental = GL_TRUE; // fixes a bug with GLEW

    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR::SIMULATION::INIT_GLEW::GLEW_INIT_FAILED" << "\n";
        glfwTerminate();
        return false;
    }
    return true;
}

// set options related to opengl preferences
void Simulation::initOpenGLOptions()
{

}

// Update window based on keyboard inputs
void Simulation::updateKeyboardInput()
{
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(this->window, GLFW_TRUE);
    }
}

Simulation::Simulation()
{
    this->WINDOW_WIDTH = 1920;
    this->WINDOW_HEIGHT = 1080;

    this->initGLFW();
    this->initGLFWWindow("Robotic Arm Simulation");
    this->initGLEW();
    this->initOpenGLOptions();
}

Simulation::~Simulation()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

// Accessors
int Simulation::getWindowShouldClose() const
{
    return glfwWindowShouldClose(this->window);
}

// Modifiers
void Simulation::setWindowShouldClose()
{
    glfwSetWindowShouldClose(this->window, GLFW_TRUE);
}

// Functions
void Simulation::update()
{
    glfwPollEvents(); // allows cursor/keyboard to interact with window

    this->updateKeyboardInput();
}