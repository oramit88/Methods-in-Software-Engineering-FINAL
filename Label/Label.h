#pragma once
#include "../SoftwareEng/Control.h"
class Label:public Control
{
	string _value;
public:
	Label(int width, string value):Control(width,3), _value(value){}
	Label(int width) :Control(width, 3){}
	void SetText(string value) { _value = value; }
	 void draw(Graphics graphics, int left, int top, int layer);
	~Label();

	void keyDown(WORD code, CHAR chr) {};
	void mousePressed(int x, int y, bool ifFirstButton) {};
	 bool canGetFocus() { return false; }

};

