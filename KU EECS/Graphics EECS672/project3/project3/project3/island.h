// island.h

#ifndef island_H
#define island_H

#include <GL/gl.h>
#include "Block.h"
#include "ModelViewWithPhongLighting.h"
#include "ObjReader.h"

class island : public ModelViewWithPhongLighting
{
public:
	island(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz);// lengths in 3 directions
	virtual ~island();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);

	void render();
private:


	ObjReader* water;
	ObjReader* grass;
	ObjReader* dirt;

	float xmin, xmax, ymin, ymax, zmin, zmax;


	void defineisland(float cx, float cy, float cz, float lx, float ly, float lz);
	void renderisland();
};

#endif
