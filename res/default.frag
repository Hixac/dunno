#version 330 core

out vec4 frag_color;

//in vec4 vert_color;
in vec2 vert_tex;

uniform sampler2D tex;

void main()
{
  frag_color = texture(tex, vert_tex);
} 
