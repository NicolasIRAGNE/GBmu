#version 330

in vec2 textCoord;

uniform usampler2D text;

out vec4 fragColor;

void main()
{
    vec4 colorPalette[20] = vec4[20](
        vec4(0.86f, 0.79f, 0.62f, 1.f),
        vec4(0.67f, 0.55f, 0.06f, 1.f),
        vec4(0.38f, 0.19f, 0.19f, 1.f),
        vec4(0.22f, 0.06f, 0.06f, 1.f),
        vec4(0.00f, 0.00f, 0.00f, 1.f),
        
        // DEBUG PALETTE BLUE
        vec4(0.00f, 0.00f, 1.00f, 1.f),
        vec4(0.00f, 0.00f, 0.80f, 1.f),
        vec4(0.00f, 0.00f, 0.60f, 1.f),
        vec4(0.00f, 0.00f, 0.40f, 1.f),
        vec4(0.00f, 0.00f, 0.00f, 1.f),
        
        // DEBUG PALETTE RED
        vec4(1.00f, 0.00f, 0.00f, 1.f),
        vec4(0.80f, 0.00f, 0.00f, 1.f),
        vec4(0.60f, 0.00f, 0.00f, 1.f),
        vec4(0.40f, 0.00f, 0.00f, 1.f),
        vec4(0.00f, 0.00f, 0.00f, 1.f),

        // DEBUG PALETTE GREEN
        vec4(0.00f, 1.00f, 0.00f, 1.f),
        vec4(0.00f, 0.80f, 0.00f, 1.f),
        vec4(0.00f, 0.60f, 0.00f, 1.f),
        vec4(0.00f, 0.40f, 0.00f, 1.f),
        vec4(0.00f, 0.00f, 0.00f, 1.f));

    uint index = texture(text, textCoord).r;
    fragColor = colorPalette[index];
}
