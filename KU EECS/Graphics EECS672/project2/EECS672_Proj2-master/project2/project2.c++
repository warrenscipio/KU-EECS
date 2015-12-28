// project2.c++: Starter for EECS 672 Project 2

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Controller.h"
#include "Board.h"
#include "Pawn.h"
#include "King.h"

#define WHITE 1
#define BLACK 0
#define BORDER 2
#define TEST 3
#define FLIP( x ) do{ (x) ^= 1; } while(0)

int main(int argc, char* argv[])
{
	// One-time initialization of the glut
	glutInit(&argc, argv);

	Controller c("Your move.", GLUT_DEPTH | GLUT_DOUBLE);

	// create your scene, adding things to the Controller....
	vec3 location =          { -50.0f, -0.5f, 0.0f };
	vec3 whitepawnlocation = { -17.5f,  0.0f, 62.5f };
	vec3 blackpawnlocation = { -7.5f,  0.0f, 12.5f };
	vec3 whitekinglocation = { -38.25f,  0.0f, 12.0f };
	vec3 blackkinglocation = { -18.75f,  0.0f, 81.75f };
	vec3 spherelocation = { 2.0f, 2.0f, 2.0f };

	c.addModel( new Board( location, 10.0f, 0.5f ) );
	c.addModel( new Pawn( WHITE, whitepawnlocation ) );
	c.addModel( new Pawn( BLACK, blackpawnlocation ) );
	c.addModel( new King( WHITE, whitekinglocation ) );
	c.addModel( new King( BLACK, blackkinglocation ) );

	glClearColor(1.0, 1.0, 1.0, 1.0);

	// Off to the glut event handling loop:
	glutMainLoop();

	return 0;
}

