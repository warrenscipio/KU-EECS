// Block.h

#ifndef BLOCK_H
#define BLOCK_H

#include <GL/gl.h>

#include "ModelViewWithPhongLighting.h"

class Block : public ModelViewWithPhongLighting
{
public:
	Block(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz);// lengths in 3 directions
	virtual ~Block();

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

	bool displayBlockEdges, displayBlockFill;

	void defineBlock();
	void renderBlock(float* color);
};

#endif
