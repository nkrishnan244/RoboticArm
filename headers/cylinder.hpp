#ifndef CYLINDER_HEADER
#define CYLINDER_HEADER

#include "vertex.hpp"
#include <vector>

class Cylinder
{
private:
    double pitch;
    double yaw;
    double roll;
    // std::vector<Vertex*> vertices;
    // glm::vec3 xAxis;
    // glm::vec3 yAxis; 

public:
    Cylinder();
    ~Cylinder();

    // Modifiers
    void setVertices(std::vector<Vertex*>& vertices, double radius, double height);
    void setRoll(double roll);
    void setPitch(double pitch);
    void setYaw(double yaw);

    // Public functions
    void getRotationMatrix(glm::mat3& rotMatrix);
};

#endif