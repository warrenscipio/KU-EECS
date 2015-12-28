// ModelViewWithPhongLighting.h

#ifndef MODELVIEWWITHPHONGLIGHTING_H
#define MODELVIEWWITHPHONGLIGHTING_H

#ifdef __APPLE_CC__
#include "GLFW/glfw3.h"
#else
#include <GL/gl.h>
#endif

#include "ModelView.h"
#include "ShaderIF.h"
#include "Matrix4x4.h"

class ModelViewWithPhongLighting : public ModelView
{
public:
	ModelViewWithPhongLighting();
	virtual ~ModelViewWithPhongLighting();

	static void setShaderSources(const std::string& vShader, const std::string& fShader);

protected:

	static ShaderIF* shaderIF;
	static int numInstances;
	static GLuint shaderProgram;
	static GLint pvaLoc_mcPosition, pvaLoc_mcNormal;
	static GLint ppuLoc_kd;
	static GLint ppuLoc_mc_ec, ppuLoc_ec_lds;

	static void fetchGLSLVariableLocations();

private:
	static std::string vShaderSource, fShaderSource;
};

#endif
