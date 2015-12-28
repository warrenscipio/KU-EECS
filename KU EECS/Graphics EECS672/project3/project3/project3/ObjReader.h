// ObjReader.h

#ifndef ObjReader_H
#define ObjReader_H

#include <GL/gl.h>
#include <fstream>


#include "ModelViewWithPhongLighting.h"

struct NormalVector {
	float x, y, z;
};

struct Vertex {
	float x, y, z;
};

struct Faces {
	int v1, v2, v3, vn;
};


class ObjReader : public ModelViewWithPhongLighting {
public:
	ObjReader(float cx, float cy, float cz, // lower left corner
		float lx, float ly, float lz, const char* name);// lengths in 3 directions
	virtual ~ObjReader();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);
	void render();
	void loadObj(const char* file);
	void CountVertices(const char* file);
	void drawObj(const char* file);
	void setColor(float *tkd, float *tka, float *tks, int tm);
	void setType(int type);


private:
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[3];

	Vertex *verticesArray;
	NormalVector *normalsArray;
	Faces *facesArray;




	float xmin, xmax, ymin, ymax, zmin, zmax;
	float mLx, mLy, mLz;
	float mOffsetX, mOffsetY, mOffsetZ;
	int mNumVerticesToRender;

	static GLuint indexList[3][4];

	bool displayObjReaderEdges, displayObjReaderFill;

	void defineObjReader();
	void renderObjReader();
};

#endif
