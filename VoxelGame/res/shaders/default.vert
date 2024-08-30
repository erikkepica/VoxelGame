#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 normal;


uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}