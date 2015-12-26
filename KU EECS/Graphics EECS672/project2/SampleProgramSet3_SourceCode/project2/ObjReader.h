// ObjReader.h

#ifndef ObjReader_H
#define ObjReader_H

#include <GL/gl.h>
#include <fstream>


#include "ModelViewWithPhongLighting.h"




class ObjReader : public ModelViewWithPhongLighting
{
public:
	ObjReader(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz,const char* name);// lengths in 3 directions
	virtual ~ObjReader();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);
	void render();
	void loadObj(const char* file);
  void drawObj(const char* file);

private:
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[3];
  float faces[256][4];
	float vertex[256][3];

	float xmin, xmax, ymin, ymax, zmin, zmax;

	static GLuint indexList[3][4];

	bool displayObjReaderEdges, displayObjReaderFill;

	void defineObjReader();
	void renderObjReader(float* color);
};

#endif
