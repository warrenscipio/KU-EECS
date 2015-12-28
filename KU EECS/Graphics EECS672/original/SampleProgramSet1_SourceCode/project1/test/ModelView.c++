// ModelView.c++ - a basic combined Model and View for OpenGL

#include <iostream>

#include "ModelView.h"
#include "Controller.h"
#include "ShaderIF.h"

ShaderIF* ModelView::shaderIF = NULL;
int ModelView::numInstances = 0;
GLuint ModelView::shaderProgram = 0;
GLint ModelView::ppuLoc_color = -2; // uniform variable (per-primitive)
GLint ModelView::ppuLoc_scaleTrans = -2;
GLint ModelView::pvaLoc_mcPosition = -2;



double ModelView::mcRegionOfInterest[6] = { -1.0, 1.0, -1.0, 1.0, -1.0, 1.0 };


ModelView::ModelView()
{
	if (ModelView::shaderProgram == 0)
	{
		// Create the common shader program:
		ModelView::shaderIF = new ShaderIF("project1.vsh", "project1.fsh");
		ModelView::shaderProgram = shaderIF->getShaderPgmID();
		fetchGLSLVariableLocations();
	}

	// TODO: define and call method(s) to initialize your model and send data to GPU

	// define vertex coordinates for the two triangles
	float vertexPositions[26][2] =
	{
		{0.0, 120.0}, {242.0, 120.0}, {0.0, 120.0},
		{0.0, 105.0}, {242.0 , 105.0}, {0.0, 105},
		{0.0, 90.0}, {242.0, 90.0}, {0.0, 90.0},
		{0.0, 75.0}, {242.0, 75.0}, {0.0, 75.0},
		{0.0, 60.0}, {242.0, 60.0}, {0.0, 60.0},
		{0.0, 45.0}, {242.0, 45.0}, {0.0, 45.0},
		{0.0, 30.0}, {242.0, 30.0}, {0.0, 30.0},
		{0.0, 15.0}, {242.0, 15.0}, {0.0, 15.0},
		{0.0, 0.0}, {242.0, 0.0}

	};


	useColor[0][0] = 0.5; useColor[0][1] = 0.5; useColor[0][2] = 0.5;
	drawInBlack[0] = false;
	visible[0] = true;


	// Send the actual geometry to the GPU:

	glGenVertexArrays(1, vao);


	glGenBuffers(1, vbo);

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			std::cout << vertexPositions[i][j] << " " << vertexPositions[i][j+1] << std::endl;
		}
	}

	for (int i=0 ; i<1 ; i++)
	{
		// (initialize and) make active the i-th VAO
		glBindVertexArray(vao[i]);
		// (initialize and) make active the corresponding i-th vertex buffer
		glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);

		// Allocate space for AND copy the vertex data for the i-th triangle to the GPU buffer
		int numBytesInBuffer = 26 * 2 * sizeof(float);
		glBufferData(GL_ARRAY_BUFFER, numBytesInBuffer, vertexPositions[i], GL_STATIC_DRAW);
		glVertexAttribPointer(ModelView::pvaLoc_mcPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(ModelView::pvaLoc_mcPosition);
	}

	ModelView::numInstances++;
}

ModelView::ModelView(float vertArr[][2]){

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			std::cout << vertArr[i][j] << " " << vertArr[i][j+1] << std::endl;
		}
	}


	if (ModelView::shaderProgram == 0)
	{
		// Create the common shader program:
		ModelView::shaderIF = new ShaderIF("project1.vsh", "project1.fsh");
		ModelView::shaderProgram = shaderIF->getShaderPgmID();
		fetchGLSLVariableLocations();
	}
	

	useColor[0][0] = (double) rand() / (RAND_MAX); useColor[0][1] = (double) rand() / (RAND_MAX); useColor[0][2] = (double) rand() / (RAND_MAX);
	
	drawInBlack[0] = false;

	visible[0] = true;

	glGenVertexArrays(1, vao);
	// Create TWO new, previously unused names for the coordinate buffers (again, one
	// for each of the two triangles. Recall each buffer object will be associated with
	// a VAO.

	glGenBuffers(1, vbo);

	for (int i=0 ; i<1 ; i++)
	{
		// (initialize and) make active the i-th VAO
		glBindVertexArray(vao[i]);
		// (initialize and) make active the corresponding i-th vertex buffer
		glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);

		// Allocate space for AND copy the vertex data for the i-th triangle to the GPU buffer
		int numBytesInBuffer = 121 * 2 * sizeof(float);
		glBufferData(GL_ARRAY_BUFFER, numBytesInBuffer, vertArr[i], GL_STATIC_DRAW);
		glVertexAttribPointer(ModelView::pvaLoc_mcPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(ModelView::pvaLoc_mcPosition);
	}

	ModelView::numInstances++;

}

ModelView::~ModelView()
{
	// TODO: delete the vertex array objects and buffers here

	if (--numInstances == 0)
	{
		ModelView::shaderIF->destroy();
		delete ModelView::shaderIF;
		ModelView::shaderIF = NULL;
		ModelView::shaderProgram = 0;
	}
}

