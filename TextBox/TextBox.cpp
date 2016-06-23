#include "TextBox.h"

void TextBox::keyDown(WORD code, CHAR c) {

	if (_value.size() < _width - 2) {
		if (c >= ' ' && c <= '~') {
			cout << c;
			_value += c;
			graphics.moveTo(_left + 1 + _value.size(), _top + 1);
			return;
		}
	}

	switch (code) {
	case VK_RIGHT: {
		
		logicalPosition = _value.size();
		if (logicalPosition < _width - 2) {
			logicalPosition++;

			graphics.moveTo(_left + 1 + logicalPosition, _top + 2);
		}
		getchar();
		break;
	}
	case VK_LEFT: {

		logicalPosition = _value.size();
		if (logicalPosition > _width - 2) {
			logicalPosition--;
			graphics.moveTo(_left + 1 + logicalPosition, _top + 2);

		}
		//	COORD startCord = _position.getStartCord();
		//	startCord.X++;
		//	if (position.X > startCord.X) {
		//		position.X--;
		//		SetConsoleCursorPosition(_handle, position);


		break;
	}
	case VK_BACK: {
		logicalPosition = _left + 2;
		if (_value.size() != 0) {
			_value.pop_back();
			logicalPosition--;
			graphics.moveTo(_left + 1 + logicalPosition, _top + 2);
			cout << " ";
			
		}
		break;
	}

	}
}
//void TextBox::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {

//}


void  TextBox::draw(Graphics graphics, int left, int top, int layer) {
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