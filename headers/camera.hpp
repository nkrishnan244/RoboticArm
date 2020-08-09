#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SOIL2.h>

class Camera
{
private:
    GLfloat pitch; // around x
    GLfloat yaw; // around y
    GLfloat roll; // around z

    glm::vec3 position; // camera position
    glm::vec3 direction; // direction camera is pointing
    glm::vec3 right; // axis pointing out to the right of the camera
    glm::vec3 up; // axis pointing up from camera
    

public:
    // Constructors/Destructors
    Camera(); 
    ~Camera();

    // Accessors

    // Modifiers

    // Public functions
    void getRotationMatrix(glm::mat3& rotMatrix); 
};

#endif