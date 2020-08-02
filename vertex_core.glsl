#version 450

layout (location == 0) in vec3 vertex_position;

out vec3 vs_position;

void main()
{
    vs_position = vertex_position;
}

