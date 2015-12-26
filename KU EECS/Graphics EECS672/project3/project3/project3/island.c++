// TEMPLATE_Subclass.c++


#include "ShaderIF.h"
#include "ModelViewWithPhongLighting.h"
#include "island.h"


typedef float vec3[3];



// index lists for the three faces that can't be drawn with glDrawArrays


island::island(float cx, float cy, float cz, float lx, float ly, float lz)
{

	xmin = cx;
	xmax = cx+lx;
	ymin = cy;
	ymax = cy+ly;
	zmin = cz;
	zmax = cz+lz;

	defineisland( cx, cy, cz, lx, ly, lz);

}

island::~island()
{

	delete water;
	delete grass;
	delete dirt;



}

void island::defineisland(float cx, float cy, float cz, float lx, float ly, float lz)
{

const char *file1 = "Objs/test.obj";
const char *file2 = "Objs/test.obj";
const char *file3 = "Objs/test.obj";


	water = new ObjReader(cx,cy-17,cz,lx*.8,ly*.8,lz*.8,file1);

	grass = new ObjReader(cx,cy,cz,lx*1.3,ly*1.3,lz*1.3,file2);

	dirt = new ObjReader(cx,cy-3,cz,lx*1.3,ly*1.3,lz*1.3,file3);

}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void island::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void island::handleCommand(unsigned char key, double ldsX, double ldsY)
{

}

void island::renderisland()
{
	//water
	float ka[] = { 0.0, 0.2, 0.4 }; //ambient reflectivity
	float kd[] = { 0.3, 1.5, 0.9 }; // basic object color
	float ks[] = { 0.0, 1.5, 0.5 }; //specular reflectivity
	float m = 25; //Specular	coefficient glossyness 0-25
//dirt
	float ka2[] = { 0.4, 0.4, 0.4 }; //ambient reflectivity
	float kd2[] = { 0.2, 0.2, 0.2 }; // basic object color
	float ks2[] = { 0.8, 0.5, 0.5 }; //specular reflectivity
	float m2 = 25; //Specular	coefficient glossyness 0-25
//feathers
	float ka3[] = { 1.0, 0.2, 0.4 }; //ambient reflectivity
	float kd3[] = { 0.8, 0.5, 0.5 }; // basic object color
	float ks3[] = { 1.0, 1.2, 0.2 }; //specular reflectivity
	float m3 = 0; //Specular	coefficient glossyness 0-25

	water->ObjReader::setColor(kd,ka,ks,m);
	water->ObjReader::render();
	grass->ObjReader::setColor(kd2,ka2,ks2,m2);
	grass->ObjReader::render();
	dirt->ObjReader::setColor(kd3,ka3,ks3,m3);
	dirt->ObjReader::render();


}

void island::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false, ec_lds.extractColMajor(mat));


	renderisland();
	establishLights();

	glUseProgram(pgm);
}
