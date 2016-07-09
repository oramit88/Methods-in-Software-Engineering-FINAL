#pragma once
#include "../SoftwareEng/Control.h"


class TextBox :
	public Control
{
	string _value = "";
	int textSize;
	int maxSize;
	int logicalPosition = 0;
	Graphics _graphics;
	int panelLeft = 0;
	int panelTop = 0;
public:
	virtual void draw(Graphics graphics, int left, int top, int layer);
	virtual void keyDown(WORD code, CHAR chr);
	virtual void mousePressed(int x, int y, bool ifFirstButton);
	virtual bool canGetFocus() { return true; }
	string GetValue() { return _value; }
	TextBox(int width) :Control(width, 3) {}
	void SetText(string value) {
		_value = value;
		logicalPosition = _value.size();
	}
	string GetText() { return _value; }
	void nowInFocus() {
		graphics.moveTo(_left + 2 + logicalPosition, _top + 2);
		_graphics.setCursorVisibility(true);
	}
	~TextBox();
};
