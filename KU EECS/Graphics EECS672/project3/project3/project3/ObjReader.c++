// ObjReader.c++

#include <iostream>
#include <math.h>
#include "ModelViewWithPhongLighting.h"
#include "ObjReader.h"


#include "ShaderIF.h"

#include <fstream>
#include <iostream>
#include <sstream>



using namespace std;



typedef float vec3[3];
int numberOfVert;
int numberOfNormals;
int numberOfFaces;
int globalColor=6;
int shapeType=0;
float *ka,*kd, *ks, m;


// index lists for the three faces that can't be drawn with glDrawArrays
// Needed some way to control the offset and scale. Used the c values as offset and the l values as scale.
ObjReader::ObjReader(float cx, float cy, float cz, float lx, float ly, float lz, const char* name) {



	CountVertices(name);
	loadObj(name);
	//setType(type);
	//glLoadIdentity();

	drawObj(name);

	// Store scaling variables
	mLx = lx;
	mLy = ly;
	mLz = lz;

	mOffsetX = cx;
	mOffsetY = cy;
	mOffsetZ = cz;

	xmin = cx; xmax = cx + lx;
	ymin = cy; ymax = cy + ly;
	zmin = cz; zmax = cz + lz;




	defineObjReader();
}

ObjReader::~ObjReader() {
	glDeleteBuffers(3, ebo);
	glDeleteBuffers(1, vbo);
	glDeleteVertexArrays(1, vao);
}

void ObjReader::setColor(float *tkd, float *tka, float *tks, int tm){

	kd = tkd;
	ka = tka;
	ks = tks;
	m = tm;
}

void ObjReader::setType(int type){
	shapeType = type;
}


void ObjReader::CountVertices(const char* filename) {

	ifstream file;
	file.open(filename);
	string str;

	while (!file.eof()) //while we are still in the file
	{
		getline(file, str); //move one line down
		//std::cout <<str<<std::endl;
		if (str[0] == 'v') break;
		//	if(str[0] == 'f') break; //if we have a vertex line, stop
	}

	int v = 0;
	int n = 0;
	int f = 0;
	//count vertices
	while (str[0] == 'v') {

		v++;
		//std::cout<<str<<std::endl;
		getline(file, str);
		//count normals
		if (str[1] == 'n') {

			while (str[1] == 'n') {
				n++;
				getline(file, str);

			}

			break;
		}

	}


	while (!file.eof()) //while we are still in the file
	{
		getline(file, str); //move one line down
		//std::cout <<str<<std::endl;
		if (str[0] == 'f') break;
		//	if(str[0] == 'f') break; //if we have a vertex line, stop
	}

	//count faces
	while (str[0] == 'f') {
		f++;
		//std::cout<<str<<std::endl;
		getline(file, str);

	}

	numberOfNormals = n;
	std::cout << "set Normals " << numberOfNormals << std::endl;
	numberOfVert = v;
	std::cout << "set Verts " << numberOfVert << std::endl;

	normalsArray = new NormalVector[numberOfNormals];
	verticesArray = new Vertex[numberOfVert];

	numberOfFaces = f;
	std::cout << "Faces " << numberOfFaces << std::endl;
	facesArray = new Faces[numberOfFaces];
	file.close();
	//	for(int i=0;i<8;i++)
		std::cout << "-------------- " <<std::endl;


}


void ObjReader::loadObj(const char* filename) {

	ifstream file;
	file.open(filename);

	string str;

	//while (!file.eof()){

		while (!file.eof()) //while we are still in the file
		{
			getline(file, str); //move one line down
			if (str[0] == 'v') break; //if we have a vertex line, stop
		}

		int v = 0;
		//get vertices
		while ((str[0] == 'v') && (str[1] != 'n')) {
			char a;
			float x;
			float y;
			float z;
			std::stringstream ss(str);
			ss >> a >> x >> y >> z;
			verticesArray[v].x = x;
			verticesArray[v].y = y;
			verticesArray[v].z = z;
			//vertices[v][0] = x;
			//	vertices[v][1] = y;
			//vertices[v][2] = z;
			v++;
			getline(file, str);
		}

		int n = 0;
		//get normals
		while ((str[0] == 'v') && (str[1] == 'n')) {
			char a;
			char b;
			float x;
			float y;
			float z;
			std::stringstream ss(str);
			ss >> a >> b >> x >> y >> z;
			normalsArray[n].x = x;
			normalsArray[n].y = y;
			normalsArray[n].z = z;
			n++;
			getline(file, str);
		}

		while (!file.eof()) //while we are still in the file
		{
			getline(file, str); //move one line down
			if (str[0] == 'f') break; //if we have a vertex line, stop
		}

		v = 0;
		int f = 0;
		//get faces
		while (str[0] == 'f') {
			char a;
			int x;
			int y;
			int x1;
			int y1;
			int x2;
			int y2;
			int x3;
			int y3;
			char spacer;
			char spacer2;


			std::stringstream ss(str);
			ss >> a >> x >> spacer >> spacer2 >> y >> x1 >> spacer >> spacer2 >> y1 >> x2 >> spacer >> spacer2 >> y2;


			facesArray[f].v1 = x;
			facesArray[f].vn = y;

			facesArray[f].v2 = x1;
			//facesArray[f].vn2 = y1;

			facesArray[f].v3 = x2;

			f++;
			getline(file, str);
		}

	//}



	file.close();

//	-- testing block--
	//for(int i=0;i<numberOfVert;i++)
	//std::cout << verticesArray[i].x << " " << verticesArray[i].y << " " << verticesArray[i].z <<std::endl;
/*
	for(int i=0;i<6;i++)
	std::cout << normalsArray[i].x << " " << normalsArray[i].y << " " << normalsArray[i].z <<std::endl;

	for(int i=0;i<6;i++){
	std::cout << facesArray[i].v1 << facesArray[i].vn << " " ;
	std::cout << facesArray[i].v2 << facesArray[i].vn << " " ;
	std::cout << facesArray[i].v3 << facesArray[i].vn << " " ;
	std::cout <<std::endl;
	std::cout << std::endl;
	}
*/


}

