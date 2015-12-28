// sword.h

#ifndef sword_H
#define sword_H

#include <GL/gl.h>
#include "Block.h"
#include "ModelViewWithPhongLighting.h"

class sword : public ModelViewWithPhongLighting
{
public:
	sword(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz);// lengths in 3 directions
	virtual ~sword();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);

	void render();
private:


	Block* handle;
	Block* hilt;
	Block* blade;

	float xmin, xmax, ymin, ymax, zmin, zmax;


	void definesword(float cx, float cy, float cz, float lx, float ly, float lz);
	void rendersword();
};

#endif
