#version 140

in vec3 vPosition;
in vec3 vNormal;
in vec2 vUV;

out vec3 fNormal;
out vec2 fUV;
out vec3 lightDirection;

uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;

uniform vec3 lightPosition;

void main()
{
    vec4 pos = mvpMatrix * vec4(vPosition, 1.0);
    lightDirection = normalize(lightPosition - pos.xyz);
    fNormal = normalize(normalMatrix * vNormal);
    fUV = vUV;
    gl_Position = pos;
}