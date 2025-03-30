#version 330 core
layout (location = 0) in vec3 pos;
//layout (location = 1) in vec3 col;
layout (location = 1) in vec2 tex;

out vec4 vert_color; // fragment in info
out vec2 vert_tex;   // fragment in info

uniform mat4 transform;

void main()
{
  gl_Position = transform * vec4(pos, 1.0f);
  //vert_color = vec4(col, 1.0);
  vert_tex = tex;
}
