#version 140

in vec3 vPosition;
in vec3 vNormal;
in vec2 vUV;

out vec3 fNormal;
out vec2 fUV;
out vec3 lightDirection;

uniform mat4 modelMatrix;
uniform mat4 viewProjectionMatrix;
uniform vec4 orientationQuaternion;

uniform vec3 lightPosition;

vec3 quatTransform( vec4 q, vec3 v )
{ 
    return v + 2.0*cross(cross(v, q.xyz ) + q.w*v, q.xyz);
}

void main()
{
    vec4 pos = modelMatrix * vec4(vPosition, 1);
    lightDirection = normalize(lightPosition - pos.xyz);
    fNormal = quatTransform(orientationQuaternion, vNormal);
    fUV = vUV;
    gl_Position = viewProjectionMatrix * pos;
}