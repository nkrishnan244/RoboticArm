#ifndef MODEL_HEADER
#define MODEL_HEADER

#include <vector>
#include "cylinder.hpp"
#include "mesh.hpp"

class Model
{
private:
    // Parts of the model
    std::vector<Mesh*> meshes; 

    // Initializers
    void initLinks();
    void initMeshes();

public:
    // this will become private
    std::vector<Cylinder*> links; 

    // Constructors/Destructors
    Model();
    ~Model();

    // Accessors

    // Modifiers

    // Public Functions
    void render(Shader* shader);
};

#endif