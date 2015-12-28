// drops.h

#ifndef drops_H
#define drops_H

#include <GL/gl.h>
#include "Block.h"
#include "ModelViewWithPhongLighting.h"
#include "ObjReader.h"

class drops : public ModelViewWithPhongLighting
{
public:
	drops(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz);// lengths in 3 directions
	virtual ~drops();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);

	void render();
private:


	ObjReader* sphere;
	ObjReader* cone;


	float xmin, xmax, ymin, ymax, zmin, zmax;


	void definedrops(float cx, float cy, float cz, float lx, float ly, float lz);
	void renderdrops();
};

#endif
