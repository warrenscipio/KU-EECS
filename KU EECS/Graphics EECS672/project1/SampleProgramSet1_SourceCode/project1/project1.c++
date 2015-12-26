// project1.c++

#include "GLFWController.h"
#include "ModelView.h"
#include <fstream>



float yValues[4][121];
float xValues[4][121];
float line1[121][2];
float line2[121][2];
float line3[121][2];
float line4[121][2];

void buildData(){


  std::ifstream is("ExchangeRates.csv");

  std::string date;
  float rate1, rate2, rate3, rate4;
  char comma;
  
  int nLines = 0;
  
  
  int j=0;
  while (is >> date >> rate1 >> comma >> rate2 >> comma >> rate3 >> comma >> rate4)
  {
  	
   	//read in and build y axis
   	yValues[0][j]= rate1/.2;
  	yValues[1][j]= rate2/.2;
  	yValues[2][j]= rate3/.2;
   	yValues[3][j]= rate4/.2;
  	 j++;
  }
  
  for(int i=0; i<121;i++){
  	//build x axis
	xValues[0][i]= i;
 	xValues[1][i]= i;
  	xValues[2][i]= i;
 	xValues[3][i]= i;
  }
  
  
  for(int i=0; i<121;i++){
  
  //set x and y pairs to the line arrays
  line1[i][0] = xValues[0][i];
  line1[i][1] = yValues[0][i];
  
  line2[i][0] = xValues[1][i];
  line2[i][1] = yValues[1][i];
  
  line3[i][0] = xValues[2][i];
  line3[i][1] = yValues[2][i];
  
  line4[i][0] = xValues[3][i];
  line4[i][1] = yValues[3][i];
  
  }
  

}



void makeBackground(Controller& c){

	//border of background
	float frameCoords[26][2] =
	{
	
		//background grid... dont judge
		{0.0, 8.0}, {125.0, 8.0}, {0.0, 8.0},
		{0.0, 7.0}, {125.0 , 7.0}, {0.0, 7},
		{0.0, 6.0}, {125.0, 6.0}, {0.0, 6.0},
		{0.0, 5.0}, {125.0, 5.0}, {0.0, 5.0},
		{0.0, 4.0}, {125.0, 4.0}, {0.0, 4.0},
		{0.0, 3.0}, {125.0, 3.0}, {0.0, 3.0},
		{0.0, 2.0}, {125.0, 2.0}, {0.0, 2.0},
		{0.0, 1.0}, {125.0, 1.0}, {0.0, 1.0},
		{0.0, 0.0}, {125.0, 0.0}
		
	
	};
	
	//pass the coords
	c.addModel(new ModelView (frameCoords));
	
}

void makeLines(Controller& c){

	//pass coords and its color number
	c.addModel(new ModelView (line1, 1));
	c.addModel(new ModelView (line2, 2));
	c.addModel(new ModelView (line3, 3));	
	c.addModel(new ModelView (line4, 4));

}


int main(int argc, char* argv[])
{
	GLFWController c(argv[0]);
	c.reportVersions(std::cout);

  	buildData();
  	
  	
	// TODO: one or more ModelView dynamic allocations, adding
	//       each to the Controller using "c.addModel(...);"
	
	// initialize 2D viewing information:
	// Get the overall scene bounding box in Model Coordinates:
	double xyz[6]; // xyz limits, even though this is 2D
	c.getOverallMCBoundingBox(xyz);
	// Simplest case: Just tell the ModelView we want to see it all:
	//overwriting the getMCBoundingbox, didnt seem to be working.. I think I messed up 
	//using it or something just setting mins and maxs here
	xyz[0]=-5;
	xyz[1]=130;
	xyz[2]=-3;
	xyz[3]= 10;
	xyz[4]=-1;
	xyz[5]=1;
	
	ModelView::setMCRegionOfInterest(xyz);
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	makeLines(c);
  	makeBackground(c);
  	
	c.run();

	return 0;
}