void ObjReader::drawObj(const char *filename) {


}


void ObjReader::defineObjReader() {
	// Check for errors so we know if we cause any.
	Controller::checkForErrors(std::cout, "defineObjReaderPre");


	/*
	This is ONE way to do this. I didn't feel like messing with the element buffers so I just went straight for the
	general buffers.
	*/
	std::vector<float> pVertices;
	std::vector<float> pNormals;

	for (int f = 0; f < numberOfFaces; f++) {
		Faces pCurrentFace = facesArray[f];

		// Convert the Vertex structs to floats and store in vector
		pVertices.push_back(verticesArray[pCurrentFace.v1-1].x);
		pVertices.push_back(verticesArray[pCurrentFace.v1-1].y);
		pVertices.push_back(verticesArray[pCurrentFace.v1-1].z);

		pVertices.push_back(verticesArray[pCurrentFace.v2-1].x);
		pVertices.push_back(verticesArray[pCurrentFace.v2-1].y);
		pVertices.push_back(verticesArray[pCurrentFace.v2-1].z);

		pVertices.push_back(verticesArray[pCurrentFace.v3-1].x);
		pVertices.push_back(verticesArray[pCurrentFace.v3-1].y);
		pVertices.push_back(verticesArray[pCurrentFace.v3-1].z);

		for (int i = 0; i < 3; i++) {
			pNormals.push_back(normalsArray[pCurrentFace.vn-1].x);
			pNormals.push_back(normalsArray[pCurrentFace.vn-1].y);
			pNormals.push_back(normalsArray[pCurrentFace.vn-1].z);
		}
	}
	for (size_t i = 0; i < pVertices.size(); i+=3) {
	//	std::cout << pVertices[i+0] << " "<< pVertices[i+1]<< " "<< pVertices[i+2] << std::endl;

	}
//std::cout << verticesArray[facesArray[1].v1].x << std::endl;



	// Scale all vertices by lx,ly,lz provided. Move the vertices by the cx,cy,cz provided
	for (size_t i = 0; i < pVertices.size(); i+=3) {
		pVertices[i + 0] = (pVertices[i + 0] * mLx) + mOffsetX;
		pVertices[i + 1] = (pVertices[i + 1] * mLy) + mOffsetY;
		pVertices[i + 2] = (pVertices[i + 2] * mLz) + mOffsetZ;
		//	std::cout << pVertices[i+0] << " "<< pVertices[i+1]<< " "<< pVertices[i+3] << std::endl;
	}


	mNumVerticesToRender = pVertices.size()/3 ;

	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glGenBuffers(2, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, pVertices.size() * sizeof(float), &pVertices.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(pvaLoc_mcPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(pvaLoc_mcPosition);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, pNormals.size() * sizeof(float), &pNormals.front(), GL_STATIC_DRAW);
	glVertexAttribPointer(pvaLoc_mcNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(pvaLoc_mcNormal);
	Controller::checkForErrors(std::cout, "defineObjReaderPost");
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void ObjReader::getMCBoundingBox(double* xyzLimits) const {
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void ObjReader::handleCommand(unsigned char key, double ldsX, double ldsY) {

}

void ObjReader::renderObjReader() {

	glBindVertexArray(vao[0]);
	//glUniform3fv(ppuLoc_kd, 1, kd);
	glPointSize(2);
//std::cout<< shapeType << std::endl;



	if(shapeType == 1){
		for (int i = 0; i < mNumVerticesToRender; i += 3) {
			glDrawArrays(GL_POINTS, i, 3);
		}
	}else if(shapeType == 2){
		for (int i = 0; i < mNumVerticesToRender; i += 3) {
			glDrawArrays(GL_LINES, i, 3);
		}

	}else {
		for (int i = 0; i < mNumVerticesToRender; i += 3) {
			glDrawArrays(GL_TRIANGLE_STRIP, i, 3);
		}

	}
}

void ObjReader::render() {

	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];

	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false,  ec_lds.extractColMajor(mat));



	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	renderObjReader();


	glUniform3fv(ppuLoc_ka, 1, ka);
	glUniform3fv(ppuLoc_kd, 1, kd);
	glUniform3fv(ppuLoc_ks, 1, ks);
	glUniform1f (ppuLoc_m, m);
	establishLights();






	glUseProgram(pgm);
}
