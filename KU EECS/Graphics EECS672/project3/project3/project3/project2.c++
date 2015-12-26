// project2.c++: Starter for EECS 672 Project 2

//#include "GLFWController.h"
#include "ControllerSub.h"//replacing GLFWController

#include "drops.h"
#include "person.h"
#include "Block.h"
#include "sword.h"
#include "island.h"
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
	ControllerSub c("Excalibur", MVC_USE_DEPTH_BIT);
	c.reportVersions(std::cout);

	// create your scene, adding things to the Controller....

	//c.addModel(new Block(0,0,0,100,3,200));

	//made some bounds so I can keep track of stuff
	c.addModel(new test(1,-50,-100,0,0,0, 0));
	c.addModel(new test(1,100,100,0,0,0, 1));
	c.addModel(new test(300,50,1,0,0,0, 1));
	c.addModel(new test(-100,50,1,0,0,0, 1));
	//---------

	//c.addModel(new test(80,-5,10,10,10,10, 1));

	c.addModel(new person(100,-6,13,10,10,10));
	c.addModel(new island(0,45,10,10,10,10));
	c.addModel(new sword(0,-3,10,5,5,5));
	c.addModel(new drops(7, 10, 10, 15, 15, 15));
	//c.addModel(new ObjReader(0, 35, 10, 10, 10, 10, file));



	glClearColor(0.0, 0.0, 0.0, 1.0);

	double xyz[6];
	c.getOverallMCBoundingBox(xyz);

	set3DViewingInformation(xyz);



	c.run();

	return 0;
}
