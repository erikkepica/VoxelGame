#version 330 core

out vec4 FragColor;

in vec2 uv;
in vec3 normal;

void main()
{
    FragColor = vec4(uv, 0.f, 1.f);
}