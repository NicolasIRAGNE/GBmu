#version 330

layout(std140) uniform staticInfos
{
    float windowWidth;
    float windowHeight;
};

layout(std140) uniform vram
{
    uvec4 data[8192 / 16];
};  

uniform vec4 colors1[4];
uniform vec4 colors2[4];

in vec2 vPosInTile;
in float fTileIndex;
in float fAttr;

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
    
	if ((uint(fAttr) & 16u) != 0u) {
        return colors2[colorIndex];
    }
    
    return colors1[colorIndex];
}

void main()
{
    gl_FragDepth = 0.1f;
    if ((uint(fAttr) & 128u) != 0u) {
        gl_FragDepth = 0.6f;
    }

    uvec2 pixelPosInTile = uvec2(vPosInTile);
    uint tileIndex = uint(fTileIndex);

    fragColor = GetColorFromTileIndex(tileIndex, pixelPosInTile);
}
