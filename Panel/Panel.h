#pragma once
#include "../SoftwareEng/Control.h"
#include <vector>
class Panel: public Control
{
	vector<Control*> controlArray;


public:
	Panel() :Control(0, 0) {}
	Panel(int height, int width):Control(width,height){}
	void AddControl(Control &control, int left, int top){
		control.setLeft(left);
		control.setTop(top);
		controlArray.push_back(&control);
	}
	 void draw(Graphics graphics, int left, int top, int layer);
	~Panel();
};

