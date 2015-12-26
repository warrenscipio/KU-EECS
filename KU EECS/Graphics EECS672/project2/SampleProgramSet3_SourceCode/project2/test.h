// test.h

#ifndef test_H
#define test_H

#include <GL/gl.h>

#include "ModelViewWithPhongLighting.h"

class test : public ModelViewWithPhongLighting
{
public:
	test(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz, double color);// lengths in 3 directions
	virtual ~test();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);
	void render();
private:
	GLuint vao[1];
	GLuint vbo[1];
	GLuint ebo[3];

	float xmin, xmax, ymin, ymax, zmin, zmax;

	static GLuint indexList[3][4];

	bool displaytestEdges, displaytestFill;

	void definetest();
	void rendertest(float* color);
};

#endif
