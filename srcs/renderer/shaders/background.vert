#version 330

in vec2 inVertex;

uniform uint line;

void main() {
	float line_size = 2.f / 144.f;
	float y = (inVertex.y + 1.f) / 144.f;
	y = y + float(line) * line_size;
	y -= 1.f;
	y *= -1.f;
	gl_Position = vec4(inVertex.x, y, 0.f, 1.f);
}