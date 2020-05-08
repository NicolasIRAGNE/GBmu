#version 330

layout(std140) uniform globalInfos
{
    float windowWidth;
    float windowHeight;
};

layout(std140) uniform vram
{
    uvec4 data[8192 / 16];
};  

uniform int wx;
uniform int wy;
uniform uint lcdc;

uniform vec4 colors[4];

out vec4 fragColor;

uint GetValueAt(uint addr)
{
    uvec4 data16B = data[addr / 16u];
    uint data4B = data16B[(addr % 16u) / 4u];
    uint offset = (addr % 4u) * 8u;
    uint data1B = (data4B & (0xffu << offset)) >> offset;
    return data1B;
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

    return colors[colorIndex];
}

void main()
{
    uvec2 pixelPos = uvec2(gl_FragCoord.x / windowWidth * 160.f, 144.f - (gl_FragCoord.y / windowHeight * 144.f));
    pixelPos = pixelPos - uvec2(wx, wy);

    uvec2 tilePos = pixelPos / 8u;
    uvec2 pixelPosInTile = pixelPos % 8u;
    
	uint offset = 0x1800u;
	if ((lcdc & 64u) != 0u)
		offset = 0x1C00u;
	uint tileIndex = GetValueAt(offset + tilePos.y * 32u + tilePos.x);
	if (((lcdc & 16u) == 0u) && (tileIndex + 0x100u < 256u + 128u)) {
		tileIndex = tileIndex + 0x100u;
    }
    
    fragColor = GetColorFromTileIndex(tileIndex, pixelPosInTile);
}
