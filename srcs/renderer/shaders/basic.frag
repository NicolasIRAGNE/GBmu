#version 330

in vec2 textCoord;

uniform usampler2D text;

out vec4 fragColor;

void main()
{
    vec4 colorPalette[5] = vec4[5](
        vec4(0.86f, 0.79f, 0.62f, 1.f),
        vec4(0.67f, 0.55f, 0.06f, 1.f),
        vec4(0.38f, 0.19f, 0.19f, 1.f),
        vec4(0.22f, 0.06f, 0.06f, 1.f),
        vec4(0.00f, 0.00f, 0.00f, 1.f));

    uint index = texture(text, textCoord).r;
    fragColor = colorPalette[index];
}
