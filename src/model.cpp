#include "model.hpp"

using namespace std;

// Initializers
void Model::initLinks()
{
    double radius = 0.2;
    double height = 1.0;

    vector<Vertex*> vertices; 

    Cylinder* cyl = new Cylinder();
    cyl->setVertices(vertices, radius, height);
    
    this->links.push_back(cyl);
    this->meshes.push_back(new Mesh(vertices));
}

void Model::initMeshes()
{
    glm::vec3 vert1 = glm::vec3(-0.5f, -0.5f, 0.f);
    glm::vec3 vert2 = glm::vec3(0.5f, -0.5f, 0.f);
    glm::vec3 vert3 = glm::vec3(0.f, 0.5f, 0.f); 

    vector<Vertex*> vertices;
    
    vertices.push_back(new Vertex(vert1));
    vertices.push_back(new Vertex(vert2));
    vertices.push_back(new Vertex(vert3));

    this->meshes.push_back(new Mesh(vertices));
}

// Constructors/Destructors 
Model::Model()
{
    this->initLinks();
    // this->initMeshes();
}

Model::~Model()
{

    for (auto*& i:this->links)
    {
        delete i;
    }
}

// Public functions
void Model::render(Shader* shader)
{
    // use program
    shader->use();
    

    for (auto& i : this->meshes)
    {
        i->render(shader);
    }
}