#version 140

in vec3 fNormal;
in vec2 fUV;

out vec4 fColor;

void main()
{
    float dummy = fUV.x / fUV.x;
    fColor = vec4(fNormal, 1.0) + vec4(0.5f, 0.5f, 0.5f, 1.f)*dummy;
}