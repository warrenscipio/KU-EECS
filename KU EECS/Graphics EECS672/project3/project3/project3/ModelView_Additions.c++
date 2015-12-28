// Extracted from: ModelView.c++ - an Abstract Base Class for a combined Model and View for OpenGL

#include "ModelView.h"
//#include "ProjectionType.h"

void ModelView::addToGlobalRotationDegrees(double rx, double ry, double rz)
{
//	std::cout << "For project 3, you must implement ModelView::addToGlobalRotationDegrees in ModelView_Additions.c++\n";
	// TODO: 1. UPDATE dynamic_view

dynamic_view = cryph::Matrix4x4::xRotationDegrees(ry)*cryph::Matrix4x4::yRotationDegrees(rx)*cryph::Matrix4x4::yRotationDegrees(rz)*dynamic_view;

// TODO: 2. Use dynamic_view in ModelView::getMatrices

}


void ModelView::resetRotation(){


dynamic_view = cryph::Matrix4x4();

}


void ModelView::addToGlobalZoom(double increment)
{
	//zooms to middle of eye
	dynamic_zoomScale =  dynamic_zoomScale * increment;
	// TODO: Project 3: Use dynamic_zoomScale in ModelView::getMatrices

}

void ModelView::getMatrices(cryph::Matrix4x4& mc_ec, cryph::Matrix4x4& ec_lds)
{

	// TODO:
	// 1. Create the mc_ec matrix:
	cryph::AffVector vec(0.0,0.0,eye.z-center.z);

	cryph::Matrix4x4 preT = cryph::Matrix4x4::translation(vec);
	cryph::Matrix4x4 postT = cryph::Matrix4x4::translation(-vec);


	cryph::Matrix4x4 M_ECu = cryph::Matrix4x4::lookAt(eye, center, up);
	// a) For project 2:
	// mc_ec = M_ECu;


	 mc_ec = postT * dynamic_view * preT * M_ECu;
	// 2. Create the ec_lds matrix:

	// Compute the radius of the sphere that circumscribes the mcRegionOfInterest:
	double dx = 0.5 * (mcRegionOfInterest[1] - mcRegionOfInterest[0]);
	double dy = 0.5 * (mcRegionOfInterest[3] - mcRegionOfInterest[2]);
	double dz = 0.5 * (mcRegionOfInterest[5] - mcRegionOfInterest[4]);
	double radius = sqrt(dx*dx + dy*dy + dz*dz)/2;
	// Use the radius to compute an approximate initial ecXmin, ecXmax, ecYmin, and ecYmax:
	double ecXmin = -radius*dynamic_zoomScale, ecXmax = radius*dynamic_zoomScale;
	double ecYmin = -radius*dynamic_zoomScale, ecYmax = radius*dynamic_zoomScale;
	// i) Adjust the width in the x OR y direction to match the viewport aspect ratio;
	double vAR = Controller::getCurrentController()->getViewportAspectRatio();
	matchAspectRatio(ecXmin, ecXmax, ecYmin, ecYmax, vAR);
	// ii) Project 3 and 4 only: Scale both widths by dynamic_zoom;
	// iii) Use the adjusted widths along with the ecZmin, ecZmax, and ecZpp:

	if (projType == ORTHOGONAL)
		ec_lds = cryph::Matrix4x4::orthogonal(ecXmin, ecXmax, ecYmin, ecYmax, ecZmin, ecZmax);
	else if (projType == PERSPECTIVE)
		ec_lds = cryph::Matrix4x4::perspective(ecZpp, ecXmin, ecXmax, ecYmin, ecYmax, ecZmin, ecZmax);
	else // Must be OBLIQUE
		ec_lds = cryph::Matrix4x4::oblique(ecZpp, ecXmin, ecXmax, ecYmin, ecYmax, ecZmin, ecZmax,
		                                   obliqueProjectionDir);
}
