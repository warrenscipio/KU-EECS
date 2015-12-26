// person.h

#ifndef person_H
#define person_H

#include <GL/gl.h>
#include "Block.h"
#include "ModelViewWithPhongLighting.h"
#include "ObjReader.h"

class person : public ModelViewWithPhongLighting
{
public:
	person(float cx, float cy, float cz, // lower left corner
	      float lx, float ly, float lz);// lengths in 3 directions
	virtual ~person();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	void handleCommand(unsigned char key, double ldsX, double ldsY);

	void render();
private:


	ObjReader* body;
	ObjReader* ship;



	float xmin, xmax, ymin, ymax, zmin, zmax;


	void defineperson(float cx, float cy, float cz, float lx, float ly, float lz);
	void renderperson();
};

#endif
