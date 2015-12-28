#include <iostream>

#include "AffPoint.h"
#include "AffVector.h"

/*
The output of the program below will be:

A = 0 0 0, B = 1 2 0, C = -1 1 1
u = 0 0 0, v = 0 1 0, w = -3.2 1.1 2.4

A = 1.7 0 0, B = 1 2 -3.4, C = 5 -44 3.7
u = 1.1 1.7 0, v = 0 1 -1, w = 0.2 1.1 2.4

A = 1.7 0 0, B = 1 2 -3.4, C = 5 -44 3.7
u = 0 0.707107 -0.707107, v = 0 1 -1, w = -0.737737 0.477359 0.477359

AminusB = 0.7 -2 3.4
midPoint of A and B = 1.35 1 -1.7
shouldBeZero1 = 0, shouldBeZero2 = 0
directionAtoB = 0.174727 -0.499221 0.848675
distanceAtoB = 4.00625

*/

void demo()
{
	// Create some points and vectors
	cryph::AffPoint A, B(1.0, 2.0), C(-1.0, 1.0, 1.0);
	cryph::AffVector u, v(0.0, 1.0), w(-3.2, 1.1, 2.4);

	std::cout << "A = " << A << ", B = " << B << ", C = " << C << '\n';
	std::cout << "u = " << u << ", v = " << v << ", w = " << w << "\n\n";

	// Very low-level modification
	A.x = 1.7;
	B.z = -3.4;
	u.dx = 1.1;
	u.dy = 1.7;
	w.dx = 0.2;
	v.dz = -1.0;
	C.assign(5.0, -44, 3.7);

	std::cout << "A = " << A << ", B = " << B << ", C = " << C << '\n';
	std::cout << "u = " << u << ", v = " << v << ", w = " << w << "\n\n";

	// Some higher level operations
	cryph::AffVector AminusB = A - B;
	cryph::AffPoint midPoint = (A + B) / 2.0;
	w = u.cross(v); // Make w be perpendicular to both u and v
	double shouldBeZero1 = u.dot(w);
	double shouldBeZero2 = v.dot(w);
	w.normalize(); // Make w be a unit vector (length 1)
	v.normalizeToCopy(u);
	double radius = 2.0;
	double theta = M_PI/3.0;
	cryph::AffPoint pntAtTheta = A + radius * (cos(theta)*u + sin(theta)*w);
	cryph::AffVector directionAtoB;
	double distanceAtoB = AminusB.normalizeToCopy(directionAtoB);

	std::cout << "A = " << A << ", B = " << B << ", C = " << C << '\n';
	std::cout << "u = " << u << ", v = " << v << ", w = " << w << "\n\n";

	std::cout << "AminusB = " << AminusB << "\n";
	std::cout << "midPoint of A and B = " << midPoint << '\n';
	std::cout << "shouldBeZero1 = " << shouldBeZero1
	          << ", shouldBeZero2 = " << shouldBeZero2 << '\n';
	std::cout << "directionAtoB = " << directionAtoB << "\n";
	std::cout << "distanceAtoB = " << distanceAtoB << "\n\n";
}

int main()
{
	demo();
	return 0;
}
