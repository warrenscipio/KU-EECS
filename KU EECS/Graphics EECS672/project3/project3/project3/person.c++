// TEMPLATE_Subclass.c++


#include "ShaderIF.h"
#include "ModelViewWithPhongLighting.h"
#include "person.h"


typedef float vec3[3];



// index lists for the three faces that can't be drawn with glDrawArrays


person::person(float cx, float cy, float cz, float lx, float ly, float lz)
{

	xmin = cx;
	xmax = cx+lx;
	ymin = cy;
	ymax = cy+ly;
	zmin = cz;
	zmax = cz+lz;

	defineperson( cx, cy, cz, lx, ly, lz);

}

person::~person()
{

	delete body;
	delete ship;

}

void person::defineperson(float cx, float cy, float cz, float lx, float ly, float lz)
{

const char *file1 = "Objs/RZ3.obj";
const char *file2 = "Objs/XWing3.obj";



	body = new ObjReader(cx,cy,cz,lx,ly,lz,file1);
	ship = new ObjReader(cx+60,cy+10,cz,lx*3,ly*3,lz*3,file2);

}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void person::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void person::handleCommand(unsigned char key, double ldsX, double ldsY)
{

}

void person::renderperson()
{
//gundam
	float ka[] = { 0.3, 0.2, 0.2 }; //ambient reflectivity
	float kd[] = { 0.2, 0.1, 0.1 }; // basic object color
	float ks[] = { 0.3, 0.2, 0.2 }; //specular reflectivity
	float m = 25; //Specular	coefficient glossyness 0-25

//water?
	float ka2[] = { 0.0, 0.2, 0.4 }; //ambient reflectivity
	float kd2[] = { 0.0, 0.2, 0.5 }; // basic object color
	float ks2[] = { 0.1, 0.1, 0.9 }; //specular reflectivity
	float m2 = 0; //Specular	coefficient glossyness 0-25


	ship->ObjReader::setColor(kd,ka,ks,m);
	ship->ObjReader::setType(0);
	//ship->ObjReader::setReflection();
	ship->ObjReader::render();

	body->ObjReader::setColor(kd2,ka2,ks2,m2);
	body->ObjReader::setType(0);
	body->ObjReader::render();
	//cone->ObjReader::setColor(3);
	//person->ObjReader::setType(0);
	//cone->ObjReader::render();

}

void person::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false, ec_lds.extractColMajor(mat));




	establishLights();

	renderperson();




	glUseProgram(pgm);
}
