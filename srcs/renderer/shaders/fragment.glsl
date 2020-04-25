#version 330

uniform sampler2D tex;

in vec2 vTexCoord;

void main()
{
    vec4 color = texture2D(tex, vTexCoord);
    gl_FragColor = color;
}