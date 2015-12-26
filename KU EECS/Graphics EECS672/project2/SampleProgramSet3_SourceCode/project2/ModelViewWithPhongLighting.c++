// ModelViewWithPhongLighting.c++

#include <iostream>
#include <math.h>

#include "AffPoint.h"
#include "AffVector.h"
#include "Matrix4x4.h"

#include "ModelViewWithPhongLighting.h"
#include "ShaderIF.h"

ShaderIF* ModelViewWithPhongLighting::shaderIF = NULL;
int ModelViewWithPhongLighting::numInstances = 0;
GLuint ModelViewWithPhongLighting::shaderProgram = 0;
GLint ModelViewWithPhongLighting::pvaLoc_mcPosition = -2;
GLint ModelViewWithPhongLighting::pvaLoc_mcNormal = -2;
GLint ModelViewWithPhongLighting::ppuLoc_kd = -2;
GLint ModelViewWithPhongLighting::ppuLoc_ka = -2;
GLint ModelViewWithPhongLighting::ppuLoc_mc_ec = -2;
GLint ModelViewWithPhongLighting::ppuLoc_ec_lds = -2;

GLint ModelViewWithPhongLighting::uLoc_p_ecLightPos = -2;
GLint ModelViewWithPhongLighting::uLoc_lightStrength = -2;
GLint ModelViewWithPhongLighting::uLoc_globalAmbient = -2;

std::string ModelViewWithPhongLighting::vShaderSource = "simple3d.vsh";
std::string ModelViewWithPhongLighting::fShaderSource = "simple3d.fsh";


float lightPosition[ ] = {
   0.8, 0.8, 0.8, 5.0 // source 0: directional
   };
float lightStrength[ ] = {
   0.8, 0.8, 0.8, // source 0: full strength white
   };
float ambientStrength[ ] = { 0.4, 0.5, 0.8 }; // assumed ambient light

void ModelViewWithPhongLighting::establishLights()
{

    // Now send the EC geometric description along with the non-geometric data:
    int numLights = 1;
    glUniform4fv(uLoc_p_ecLightPos, numLights, lightPosition);
    glUniform3fv(uLoc_lightStrength, numLights, lightStrength);

    glUniform3fv(uLoc_globalAmbient, 1, ambientStrength);
}

ModelViewWithPhongLighting::ModelViewWithPhongLighting()
{
	if (shaderProgram == 0)
	{
		shaderIF = new ShaderIF(vShaderSource, fShaderSource);
		shaderProgram = shaderIF->getShaderPgmID();
		fetchGLSLVariableLocations();
	}
	numInstances++;
}

ModelViewWithPhongLighting::~ModelViewWithPhongLighting()
{
	if (--numInstances == 0)
	{
		shaderIF->destroy();
		delete shaderIF;
		shaderIF = NULL;
		shaderProgram = 0;
	}
}

void ModelViewWithPhongLighting::fetchGLSLVariableLocations()
{
	if (shaderProgram > 0)
	{
		pvaLoc_mcPosition = pvAttribLocation(shaderProgram, "mcPosition");
		pvaLoc_mcNormal = pvAttribLocation(shaderProgram, "mcNormal");
		ppuLoc_kd = ppUniformLocation(shaderProgram, "kd");
    ppuLoc_ka = ppUniformLocation(shaderProgram, "ka");
		ppuLoc_mc_ec = ppUniformLocation(shaderProgram, "mc_ec");
		ppuLoc_ec_lds = ppUniformLocation(shaderProgram, "ec_lds");

    uLoc_p_ecLightPos = ppUniformLocation(shaderProgram, "p_ecLightPos");
    uLoc_lightStrength = ppUniformLocation(shaderProgram, "lightStrength");
    uLoc_globalAmbient = ppUniformLocation(shaderProgram, "globalAmbient");

	}
}

void ModelViewWithPhongLighting::setShaderSources(const std::string& vShaderSrc, const std::string& fShaderSrc)
{
	vShaderSource = vShaderSrc;
	fShaderSource = fShaderSrc;
}
