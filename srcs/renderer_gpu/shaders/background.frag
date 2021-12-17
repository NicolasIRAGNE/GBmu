#version 330

layout(std140) uniform staticInfos
{
    float windowWidth;
    float windowHeight;
};

layout(std140) uniform dynamicInfos
{
    float timestamp;
};

struct Lcd {
    uint lcdc;
    int scx;
    int scy;
    int wx;
    int wy;
};

layout(std140) uniform lcd
{
    uvec4 lcdArray[144 * 5 / 4];
};

layout(std140) uniform vram
{
    uvec4 data[8192 / 16];
};

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

Lcd GetLcd(uint line)
{
    uint index = line * 5u / 4u;
    uint offset = line * 5u % 4u;

    Lcd lcd;
    lcd.lcdc = lcdArray[index + ((offset + 0u) / 4u)][(offset + 0u) % 4u];
    lcd.scx = int(lcdArray[index + ((offset + 1u) / 4u)][(offset + 1u) % 4u]);
    lcd.scy = int(lcdArray[index + ((offset + 2u) / 4u)][(offset + 2u) % 4u]);
    lcd.wx = int(lcdArray[index + ((offset + 3u) / 4u)][(offset + 3u) % 4u]);
    lcd.wy = int(lcdArray[index + ((offset + 4u) / 4u)][(offset + 4u) % 4u]);

    return lcd;
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

    gl_FragDepth = 0.5f;
    if (colorIndex == 0u) {
        gl_FragDepth = 0.9f;
    }

    return colors[colorIndex];
}

void main()
{
    uvec2 pixelPos = uvec2(gl_FragCoord.x, 144.f - gl_FragCoord.y);
    uint line = 144u - uint(gl_FragCoord.y) - 2u;
    pixelPos = (pixelPos + uvec2(GetLcd(line).scx, GetLcd(line).scy)) % 256u;

    uvec2 tilePos = pixelPos / 8u;
    uvec2 pixelPosInTile = pixelPos % 8u;
    
	uint offset = 0x1800u;
	if ((GetLcd(line).lcdc & 8u) != 0u)
		offset = 0x1C00u;

	uint tileIndex = GetValueAt(offset + tilePos.y * 32u + tilePos.x);
	if (((GetLcd(line).lcdc & 16u) == 0u) && (tileIndex + 0x100u < 256u + 128u)) {
		tileIndex = tileIndex + 0x100u;
    }

    if ((GetLcd(line).lcdc & 1u) == 0u) {
        fragColor = vec4(0.f, 0.f, 0.f, 1.f);
    }
    else {
        // fragColor = vec4(0.f, 0.f, 0.f, 1.f);
        fragColor = GetColorFromTileIndex(tileIndex, pixelPosInTile);
    }

}
