#version 450
layout (location = 0) in vec2 aVertex;
layout (location = 2) in mat4 aModel;
layout (location = 6) in uint aTextureIndex;

layout (std140) uniform cameraData
{ 
	mat4 camera_proj;
};

out vec2 oUvs;
flat out uint oTextureIndex;

void main(void)
{
    oUvs = aVertex;
    oTextureIndex = aTextureIndex;
    gl_Position = camera_proj * aModel * vec4( aVertex, 0.0, 1.0 );
}