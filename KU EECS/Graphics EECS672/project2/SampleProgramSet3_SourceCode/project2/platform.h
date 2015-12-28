// platform.h

#ifndef platform_H
#define platform_H

#include <GL/gl.h>
#include "Block.h"
#include "ModelViewWithPhongLighting.h"

class platform : public ModelViewWithPhongLighting
{
public:
	platform(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz);// lengths in 3 directions
	virtual ~platform();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);

	void render();
private:


	Block* top;
	Block* midBlock;
	Block* floorBlock;

	float xmin, xmax, ymin, ymax, zmin, zmax;


	void defineplatform(float cx, float cy, float cz, float lx, float ly, float lz);
	void renderplatform(float* color);
};

#endif
