#include "cylinder.hpp"
#include "vertex.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

Cylinder::Cylinder()
{
    // this->xAxis = glm::vec3(1.0, 0.0, 0.0);
    // this->yAxis = glm::vec3(0.0, 1.0, 0.0);
}

Cylinder::~Cylinder()
{

}

void Cylinder::setVertices(vector<Vertex*>& vertices, double radius, double height)
{
    double theta_increment = 2.00*M_PI/16.0;
    double prev_x = 0;
    double prev_y = radius;

    for (double theta = 0; theta <= 2.00*M_PI + theta_increment; theta += theta_increment)
    {
        double x = radius*sin(theta);
        double y = radius*cos(theta);
        
        vertices.push_back(new Vertex(glm::vec3(x, y, 0.f)));
        vertices.push_back(new Vertex(glm::vec3(prev_x, prev_y, 0.f)));
        vertices.push_back(new Vertex(glm::vec3(0.f, 0.f, 0.f)));

        prev_x = x;
        prev_y = y;
    }

    prev_x = 0;
    prev_y = radius;

    for (double theta = 0; theta <= 2.00*M_PI + theta_increment; theta += theta_increment)
    {
        double x = radius*sin(theta);
        double y = radius*cos(theta);

        vertices.push_back(new Vertex(glm::vec3(x, y, height)));
        vertices.push_back(new Vertex(glm::vec3(prev_x, prev_y, height)));
        vertices.push_back(new Vertex(glm::vec3(0.f, 0.f, height)));


        prev_x = x;
        prev_y = y;
    }

    prev_x = 0;
    prev_y = radius;

    for (double theta = 0; theta <= 2.00*M_PI + theta_increment; theta += theta_increment)
    {
        double x = radius*sin(theta);
        double y = radius*cos(theta);

        vertices.push_back(new Vertex(glm::vec3(x, y, 0)));
        vertices.push_back(new Vertex(glm::vec3(prev_x, prev_y, 0)));
        vertices.push_back(new Vertex(glm::vec3(prev_x, prev_y, height)));

        vertices.push_back(new Vertex(glm::vec3(x, y, 0)));
        vertices.push_back(new Vertex(glm::vec3(prev_x, prev_y, height)));
        vertices.push_back(new Vertex(glm::vec3(x, y, height)));


        prev_x = x;
        prev_y = y;
    }
}

void Cylinder::setRoll(double roll)
{
    this->roll += roll; 
}

void Cylinder::setPitch(double pitch)
{
    this->pitch += pitch;
}

void Cylinder::setYaw(double yaw)
{
    this->yaw += yaw; 
}


void Cylinder::getRotationMatrix(glm::mat3& rotMatrix)
{
    glm::mat3 rollMat(0.f);

    rollMat[0][0] = cos(roll);
    rollMat[0][1] = sin(roll);
    rollMat[1][0] = -sin(roll);
    rollMat[1][1] = cos(roll); 
    rollMat[2][2] = 1;

    glm::mat3 pitchMat(0.f);

    pitchMat[0][0] = cos(pitch);
    pitchMat[0][2] = sin(pitch);
    pitchMat[1][1] = 1;
    pitchMat[2][0] = -sin(pitch); 
    pitchMat[2][2] = cos(pitch);

    glm::mat3 yawMat(0.f);

    yawMat[0][0] = 1;
    yawMat[1][1] = cos(yaw);
    yawMat[1][2] = -sin(yaw);
    yawMat[2][1] = sin(yaw); 
    yawMat[2][2] = cos(yaw);


    rotMatrix = yawMat*pitchMat*rollMat;
}