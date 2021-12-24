#version 330

in vec2 textCoord;

uniform sampler2D text;

out vec4 fragColor;

void main()
{
    fragColor = texture(text, textCoord);
}
