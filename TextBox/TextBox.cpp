#include "TextBox.h"

void TextBox::keyDown(WORD code, CHAR c) {

	if(_value.size() < _width-2) {
		if (c >= ' ' && c <= '~') {
			cout << c;
			_value += c;
			graphics.moveTo(_left + 1 + _value.size()+ 1, _top + 1);
			return;
		}
	}

	switch (code) {
	case VK_RIGHT: {
		//	printf("jjjj");
		
		if (_value.size() < _width + 2) {
			graphics.moveTo(_left + 1 + _value.size() + 1, _top + 1);
			getchar();
		}
		break;
	}/*
	case VK_LEFT: {
	//	COORD startCord = _position.getStartCord();
	//	startCord.X++;
		if (position.X > startCord.X) {
			position.X--;
			SetConsoleCursorPosition(_handle, position);
		}
		break;
	}
	case VK_BACK: {
		COORD startCord = _position.getStartCord();
		startCord.X++;
		if (position.X > startCord.X) {
			_value.pop_back();
			position.X--;
			SetConsoleCursorPosition(_handle, position);
			cout << " ";
			SetConsoleCursorPosition(_handle, position);
		}
		break;
	}
	}*/
	}
}

//void TextBox::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {

//}


void  TextBox::draw(Graphics graphics, int left, int top, int layer) {
	Control::draw(graphics,left,top,layer);
//	if (_width < _value.size()) { //todo
//		graphics.write(left + 1, top + 1, _value);
//	}
	// to do-else
	graphics.write(left + 1, top + 1, _value);
	graphics.moveTo(left + 1 + _value.size(), top + 1);
	graphics.setCursorVisibility(true);
	//position.X += _value.size();
	//graphics.moveTo(newXPos,newYPos);
//	SetConsoleCursorPosition(_handle, position);

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