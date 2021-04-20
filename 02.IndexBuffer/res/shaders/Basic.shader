#shader vertex
#version 330 core
layout(location = 0) in vec4 position;

void main()
{
   gl_Position = position;
};

#shader fragment
#version 330 core

out vec4 fragmentColor;
void main()
{
    fragmentColor = vec4(0.0, 0.7, 0.7, 0.1);
};