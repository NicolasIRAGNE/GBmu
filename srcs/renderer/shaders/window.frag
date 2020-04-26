#version 330

uniform sampler2D tex;

uniform uint wx;
uniform uint wy;
uniform uint lcdc;

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

vec4 GetColorFromTileIndex(uint index, uvec2 posInTile)
{   
    uint msb = GetValueAt(index * 16u + posInTile.y * 2u);
    uint lsb = GetValueAt(index * 16u + posInTile.y * 2u + 1u);

    uint posInByte = (7u - posInTile.x);
    uint bit = 1u << posInByte;
    uint colorIndex = ((msb & bit) << (posInByte + 1u))
                    | ((lsb & bit) << posInByte);

    colorIndex = colorIndex >> (posInByte * 2u);

    return monochromePalette[colorIndex];
}

void main()
{
    uvec2 pixelPos = uvec2(gl_FragCoord.x / 2.f, 144.f - gl_FragCoord.y / 2.f);
    pixelPos = pixelPos - uvec2(wx, wy);

    uvec2 tilePos = pixelPos / 8u;
    uvec2 pixelPosInTile = pixelPos % 8u;
    
	uint tileIndex = GetValueAt(0x1800u + tilePos.y * 32u + tilePos.x);
	if (((lcdc & 16u) == 0u) && (tileIndex + 0x100u < 256u + 128u)) {
		tileIndex = tileIndex + 0x100u;
    }
    
    fragColor = GetColorFromTileIndex(tileIndex, pixelPosInTile);
}