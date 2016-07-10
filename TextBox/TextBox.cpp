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
		if (logicalPosition >= 1) {
			logicalPosition--;
			graphics.moveTo(_left + 1 + _value.size(), _top + 2);
		}
		break;
	}

	case VK_BACK: {
		if (logicalPosition  > 0) {
			logicalPosition--;
			_value.erase(logicalPosition , 1);
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
	if (isVisible()) {
		int pressed = x - _left - 2;
		int yTest=y;
		if (pressed >= _value.size()||(yTest!= _top + 2)) { //checking if the mouse is on the textbox.
			return;
		}
		Control::setFocus(*this);

		logicalPosition = pressed;
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

TextBox::~TextBox()
{
}