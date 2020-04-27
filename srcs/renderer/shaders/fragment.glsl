#version 330

uniform sampler2D tex;

in vec2 vTexCoord;

out vec4 fragColor;

uint GetValueAt(uint addr)
{
    float x = float(addr % 128u) / 128.f;
    float y = float(addr / 64u) / 64.f;

    float octet = texture2D(tex, vec2(x, y)).r;
    uint ret = uint(octet * 255.f);

    return ret;
}

void main()
{
    uint value = GetValueAt(128u);

    float color = float(value) / 255.f;

    fragColor = vec4(color, color, color, 1.f);
}