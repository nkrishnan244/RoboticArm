#version 450

layout (location = 0) in vec3 vertex_position;

out vec3 vs_color; 

uniform mat3 ModelMatrix; 
uniform float Scale;

void main()
{
    mat3 model = ModelMatrix;
    vs_color = vec3(1.f, 0.f, 0.f);
    vec3 temp = model*vertex_position;
    temp.x = temp.x*Scale;
    temp.y = temp.y*Scale;
    temp.z = temp.z*Scale;
    gl_Position = vec4(temp, 1.f);
}

