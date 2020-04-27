#version 330

in vec2 in_position;
in vec4 in_color;
out vec2 position;
out vec4 color;

void main() {
    position = in_position;
    gl_Position = vec4(in_position.x, in_position.y, 0.0, 1.0);
    color = in_color;
}