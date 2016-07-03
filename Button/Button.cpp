#include "Button.h"

void Button::mousePressed(int x, int y, bool ifFirstButton) {
	/*
	cout << "(";
	cout<<x;
	cout<<",";
	cout<<y;
	cout<<")";
	cout << "_left:";
	cout << _left;
	cout << "_top:";
	cout << _top;
		getchar();
		*/
	if (isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height)) {

		for (int i = 0;i < listeners.size();i++) {
			//cout << "test" << endl;
			listeners[i]->MousePressed(x, y, ifFirstButton); //dima cresh (5,6,TRUE)
		}
	}
}
void Button::draw(Graphics graphics, int left, int top, int layer) {
	if (layer != getZIndex()) {
		return;
	}
	Label::draw(graphics, _left + left, _top + top, layer);
	panelLeft = left;
	panelTop = top;
	graphics.setCursorVisibility(false);
}
Button::~Button()
{
}
