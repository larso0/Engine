#version 140

in vec3 fNormal;
in vec2 fUV;

out vec4 fColor;

void main()
{
    fColor = vec4(fNormal, 1.0);
}