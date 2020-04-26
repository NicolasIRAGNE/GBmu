#version 330

in vec4 inVertex;

out vec2 vPosInTile;
out float fTileIndex;
out float fAttr;

vec2 posInTile[6] = vec2[](
    vec2(0.f, 0.f),
    vec2(0.f, 8.f),
    vec2(8.f, 0.f),
    vec2(0.f, 8.f),
    vec2(8.f, 0.f),
    vec2(8.f, 8.f));

void main() {
    gl_Position = vec4(inVertex.xy, 0.f, 1.f);

    vPosInTile = posInTile[gl_VertexID % 6];
    fTileIndex = inVertex.z;
    fAttr = inVertex.w;
}