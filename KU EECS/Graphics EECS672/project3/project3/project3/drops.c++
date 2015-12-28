// TEMPLATE_Subclass.c++


#include "ShaderIF.h"
#include "ModelViewWithPhongLighting.h"
#include "drops.h"


typedef float vec3[3];



// index lists for the three faces that can't be drawn with glDrawArrays


drops::drops(float cx, float cy, float cz, float lx, float ly, float lz)
{

	xmin = cx;
	xmax = cx+lx;
	ymin = cy;
	ymax = cy+ly;
	zmin = cz;
	zmax = cz+lz;

	definedrops( cx, cy, cz, lx, ly, lz);

}

drops::~drops()
{

	delete sphere;
	delete cone;




}

void drops::definedrops(float cx, float cy, float cz, float lx, float ly, float lz)
{

const char *file1 = "Objs/sphere.obj";



	sphere = new ObjReader(cx,cy,cz,lx,ly,lz,file1);

	cone = new ObjReader(cx,cy,cz,lx*20,ly*20,lz*20,file1);


}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void drops::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void drops::handleCommand(unsigned char key, double ldsX, double ldsY)
{

}

void drops::renderdrops()
{
	//big sphere
	float ks[] = { 0.9, 0.9, 0.9 }; //specular reflectivity
	float m = 0; //Specular	coefficient glossyness 0-25
	float ka[] = { 0.9, 0.9, 9.0 }; //ambient reflectivity
	float kd[] = { 0.9, 0.9, 9.0 }; // basic object color

//ship
	float ks1[] = { 0.7, 0.5, 0.4 }; //specular reflectivity
	float m1 = 15; //Specular	coefficient glossyness 0-25
	float ka1[] = { 0.7, 0.5, 0.5 }; //ambient reflectivity
	float kd1[] = { 0.7, 0.4, 0.4 }; // basic object color


	sphere->ObjReader::setColor(kd,ka,ks,m);
	sphere->ObjReader::setType(1);
	sphere->ObjReader::render();
	cone->ObjReader::setColor(kd1,ka1,ks1,m1);
	cone->ObjReader::setType(1);
	cone->ObjReader::render();

}

void drops::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false, ec_lds.extractColMajor(mat));



	renderdrops();
	establishLights();

	glUseProgram(pgm);
}
