#version 140

in vec3 vPosition;
in vec3 vNormal;
in vec2 vUV;

out vec3 fNormal;
out vec2 fUV;

uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;

void main()
{
    gl_Position = mvpMatrix * vec4(vPosition, 1.0);
    fNormal = normalize(normalMatrix * vNormal);
    fUV = vUV;
}