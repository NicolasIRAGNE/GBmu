#version 330

in vec2 inVertex;
in vec2 inTextCoord;

out vec2 textCoord;

void main() {
    textCoord = inTextCoord;
	gl_Position = vec4(inVertex.xy, 0.f, 1.f);
}