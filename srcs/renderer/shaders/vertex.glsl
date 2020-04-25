#version 330

in vec2 inVertex;
in vec2 inTexCoord;

out vec2 vTexCoord;

void main() {
    gl_Position = vec4(inVertex.x, inVertex.y, 0.0, 1.0);
    vTexCoord = inTexCoord;
}