#include "Button.h"

void Button::mousePressed(int x, int y, bool ifFirstButton) {
	if (isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height)) {
		for (int i = 0;i < listeners.size();i++) {
			listeners[i]->MousePressed(x, y, ifFirstButton); 
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
