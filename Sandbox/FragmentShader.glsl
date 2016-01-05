#version 140

in vec3 fNormal;
in vec2 fUV;
in vec3 lightDirection;
in vec3 cameraDirection;

out vec4 fColor;

uniform vec4 objectColor;
uniform sampler2D objectTexture;

void main()
{
    float brightness = max(dot(lightDirection, fNormal), 0);
    float sh = 50;
    float s = pow(max(dot(reflect(-lightDirection, fNormal), cameraDirection), 0), sh/4);
    vec4 color = texture(objectTexture, fUV)*objectColor;
    fColor = vec4(0.1f, 0.1f, 0.1f, 1.f)*color + color*brightness + vec4(s, s, s, 1.f);
}