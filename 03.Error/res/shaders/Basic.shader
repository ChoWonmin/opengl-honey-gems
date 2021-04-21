#shader vertex
#version 330 core
layout(location = 0) in vec4 position;

void main()
{
   gl_Position = position;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 fragmentColor;

uniform vec4 u_Color;

void main()
{
    // fragmentColor = vec4(0.0, 0.7, 0.7, 0.1);
    fragmentColor = u_Color;
};