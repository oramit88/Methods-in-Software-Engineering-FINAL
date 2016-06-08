/*
#pragma once
#include "../SoftwareEng/Control.h"


class TextBox :
	public Control
{
	string _value;
	int textSize;
	int maxSize;
//	COORD position;
public:
	virtual void keyEvent(KEY_EVENT_RECORD keyEvent);
	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent);
//	virtual vector<string> getChoosenData();
	//virtual void createFrame() = 0; // replace to draw
	virtual void draw();
	virtual void hide();
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
/*
	~TextBox();
};
*/