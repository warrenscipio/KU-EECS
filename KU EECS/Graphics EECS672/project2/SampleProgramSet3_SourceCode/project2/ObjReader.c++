// ObjReader.c++

#include <iostream>
#include <math.h>
#include "ModelViewWithPhongLighting.h"
#include "ObjReader.h"
#include "ShaderIF.h"
#include <fstream>
#include <iostream>

using namespace std;



typedef float vec3[3];

// index lists for the three faces that can't be drawn with glDrawArrays


ObjReader::ObjReader(float cx, float cy, float cz, float lx, float ly, float lz, const char* name)
{
	for(int i = 0; i < 256; i++ ) {
			vertex[i][0] = 0;
			vertex[i][1] = 0;
			vertex[i][2] = 0;
	}

	loadObj(name);

	//glLoadIdentity();

	drawObj(name);

	xmin = cx; xmax = cx + lx;
	ymin = cy; ymax = cy + ly;
	zmin = cz; zmax = cz + lz;
defineObjReader();
}

ObjReader::~ObjReader()
{
	glDeleteBuffers(3,ebo);
	glDeleteBuffers(1, vbo);
	glDeleteVertexArrays(1, vao);
}

void ObjReader::loadObj(const char* filename){

    ifstream file;
    file.open(filename);

    string str;

    while(!file.eof()) //while we are still in the file
    {
        getline(file,str); //move one line down
        if(str[0] == 'v') break; //if we have a vertex line, stop
    }

    int v = 0;
		//get vertices
    while(str[0] == 'v') {

        int i = 0;

        while(true)
        {
            while(str[i] == ' ' )
            {
                i++; //move a space over
            }
            i++;
            i++;
            int j = i, k = i;
            while(str[i] != ' ') {
                i++;
                k = i;
            }
            vertex[v][0] = atof(str.substr(j, k-j).c_str());

            while(str[i] == ' ' ) {
                i++;
            }

            int q = i, w = i;
            while(str[i] != ' ' ) {
                i++;
                w = i;
            }
            vertex[v][1] = atof(str.substr(q, w-q).c_str());

            while(str[i] == ' ' ) {
                i++;
            }

            int a = i, s = i;
            while(str[i] != ' ' ) {
                i++;
                s = i;
            }
            vertex[v][2] = atof(str.substr(a, s-a).c_str());

            break;
        }
        v++;
        getline(file, str);
    }
		for(int i=0;i<8;i++)
		std::cout << vertex[i][0] << " " << vertex[i][1] << " " << vertex[i][2] <<std::endl;




}

void ObjReader::drawObj(const char *filename)
{

    ifstream is(filename);

		float rate1, rate2, rate3, rate4;
		char face;
    char space;
		int j=0;
		while (is >> face >> space >> rate1 >> space >> rate2 >> space >> rate3 >> space >> rate4)
  {

   	//read in and build y axis
   	faces[j][0]= rate1;
  	faces[j][1]= rate2;
  	faces[j][2]= rate3;
   	faces[j][3]= rate4;
  	 j++;
  }
	for(int i=0;i<8;i++)
	std::cout << faces[i][0] << " " << faces[i][1] << " " << faces[i][2] << faces[i][3]<<std::endl;


}


GLuint ObjReader::indexList[3][4] = {
	{ 6, 7, 0, 1 }, // xmin face
	{ 6, 0, 4, 2 }, // ymin face
	{ 1, 7, 3, 5 }  // ymax face
};


void ObjReader::defineObjReader()
{

	vec3 vtx[] = { // The 8 unique vertices (Note the order)
		{xmin ,ymin, zmax}, {xmin, ymax, zmax},
		{xmax, ymin, zmax}, {xmax, ymax, zmax},
		{xmax, ymin, zmin}, {xmax, ymax, zmin},
		{xmin, ymin, zmin}, {xmin, ymax, zmin}
	};




	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 8*sizeof(vec3), vtx, GL_STATIC_DRAW);
	glVertexAttribPointer(pvaLoc_mcPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(pvaLoc_mcPosition);

	glGenBuffers(3, ebo);
	for (int i=0 ; i<3 ; i++)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[i]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4*sizeof(GLuint), indexList[i], GL_STATIC_DRAW);
	}

	glDisableVertexAttribArray(pvaLoc_mcNormal);
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void ObjReader::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void ObjReader::handleCommand(unsigned char key, double ldsX, double ldsY)
{

}

void ObjReader::renderObjReader(float* color)
{
	glBindVertexArray(vao[0]);
	glUniform3fv(ppuLoc_kd, 1, color);

	// The three faces that can be drawn with glDrawArrays
	glVertexAttrib3f(pvaLoc_mcNormal, 0.0, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glVertexAttrib3f(pvaLoc_mcNormal, 1.0, 0.0, 0.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 2, 4);
	glVertexAttrib3f(pvaLoc_mcNormal, 0.0, 0.0, -1.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);

	// The three faces that are drawn with glDrawElements
	glVertexAttrib3f(pvaLoc_mcNormal, -1.0, 0.0, 0.0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, NULL);
	glVertexAttrib3f(pvaLoc_mcNormal, 0.0, -1.0, 0.0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[1]);
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, NULL);
	glVertexAttrib3f(pvaLoc_mcNormal, 0.0, 1.0, 0.0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[2]);
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, NULL);
}

void ObjReader::render()
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
	float bColor[] = { 0.8, 0.8, 0.8 };


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	renderObjReader(bColor);


	establishLights();
	glUseProgram(pgm);
}
