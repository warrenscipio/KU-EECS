// TEMPLATE_Subclass.c++


#include "ShaderIF.h"
#include "ModelViewWithPhongLighting.h"
#include "sword.h"


typedef float vec3[3];



// index lists for the three faces that can't be drawn with glDrawArrays


sword::sword(float cx, float cy, float cz, float lx, float ly, float lz)
{

	xmin = cx;
	xmax = cx+lx;
	ymin = cy;
	ymax = cy+ly;
	zmin = cz;
	zmax = cz+lz;

	definesword( cx, cy, cz, lx, ly, lz);

}

sword::~sword()
{

	delete handle;
	delete hilt;
	delete blade;



}

void sword::definesword(float cx, float cy, float cz, float lx, float ly, float lz)
{



	//top
	handle = new Block(((cx+lx)/2)-((lx*.2)/2),ly+(ly/10),cz,lx*.2,ly*.2,lz);
	//midBlock
hilt = new Block((cx-1)/2,ly,cz,lx,ly/10,lz);

	//floor
	blade = new Block((cx+lx)/2-((lx*.5)/2),cy,cz,lx*.5,ly,5);




}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void sword::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void sword::handleCommand(unsigned char key, double ldsX, double ldsY)
{

}

void sword::rendersword()
{

	handle->Block::setColor(1);
	handle->Block::render();
	hilt->Block::setColor(3);
	hilt->Block::render();
	blade->Block::setColor(5);
	blade->Block::render();




}

void sword::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false, ec_lds.extractColMajor(mat));

	//

	rendersword();
	establishLights();

	glUseProgram(pgm);
}
