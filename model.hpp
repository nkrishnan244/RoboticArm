#ifndef MODEL_HEADER
#define MODEL_HEADER

#include <vector>
#include "cylinder.hpp"

class Model
{
private:
    // Parts of the model
    std::vector<Cylinder> links; 

public:
    Model();
    ~Model();
};

#endif