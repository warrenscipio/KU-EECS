// hello.c++: A "Hello, OpenGL" program that draws a triangle
// This is a standalone version that does not make use of our MVC framework.

#include <iostream>
#include <stdlib.h>
#include "GLFW/glfw3.h"
#include "ShaderIF.h"

GLFWwindow* theWindow;
GLuint shaderProgram;
GLuint vao[1];

void createWindowAndRC()
{
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	theWindow = glfwCreateWindow(400, 400, "Hello, OpenGL", NULL, NULL);
	if (theWindow == NULL)
	{
		std::cerr << "Could not create a 4.3 OpenGL Rendering context.\n";
		exit(1);
	}
	glfwMakeContextCurrent(theWindow);
}

void handleDisplay(GLFWwindow* window)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);

	glBindVertexArray(vao[0]); // Make our VAO-VBO "active"
	// Starting at location 0 in the VBO, use 3 vertices to draw a triangle:
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glfwSwapBuffers(window);
}

void initModelGeometry()
{
	shaderProgram = ShaderIF::initShader("hello.vsh", "hello.fsh");
	float triangleVertices[3][2] =
	{
		{ -0.75, -0.75 }, { 0.75, -0.75 }, { 0.0, 0.75 }
	};

	glGenVertexArrays(1, vao); // get a new, previously unused VAO name
	glBindVertexArray(vao[0]); // (initialize it and) make it active

	GLuint vbo[1];
	glGenBuffers(1, vbo); // get a new, previously unused VBO name
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // (initialize it and) make it active

	// Allocate space for AND copy the CPU data in "triangleVertices" to the VBO on the GPU:
	int numBytesInBuffer = 3 * 2 * sizeof(float); // 3 points; 2 coords each; float
	glBufferData(GL_ARRAY_BUFFER, numBytesInBuffer, triangleVertices, GL_STATIC_DRAW);

	int coordinateLocation = 0; // See "layout" in hello.vsh
	glVertexAttribPointer(coordinateLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(coordinateLocation);
}

void run()
{
	while (!glfwWindowShouldClose(theWindow))
	{
		glfwWaitEvents();
		handleDisplay(theWindow);
	}
	glfwDestroyWindow(theWindow);
}

int main(int argc, char* argv[])
{
	glfwInit();          // 0. Initialize GLFW window system
	createWindowAndRC(); // 1. Create window and Rendering Context (RC)
	initModelGeometry(); // 2. Create and send geometry of model to GPU
	run();               // 3. Hand off to window manager to monitor events

	return 0;
}
