#include "Label.h"

void Label::draw(Graphics graphics, int left, int top, int layer) {
	if (layer != getZIndex()) {
		return;
	}
	Control::draw(graphics, left,  top,  layer);
	graphics.write(left+1,top+1,_value);
}

Label::~Label()
{
}

