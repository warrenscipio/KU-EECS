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
	delete fog;



}

void sword::definesword(float cx, float cy, float cz, float lx, float ly, float lz)
{

const char *file1 = "Objs/thandle.obj";
const char *file2 = "Objs/tfeathers.obj";
const char *file3 = "Objs/tblade.obj";
const char *file4 = "Objs/tfeathers.obj";




	handle = new ObjReader(cx,cy,cz,lx,ly,lz,file1);

	hilt = new ObjReader(cx,cy,cz,lx,ly,lz,file2);

	blade = new ObjReader(cx,cy,cz,lx,ly,lz,file3);

	fog = new ObjReader(cx,cy,cz,lx,ly,lz,file4);




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
//handle
	float ka[] = { 1.0, 0.2, 0.4 }; //ambient reflectivity
	float kd[] = { 0.8, 0.5, 0.5 }; // basic object color
	float ks[] = { 1.0, 1.2, 0.2 }; //specular reflectivity
	float m = 0; //Specular	coefficient glossyness 0-25

	float ka1[] = { 0.0, 0.2, 0.4 }; //ambient reflectivity
	float kd1[] = { 0.0, 1.0, 0.0 }; // basic object color
	float ks1[] = { 0.0, 0.0, 0.0 }; //specular reflectivity
	float m1 = 0; //Specular	coefficient glossyness 0-25
//blade
	float ka2[] = { 0.9, 0.2, 0.4 }; //ambient reflectivity
	float kd2[] = { 0.5, 0.5, 0.5 }; // basic object color
	float ks2[] = { 0.9, 0.7, 0.5 }; //specular reflectivity
	float m2 = 0; //Specular	coefficient glossyness 0-25

//little sphere
	float ka3[] = { 1.0, 0.2, 0.4 }; //ambient reflectivity
	float kd3[] = { 0.2, 0.6, 0.9 }; // basic object color
	float ks3[] = { 0.2, 0.5, 0.9 }; //specular reflectivity
	float m3 = 0; //Specular	coefficient glossyness 0-25

	fog->ObjReader::setColor(kd,ka,ks,m);
	fog->ObjReader::setType(2);
	fog->ObjReader::render();
	handle->ObjReader::setColor(kd1,ka1,ks1,m1);
	handle->ObjReader::setType(0);
	handle->ObjReader::render();
	hilt->ObjReader::setColor(kd2,ka2,ks2,m2);
	hilt->ObjReader::setType(0);
	hilt->ObjReader::render();
	blade->ObjReader::setColor(kd3,ka3,ks3,m3);
	blade->ObjReader::setType(0);
	blade->ObjReader::render();







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





	rendersword();
	establishLights();

	glUseProgram(pgm);
}
