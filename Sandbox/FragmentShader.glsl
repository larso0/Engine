#version 140

in vec3 fNormal;
in vec2 fUV;
in vec3 lightDirection;

out vec4 fColor;

uniform vec4 objectColor;

void main()
{
    float dummy = fUV.x / fUV.x;
    float brightness = dot(lightDirection, fNormal) * dummy;
    fColor = vec4(0.1f, 0.1f, 0.1f, 1.f) + objectColor*brightness;
}