// ModelView.c++ - a basic combined Model and View for OpenGL

#include <iostream>

#include "ModelView.h"
#include "Controller.h"
#include "ShaderIF.h"

ShaderIF* ModelView::shaderIF = NULL;
int ModelView::numInstances = 0;
GLuint ModelView::shaderProgram = 0;
GLint ModelView::pvaLoc_mcPosition = -2;
GLint ModelView::ppuLoc_scaleTrans = -2;
GLint ModelView::ppuLoc_color = -2;


double ModelView::mcRegionOfInterest[6] = { -1.0, 1.0, -1.0, 1.0, -1.0, 1.0 };

//building the grid
ModelView::ModelView(float vertices[][2])
{
	if (ModelView::shaderProgram == 0)
	{
		// Create the common shader program:
		ModelView::shaderIF = new ShaderIF("project1.vsh", "project1.fsh");
		ModelView::shaderProgram = shaderIF->getShaderPgmID();
		fetchGLSLVariableLocations();
	}

	// TODO: define and call method(s) to initialize your model and send data to GPU
	//first color for grid

	useColor[0][0] = 0.7; useColor[0][1] = 0.7; useColor[0][2] = 0.7;

	glGenVertexArrays(1, vao); // get a new, previously unused VAO name
	glGenBuffers(1, vbo); // get a new, previously unused VBO name

	glBindVertexArray(vao[0]); // (initialize it and) make it active
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // (initialize it and) make it active

	int numBytesInBuffer = 26 * 2 * sizeof(float); //points; 2 coords each;

	glBufferData(GL_ARRAY_BUFFER, numBytesInBuffer, vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(ModelView::pvaLoc_mcPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(ModelView::pvaLoc_mcPosition);



	ModelView::numInstances++;
}

//building each line
ModelView::ModelView(float vertices[][2], int color)
{


	if (ModelView::shaderProgram == 0)
	{
		// Create the common shader program:

		ModelView::shaderIF = new ShaderIF("project1.vsh", "project1.fsh");
		ModelView::shaderProgram = shaderIF->getShaderPgmID();
		fetchGLSLVariableLocations();
	}

	// TODO: define and call method(s) to initialize your model and send data to GPU
	//first color aka grid

	//std::cout<<color<<std::endl;

	int saturation = 2;
	switch(color){
		case 1:
			useColor[0][0] = 0.192*saturation; useColor[0][1] = 0.300*saturation; useColor[0][2] = 0.404*saturation;//blue
			break;
		case 2:
			useColor[0][0] = 0.408*saturation; useColor[0][1] = 0.196*saturation; useColor[0][2] = 0.192*saturation;//red
			break;
		case 3:
			useColor[0][0] = 0.316*saturation; useColor[0][1] = 0.400*saturation; useColor[0][2] = 0.206;//blue
			break;
		case 4:
			useColor[0][0] = 0.288*saturation; useColor[0][1] = 0.236*saturation; useColor[0][2] = 0.352*saturation;//purple
			break;

	}

	glGenVertexArrays(1, vao); // get a new, previously unused VAO name
	glGenBuffers(1, vbo); // get a new, previously unused VBO name

	glBindVertexArray(vao[0]); // (initialize it and) make it active
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // (initialize it and) make it active


	int numBytesInBuffer = 121 * 2 * sizeof(float); //points; 2 coords each;


	glBufferData(GL_ARRAY_BUFFER, numBytesInBuffer, vertices, GL_STATIC_DRAW);

	//int coordinateLocation = 0; // See "layout" in hello.vsh
	glVertexAttribPointer(ModelView::pvaLoc_mcPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(ModelView::pvaLoc_mcPosition);



	ModelView::numInstances++;
}

ModelView::~ModelView()
{
	// TODO: delete the vertex array objects and buffers here
	glDeleteBuffers(1, vbo);
	glDeleteVertexArrays(1, vao);

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
	xyzLimits[0] =  -5.0; xyzLimits[1] =   130.0; // (xmin, xmax)
	xyzLimits[2] = -3.0; xyzLimits[3] = 10.0; // (ymin, ymax)
	xyzLimits[4] =  -1.0; xyzLimits[5] =   1.0;


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

	// draw using our vertex and fragment shaders
	glUseProgram(shaderProgram);

	// TODO: set scaleTrans (and all other needed) uniform(s)
	float scaleTrans[4];
	compute2DScaleTrans(scaleTrans);
	glUniform4fv(ModelView::ppuLoc_scaleTrans, 1, scaleTrans);

	//std::cout<< scaleTrans[3] <<std::endl;

	//std::cout<< "render numvert:"<< numVertices<<std::endl;
	// TODO: make require primitive call(s)
	int buf=0;
	//for (int i=0 ; i<2 ; i++)
	//{


		glUniform3fv(ModelView::ppuLoc_color, 1, useColor[0]);
		glBindVertexArray(vao[0]);
		glDrawArrays(GL_LINE_STRIP, 0,  121);


	//}
	// restore the previous program
	glUseProgram(pgm);
}

void ModelView::setMCRegionOfInterest(double xyz[6])
{
	for (int i=0 ; i<6 ; i++){
		mcRegionOfInterest[i] = xyz[i];

		}
}
