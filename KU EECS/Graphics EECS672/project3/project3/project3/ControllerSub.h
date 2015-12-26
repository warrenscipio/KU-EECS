#ifndef CONTROLLER_SUB_H
#define CONTROLLER_SUB_H

#include "GLFWController.h"
#include "ModelViewWithPhongLighting.h"


class ControllerSub : public GLFWController
{
public:
	ControllerSub(const std::string& windowTitle, int rcFlags = 0);
	virtual ~ControllerSub();

private:
	virtual void handleAsciiChar(unsigned char theChar, int x, int y);
	virtual void handleMouseButton(MouseButton button, bool pressed, int x, int y, int mods);
	virtual void handleMouseMotion(int x, int y);
	virtual void handleScroll(bool up);

	bool leftPressed;
	int currentX, currentY;
};

#endif
