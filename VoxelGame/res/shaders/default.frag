#version 330 core

out vec4 FragColor;

in vec2 uv;
in vec3 normal;
in vec3 fragPos;

uniform sampler2D ourTexture;

uniform vec3 lightPos; 
uniform vec3 lightColor;

void main()
{
    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
            
    vec3 result = clamp(ambient + diffuse,0,1) * texture(ourTexture, uv).rgb;
    FragColor = vec4(result, 1.0);
    FragColor = vec4(uv,1.0f, 1.0);
}