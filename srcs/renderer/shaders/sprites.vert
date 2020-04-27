#version 330

in vec4 inVertex;
in vec2 posInTile;

out vec2 vPosInTile;
out float fTileIndex;
out float fAttr;

void main() {
    gl_Position = vec4(inVertex.xy, 0.f, 1.f);

    vPosInTile = posInTile;
    fTileIndex = inVertex.z;
    fAttr = inVertex.w;
}