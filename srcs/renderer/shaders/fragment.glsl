#version 330

struct Infos {
    uint scx;
    uint scy;
    uint lcdc;
};

uniform sampler2D tex;
uniform struct Infos infos;

in vec2 position;

out vec4 fragColor;

vec4 monochromePalette[4] = vec4[](
    vec4(0.8f, 0.8f, 0.8f, 1.f),
    vec4(0.5f, 0.5f, 0.5f, 1.f),
    vec4(0.3f, 0.3f, 0.3f, 1.f),
    vec4(0.1f, 0.1f, 0.1f, 1.f)
);

uint GetValueAt(uint addr)
{
    float x = float(addr % 128u) / 128.f;
    float y = float(addr / 128u) / 64.f;

    float octet = texture2D(tex, vec2(x, y)).r;
    uint ret = uint(octet * 255.f);

    return ret;
}

void main()
{
    uvec2 pixelPos = uvec2(gl_FragCoord.x / 2.f, 144.f - gl_FragCoord.y / 2.f);
    pixelPos = pixelPos + uvec2(infos.scx, infos.scy);

    uvec2 tilePos = pixelPos / 8u;
    uvec2 pixelPosInTile = pixelPos % 8u;
    
	uint tileIndex = GetValueAt(0x1800u + tilePos.y * 32u + tilePos.x);
	if (((infos.lcdc & 16u) == 0u) && (tileIndex + 0x100u < 256u + 128u)) {
		tileIndex = tileIndex + 0x100u;
    }
    
    uint msb = GetValueAt(tileIndex * 16u + pixelPosInTile.y * 2u);
    uint lsb = GetValueAt(tileIndex * 16u + pixelPosInTile.y * 2u + 1u);

    uint posInByte = (7u - pixelPosInTile.x);
    uint bit = 1u << posInByte;
    uint colorIndex = ((msb & bit) << (posInByte + 1u))
                    | ((lsb & bit) << posInByte);

    colorIndex = colorIndex >> (posInByte * 2u);
    
    fragColor = monochromePalette[colorIndex];
}