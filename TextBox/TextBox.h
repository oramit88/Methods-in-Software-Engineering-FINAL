#pragma once
#include "../SoftwareEng/Control.h"


class TextBox :
	public Control
{
	string _value = "";
	int textSize;
	int maxSize;
//	COORD position;
public:
	virtual void draw(Graphics graphics, int left, int top, int layer);
	virtual void keyDown(WORD code, CHAR chr);
	virtual void mousePressed(int x, int y, bool ifFirstButton) {};
	virtual bool canGetFocus() {	return true;}

//	virtual void keyDown(KEY_EVENT_RECORD keyEvent);
//	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent);
	string GetValue() { return _value; }
	//virtual void createFrame() = 0; // replace to draw
//	virtual void draw();
//	virtual void hide();
	TextBox(int width):Control(width,3){}
	void SetText(string value) { _value = value; }
	string GetText() { return _value; }
	/*
	TextBox(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle, int width, string text = "")
		:Component(coord, backgroundColor, textColor, handle) {
		_text = text;
		_position.setHeight(3);
		_position.setWidth(width);
		textSize = text.size();
		maxSize = width - 2;
		position = _position.getStartCord();
		position.X++;
		position.Y++;
	}
*/
	~TextBox();
};
