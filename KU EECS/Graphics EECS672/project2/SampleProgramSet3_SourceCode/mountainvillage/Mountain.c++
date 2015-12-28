// Mountain.c++ - concrete subclass of ModelView that represents a Mountain

#include <iostream>
#include <cmath>

#include "Mountain.h"
#include "ShaderIF.h"

typedef float vec2[2];

ShaderIF* Mountain::shaderIF = NULL;
int Mountain::numInstances = 0;
GLuint Mountain::shaderProgram = 0;
GLint Mountain::pvaLoc_mcPosition = -2;
GLint Mountain::pvaLoc_heightFraction = -2;
GLint Mountain::ppuLoc_scaleTrans = -2;
GLint Mountain::ppuLoc_whichMountain = -2;

Mountain::Mountain(double xMinIn, double xMaxIn, double yMin, double sin_yMax, double cos_yMax,
		double cos_bIn, double cos_cIn, double sin_bIn, double sin_cIn,
		int numSamplePointsIn) :
	xMin(xMinIn), xMax(xMaxIn), cos_b(cos_bIn), cos_c(cos_cIn), sin_b(sin_bIn), sin_c(sin_cIn),
	numSamplePoints(numSamplePointsIn)
{
	if (Mountain::shaderProgram == 0)
	{
		// The first time an instance of this class is generated, create the common shader program:
		Mountain::shaderIF = new ShaderIF("Mountain.vsh", "Mountain.fsh");
		Mountain::shaderProgram = shaderIF->getShaderPgmID();
		fetchGLSLVariableLocations();
	}

	// Now do instance-specific initialization:
	validateData(yMin, sin_yMax, cos_yMax);
	defineModel();
	Mountain::numInstances++;
}

Mountain::~Mountain()
{
	glDeleteBuffers(2, vbo);
	glDeleteVertexArrays(1, vao);
	if (--Mountain::numInstances == 0)
	{
		Mountain::shaderIF->destroy();
		delete Mountain::shaderIF;
		Mountain::shaderIF = NULL;
		Mountain::shaderProgram = 0;
	}
}

void Mountain::defineModel()
{
	vao[0] = 0; // delete this line and the following "cout" when completing the exercise
	std::cout << "Mountain::defineModel: Implementation left as exercise.\n";
}

void Mountain::fetchGLSLVariableLocations()
{
	if (Mountain::shaderProgram > 0)
	{
		Mountain::pvaLoc_mcPosition = pvAttribLocation(shaderProgram, "mcPosition");
		Mountain::pvaLoc_heightFraction = pvAttribLocation(shaderProgram, "heightFraction");
		Mountain::ppuLoc_scaleTrans = ppUniformLocation(shaderProgram, "scaleTrans");
		Mountain::ppuLoc_whichMountain = ppUniformLocation(shaderProgram, "whichMountain");
	}
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Mountain::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xMin;
	xyzLimits[1] = xMax;
	double dy_sin = sin_d - sin_a;
	double dy_cos = cos_d - cos_a;
	if (dy_sin < dy_cos)
		xyzLimits[2] = dy_sin;
	else
		xyzLimits[2] = dy_cos;
	dy_sin = sin_d + sin_a;
	dy_cos = cos_d + cos_a;
	if (dy_sin > dy_cos)
		xyzLimits[3] = dy_sin;
	else
		xyzLimits[3] = dy_cos;
	xyzLimits[4] = -1.0; xyzLimits[5] = 1.0; // (zmin, zmax) (really 0..0)
}

void Mountain::render()
{
	// save the current GLSL program in use
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	// draw the triangles using our vertex and fragment shaders
	glUseProgram(shaderProgram);

	// define the mapping from MC to -1..+1 Logical Device Space:
	float scaleTrans[4];
	compute2DScaleTrans(scaleTrans);
	glUniform4fv(Mountain::ppuLoc_scaleTrans, 1, scaleTrans);

	glBindVertexArray(vao[0]);
	// draw background mountain
	glUniform1i(Mountain::ppuLoc_whichMountain, 0); // '0' means background
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 2*numSamplePoints);
	// then draw foreground mountain
	glUniform1i(Mountain::ppuLoc_whichMountain, 1); // '1' means foreground
	glDrawArrays(GL_TRIANGLE_STRIP, 2*numSamplePoints, 2*numSamplePoints);
	// restore the previous program
	glUseProgram(pgm);
}

void Mountain::validateData(double yMin, double sin_yMax, double cos_yMax)
{
	// simplistic test and fix; not very robust, but OK for now
	if (sin_yMax <= yMin)
		sin_yMax = yMin + 1.0;
	if (cos_yMax <= yMin)
		cos_yMax = yMin + 1.0;
	// compute the 'a' and 'd' constants so that the cos and sin curves observe
	// the requested y min and max. The relevant equations:
	// yMin = -a + d
	// yMax =  a + d
	// Solving:
	cos_d = (yMin + cos_yMax) / 2.0;
	cos_a = cos_yMax - cos_d;
	sin_d = (yMin + sin_yMax) / 2.0;
	sin_a = sin_yMax - sin_d;
}
