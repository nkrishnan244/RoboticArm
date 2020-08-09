#version 450

layout (location = 0) in vec3 vertex_position;

out vec3 vs_color; 

void main()
{
    vs_color = vec3(1.f, 0.f, 0.f);
    gl_Position = vec4(vertex_position, 1.f);
}

