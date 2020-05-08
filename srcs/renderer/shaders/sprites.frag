#version 330

uniform sampler2D tex;

uniform vec4 colors1[4];
uniform vec4 colors2[4];

in vec2 vPosInTile;
in float fTileIndex;
in float fAttr;

out vec4 fragColor;

uint GetValueAt(uint addr)
{
    float x = float(addr % 128u) / 128.f;
    float y = float(addr / 128u) / 64.f;

    float octet = texture(tex, vec2(x, y)).r;
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
    
	if ((uint(fAttr) & 16u) != 0u) {
        return colors2[colorIndex];
    }
    
    return colors1[colorIndex];
}

void main()
{
    uvec2 pixelPosInTile = uvec2(vPosInTile);
    uint tileIndex = uint(fTileIndex);

	 fragColor = GetColorFromTileIndex(tileIndex, pixelPosInTile);
}
