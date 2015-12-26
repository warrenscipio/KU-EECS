// test.c++

#include "ControllerSub.h"
//#include "project2.c++"

ControllerSub::ControllerSub(const std::string& windowTitle, int rcFlags)
: GLFWController(windowTitle, rcFlags)
{

  leftPressed = false;
  currentX = 0;
  currentY = 0;
}
ControllerSub::~ControllerSub() {

}

void ControllerSub::handleAsciiChar(unsigned char theChar, int x, int y)
{
  if (theChar=='o'){
    ModelView::setProjection(ORTHOGONAL);

  }else if (theChar=='p'){
    ModelView::setProjection(PERSPECTIVE);

  }else if (theChar=='q'){

    ModelView::setProjection(OBLIQUE);

  }else if (theChar=='c'){
    //made some changes
    //  ModelView::resetRotation();

  }
}

void ControllerSub::handleMouseButton(MouseButton button, bool pressed, int x, int y, int mods)
{
  if(button == LEFT_BUTTON){
  	//std::cout<<"clicked"<<std::endl;

    if (pressed)
    {
      leftPressed= true;
      currentX = x;
      currentY = y;
    }
    else
      leftPressed= false;
  }
}

void ControllerSub::handleMouseMotion(int x, int y)
{
  if (leftPressed)
  {
			//std::cout<<"clicked and moving"<<std::endl;
    int dx = x - currentX;
    int dy = y - currentY;
    currentX = x;
    currentY = y;

    //TODO: apply rotation
    ModelView::addToGlobalRotationDegrees(dx/2, dy/2, 0);
  }
}

void ControllerSub::handleScroll(bool up)
{
	if(up)
  	ModelView::addToGlobalZoom(.50 );
	else
		ModelView::addToGlobalZoom( 1.5);

}
