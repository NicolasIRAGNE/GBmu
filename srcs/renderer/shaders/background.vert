#version 330

in vec2 inVertex;

void main() {
    gl_Position = vec4(inVertex, 0.f, 1.f);
}