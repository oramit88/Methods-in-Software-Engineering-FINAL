#include "TextBox.h"

void TextBox::keyDown(WORD code, CHAR c) {
	if (code == 0x46) { // F key for debaging
		string str = "";
		_graphics.write(10, 10, _value);
		getchar();
	}
	if (_value.size() < _width - 2) {
		if (c >= ' ' && c <= '~') {
			cout << c;
			if (_value.size() == logicalPosition - 1) {
				_value += c;
			}
			else {
				char temp[] = { c };
				_value.insert(logicalPosition, temp, 1);
			}
			graphics.moveTo(_left + 1 + _value.size(), _top + 1);
			logicalPosition++;
			return;
		}
	}

	switch (code) {
	case VK_RIGHT: {

		if (_value.size() < _width - 3) {
			logicalPosition++;
			_value += " ";
			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
		}
		break;
	}
	case VK_LEFT: {
		if (logicalPosition > 1) {
			logicalPosition--;
			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
		}
		break;
	}

	case VK_BACK: {
		if (logicalPosition  > 0) {
			logicalPosition--;
			_value.erase(logicalPosition - 1, 1);
		}
		break;
	}


	case VK_DELETE: {
		if (logicalPosition > 0) {

			_value.erase(logicalPosition, 1);
		}
		break;
	}

	}
}


void TextBox::mousePressed(int x, int y, bool ifFirstButton) {
	if (!ifFirstButton || !isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height) ||
		x != _left + panelLeft + 2) {
		return;
	}
}
void  TextBox::draw(Graphics graphics, int left, int top, int layer) {
	if (layer != getZIndex()) {
		return;
	}
	Control::draw(graphics, left, top, layer);
	graphics.setCursorVisibility(true);
	graphics.write(left + 1, top + 1, _value);
	graphics.moveTo(left + 1 + _value.size(), top + 1);

}



/*
void TextBox::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {

#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif

switch (mouseEvent.dwEventFlags)
{
case 0:

if (mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
{
COORD mouseCoord = mouseEvent.dwMousePosition;
int myPosi = _position.getStartCord().X + 1;
if (mouseCoord.X - myPosi >-1 & maxSize - mouseCoord.X>-3) {
SetConsoleCursorPosition(_handle, mouseCoord);
}
}
else if (mouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
{

}
else
{

}
break;
case DOUBLE_CLICK:

break;
case MOUSE_HWHEELED:

break;
case MOUSE_MOVED:

break;
case MOUSE_WHEELED:

break;
default:

break;
}
}


*/



TextBox::~TextBox()
{
}