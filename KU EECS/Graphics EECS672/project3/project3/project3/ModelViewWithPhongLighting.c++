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
GLint ModelViewWithPhongLighting::ppuLoc_ks = -2;
GLint ModelViewWithPhongLighting::ppuLoc_m = -2;
GLint ModelViewWithPhongLighting::ppuLoc_mc_ec = -2;
GLint ModelViewWithPhongLighting::ppuLoc_ec_lds = -2;

GLint ModelViewWithPhongLighting::ppuLoc_ka = -2;
GLint ModelViewWithPhongLighting::ppuLoc_p_ecLightPos = -2;
GLint ModelViewWithPhongLighting::ppuLoc_lightStrength = -2;
GLint ModelViewWithPhongLighting::ppuLoc_actualNumLights = -2;
GLint ModelViewWithPhongLighting::ppuLoc_globalAmbient = -2;

std::string ModelViewWithPhongLighting::vShaderSource = "simple3d.vsh";
std::string ModelViewWithPhongLighting::fShaderSource = "simple3d.fsh";


float lightPositionInEC[ ] = {
  0.0,  -100.0, 0.0, 1.0, //
  0.0, 100.0, 0.0, 1.0,
  0.0, 0.0, 0.0, 0.0// location light

   };
float lightStrength[ ] = {
   1.0, 1.0, 1.0,
   1.0, 1.0, 0.0,
   0.5, 0.5, 0.5 // source 0: full strength white
   };

float ambientStrength[ ] = { 0.2, 0.2, 0.2 }; // assumed ambient light


void ModelViewWithPhongLighting::establishLights()
{

    // Now send the EC geometric description along with the non-geometric data:
    int numLights = 3;
  //  glUniform4fv(uLoc_p_ecLightPos, numLights, lightPosition);
  //  glUniform3fv(uLoc_lightStrength, numLights, lightStrength);
  //  glUniform3fv(uLoc_globalAmbient, 1, ambientStrength);

    glUniform4fv(ppuLoc_p_ecLightPos, numLights, lightPositionInEC);
   glUniform3fv(ppuLoc_lightStrength, numLights, lightStrength);
   glUniform1i(ppuLoc_actualNumLights, numLights);
   glUniform3fv(ppuLoc_globalAmbient, 1, ambientStrength);
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

    ppuLoc_ks = ppUniformLocation(shaderProgram, "ks");
		ppuLoc_mc_ec = ppUniformLocation(shaderProgram, "mc_ec");
		ppuLoc_ec_lds = ppUniformLocation(shaderProgram, "ec_lds");
    ppuLoc_m = ppUniformLocation(shaderProgram, "m");

    ppuLoc_ka = ppUniformLocation(shaderProgram, "ka");
    ppuLoc_p_ecLightPos = ppUniformLocation(shaderProgram, "p_ecLightPos");
    ppuLoc_lightStrength = ppUniformLocation(shaderProgram, "lightStrength");
    ppuLoc_globalAmbient = ppUniformLocation(shaderProgram, "globalAmbient");

	}
}

void ModelViewWithPhongLighting::setShaderSources(const std::string& vShaderSrc, const std::string& fShaderSrc)
{
	vShaderSource = vShaderSrc;
	fShaderSource = fShaderSrc;
}
