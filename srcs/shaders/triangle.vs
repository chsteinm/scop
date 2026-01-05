#version 330 core

layout (location = 0) in vec3 aPos;
// layout (location = 1) in vec3 aColor;
uniform vec2 uOffset;
out vec4 Color;
void main()
{
    Color = vec4(aPos + vec3(uOffset, 0.0), 1.0);
    gl_Position = vec4(aPos + vec3(uOffset, 0.0), 1.0);
}