void ModelView::compute2DScaleTrans(float* scaleTransF) // CLASS METHOD
{
	// TODO: This code can be used as is, BUT be absolutely certain you
	//       understand everything about how it works.

	double xmin = mcRegionOfInterest[0];
	double xmax = mcRegionOfInterest[1];
	double ymin = mcRegionOfInterest[2];
	double ymax = mcRegionOfInterest[3];

	// If we wish to preserve aspect ratios, make "region of interest"
	// wider or taller to match the Controller's viewport aspect ratio.
	double vAR = Controller::getCurrentController()->getViewportAspectRatio();
	matchAspectRatio(xmin, xmax, ymin, ymax, vAR);

    // We are only concerned with the xy extents for now, hence we will
    // ignore mcRegionOfInterest[4] and mcRegionOfInterest[5].
    // Map the overall limits to the -1..+1 range expected by the OpenGL engine:
	double scaleTrans[4];
	linearMap(xmin, xmax, -1.0, 1.0, scaleTrans[0], scaleTrans[1]);
	linearMap(ymin, ymax, -1.0, 1.0, scaleTrans[2], scaleTrans[3]);
	for (int i=0 ; i<4 ; i++)
		scaleTransF[i] = static_cast<float>(scaleTrans[i]);
}

void ModelView::fetchGLSLVariableLocations()
{
	if (ModelView::shaderProgram > 0)
	{
		// TODO: Set GLSL variable locations here
		ModelView::ppuLoc_color = ppUniformLocation(shaderProgram, "color");
		ModelView::ppuLoc_scaleTrans = ppUniformLocation(shaderProgram, "scaleTrans");
		// "mc" in "mcPosition" refers to "model coordinates"
		ModelView::pvaLoc_mcPosition = pvAttribLocation(shaderProgram, "mcPosition");
	}
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void ModelView::getMCBoundingBox(double* xyzLimits) const
{
	// TODO:
	// Put this ModelView instance's min and max x, y, and z extents
	// into xyzLimits[0..5]. (-1 .. +1 is OK for z direction for 2D models)
	xyzLimits[0] =  -10.0; xyzLimits[1] =   300.0; // (xmin, xmax)
	xyzLimits[2] = -10.0; xyzLimits[3] = 100.0; // (ymin, ymax)
	xyzLimits[4] =  -1.0; xyzLimits[5] =   1.0; // (zmin, zmax) (really 0..0)
}

void ModelView::handleCommand(unsigned char key, double ldsX, double ldsY)
{
}

// linearMap determines the scale and translate parameters needed in
// order to map a value, f (fromMin <= f <= fromMax) to its corresponding
// value, t (toMin <= t <= toMax). Specifically: t = scale*f + trans.
void ModelView::linearMap(double fromMin, double fromMax, double toMin, double toMax,
					  double& scale, double& trans) // CLASS METHOD
{
	scale = (toMax - toMin) / (fromMax - fromMin);
	trans = toMin - scale*fromMin;
}

void ModelView::matchAspectRatio(double& xmin, double& xmax,
        double& ymin, double& ymax, double vAR)
{
	// TODO: This code can be used as is, BUT be absolutely certain you
	//       understand everything about how it works.

	double wHeight = ymax - ymin;
	double wWidth = xmax - xmin;
	double wAR = wHeight / wWidth;
	if (wAR > vAR)
	{
		// make window wider
		wWidth = wHeight / vAR;
		double xmid = 0.5 * (xmin + xmax);
		xmin = xmid - 0.5*wWidth;
		xmax = xmid + 0.5*wWidth;
	}
	else
	{
		// make window taller
		wHeight = wWidth * vAR;
		double ymid = 0.5 * (ymin + ymax);
		ymin = ymid - 0.5*wHeight;
		ymax = ymid + 0.5*wHeight;
	}
}

GLint ModelView::ppUniformLocation(GLuint glslProgram, const std::string& name)
{
	GLint loc = glGetUniformLocation(glslProgram, name.c_str());
	if (loc < 0)
		std::cerr << "Could not locate per-primitive uniform: '" << name << "'\n";
	return loc;
}

GLint ModelView::pvAttribLocation(GLuint glslProgram, const std::string& name)
{
	GLint loc = glGetAttribLocation(glslProgram, name.c_str());
	if (loc < 0)
		std::cerr << "Could not locate per-vertex attribute: '" << name << "'\n";
	return loc;
}

void ModelView::render() const
{
	// save the current GLSL program in use
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);

	// draw the triangles using our vertex and fragment shaders
	glUseProgram(shaderProgram);

	// TODO: set scaleTrans (and all other needed) uniform(s)
	float scaleTrans[4];
	compute2DScaleTrans(scaleTrans);
	glUniform4fv(ModelView::ppuLoc_scaleTrans, 1, scaleTrans);
	
	float black[] = { 0.0, 0.0, 0.0 };

	for (int i=0 ; i<1 ; i++)
	{
		if ((vao[i] == 0)  || // if it has been deleted
		    (!visible[i]))    // if it has been temporarily blanked
			continue;
		// set the desired triangle (primitive) color
		if (drawInBlack[i])
			glUniform3fv(ModelView::ppuLoc_color, 1, black);
		else
			glUniform3fv(ModelView::ppuLoc_color, 1, useColor[i]);

		// Bind the i-th triangle.
		// IMPORTANT NOTES:
		// Binding a VAO automatically binds all buffers associated with it. It also
		// effectively reestablishes all associated glVertexAttribPointer settings
		// as well as the associated gl[En|Dis]ableVertexAttribArray flags.
		glBindVertexArray(vao[i]);

		// Draw the i-th triangle.
		glDrawArrays(GL_LINE_STRIP, 0, 121);
	}
	// restore the previous program
	glUseProgram(pgm);
}

void ModelView::setMCRegionOfInterest(double xyz[6])
{
	for (int i=0 ; i<6 ; i++)
		mcRegionOfInterest[i] = xyz[i];
}
