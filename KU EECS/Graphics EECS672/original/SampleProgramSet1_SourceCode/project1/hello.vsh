#version 410 core

layout (location = 0) in vec2 vertexCoordinates;

void main()
{
	gl_Position = vec4(vertexCoordinates, 0, 1);
}

