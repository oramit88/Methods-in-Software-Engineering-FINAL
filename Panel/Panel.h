#pragma once
#include "../SoftwareEng/Control.h"
#include <vector>
class Panel: public Control
{
	vector<Control*> controlArray;

public:
	Panel() :Control(0, 0) {}
	Panel(int height, int width):Control(width,height){}
	void AddControl(Control &control, int left, int top){ //adding a graphical element (control class) to the panel element.
		control.setLeft(left);
		control.setTop(top);
		controlArray.push_back(&control); //adding the control to the panels vector list of controls.
	}
	 void draw(Graphics graphics, int left, int top, int layer);
	 void getAllControls(vector<Control*> *controls);
	 void keyDown(WORD code, CHAR chr) {};
	 void mousePressed(int x, int y, bool ifFirstButton) {
		 for (int i = 0; i < controlArray.size();i++) {
			 controlArray[i]->mousePressed(x, y, ifFirstButton); //activating the mouse pressed functiob on the panels sons.
		 }
	 };
	 bool canGetFocus() { return false; }
	~Panel();
};

