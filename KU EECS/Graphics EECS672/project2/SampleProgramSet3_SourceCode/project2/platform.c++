// TEMPLATE_Subclass.c++


#include "ShaderIF.h"
#include "ModelViewWithPhongLighting.h"
#include "platform.h"


typedef float vec3[3];



// index lists for the three faces that can't be drawn with glDrawArrays


platform::platform(float cx, float cy, float cz, float lx, float ly, float lz)
{

	xmin = cx;
	xmax = cx+lx;
	ymin = cy;
	ymax = cy+ly;
	zmin = cz;
	zmax = cz+lz;

	defineplatform( cx, cy, cz, lx, ly, lz);

}

platform::~platform()
{

	delete top;
	delete midBlock;
	delete floorBlock;



}

void platform::defineplatform(float cx, float cy, float cz, float lx, float ly, float lz)
{

	//top
	top = new Block(cx*1.5,cy*3,cz,lx*.5,ly,lz*.6);
	//midBlock
	midBlock = new Block(cx*1.25,cy*2,cz,lx*.75,ly,lz*.8);
	//floor
	floorBlock = new Block(cx,cy,cz,lx,ly,lz);


}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void platform::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void platform::handleCommand(unsigned char key, double ldsX, double ldsY)
{

}

void platform::renderplatform(float* color)
{

	top->Block::setColor(4);
	top->Block::render();
	midBlock->Block::setColor(4);
	midBlock->Block::render();
	floorBlock->Block::setColor(4);
	floorBlock->Block::render();


}

void platform::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false, ec_lds.extractColMajor(mat));

	float black[] = { 0.0, 0.0, 0.0 };
	float bColor[] = { 0.2, 0.9, 0.2 };


	renderplatform(bColor);
	establishLights();

	glUseProgram(pgm);
}
