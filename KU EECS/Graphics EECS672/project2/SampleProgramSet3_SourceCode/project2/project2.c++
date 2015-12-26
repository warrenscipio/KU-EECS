// project2.c++: Starter for EECS 672 Project 2

#include "GLFWController.h"
#include "platform.h"
#include "Block.h"
#include "sword.h"
#include "ObjReader.h"//I tried


#include "test.h"




void set3DViewingInformation(double xyz[6])
{
	ModelView::setMCRegionOfInterest(xyz);



	double xmid = 0.5 * (xyz[0] + xyz[1]);
	double ymid = 0.5 * (xyz[2] + xyz[3]);
	double zmid = 0.5 * (xyz[4] + xyz[5]);
	cryph::AffPoint center(xmid, ymid, zmid);

	// 2:
	double maxDelta = xyz[1] - xyz[0];
	double delta = xyz[3] - xyz[2];
	if (delta > maxDelta)
		maxDelta = delta;
	delta = xyz[5] - xyz[4];
	if (delta > maxDelta)
		maxDelta = delta;

	double distEyeCenter = 2.0 * maxDelta;
	cryph::AffPoint eye(xmid+40, ymid+100, zmid + distEyeCenter);

	// 3:
	cryph::AffVector up = cryph::AffVector::yu;

	// Set values for eye-center-up to produce a reasonable off-axis
	// view of your scene, then:

	// Notify the ModelView of our MC->EC viewing requests:
	ModelView::setEyeCenterUp(eye, center, up);

	double ecZpp, ecZmin, ecZmax;


	ecZpp = -(distEyeCenter - 0.5*maxDelta);
	ecZmin = ecZpp - maxDelta;
	ecZmax = ecZpp + 0.5*maxDelta;


	// Set values for ecZpp, ecZmin, ecZmax that make sense in the context of
	// the EC system established above, then:

	ModelView::setProjection(PERSPECTIVE);
	ModelView::setProjectionPlaneZ(ecZpp);
	ModelView::setECZminZmax(ecZmin, ecZmax);
}

int main(int argc, char* argv[])
{
	GLFWController c("CUBE TEST", MVC_USE_DEPTH_BIT);
	c.reportVersions(std::cout);
	const char *file = "realSword.obj";
	// create your scene, adding things to the Controller....

c.addModel(new Block(0,0,0,100,3,200));
	//c.addModel(new ObjReader(10,100,10,100,50,200, file));
	c.addModel(new sword(80,5,150,20,50,10));
	c.addModel(new platform(25,5,150,50,5,25));
	c.addModel(new test(2,2,0,100,100,130, 1));


	glClearColor(0.0, 0.0, 0.0, 1.0);

	double xyz[6];
	c.getOverallMCBoundingBox(xyz);
	set3DViewingInformation(xyz);



	c.run();

	return 0;
}
