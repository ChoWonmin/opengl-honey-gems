#shader vertex
#version 330 core
layout(location = 0) in vec4 position;

void main()
{
   gl_Position = position;
};

#shader geometry
#version 330 core

layout (points) in;
layout (line_strip, max_vertices = 256) out;
out vec3 color;

void main()
{
   const float PI = 3.1415926538;
   float length = gl_in[0].gl_Position.w;
   const int leafNum = 5;
   vec3 color1 = vec3(1.0, 0.93, 0.67);
   vec3 color2 = vec3(0.71, 0.53, 0.69);

   for (int i=0; i<leafNum; i++)
   {

       gl_Position = vec4(gl_in[0].gl_Position.xyz, 1.0);
       EmitVertex();

       float theta = 2*PI * i / float(leafNum);
       vec3 pos = gl_in[0].gl_Position.xyz + vec3(length * cos(theta), length * sin(theta), 0.0);
       gl_Position = vec4(pos.xyz, 1.0);

       float interpolation = length + 0.3;
       color = mix(color1, color2, vec3(interpolation, interpolation, interpolation));
       EmitVertex();

   }

   EndPrimitive();
};

#shader fragment
#version 330 core
in vec3 color;
out vec4 fragmentColor;
void main()
{
fragmentColor = vec4(color, 0.1);
};