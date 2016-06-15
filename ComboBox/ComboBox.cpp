#include "ComboBox.h"


void ComboBox::mousePressed(int x, int y, bool ifFirstButton) {

	// to do liza
	// check if pressed on button or droplist
	// !! problem dima or !!
	if (isInside(x, y, _left , _top , _width, _height)) {
		listener.flag = !listener.flag;
	}
}

void ComboBox::draw(Graphics graphics, int left, int top, int layer) {
	panelLeft = left;
	panelTop = top;
	//Control::draw(graphics, left, top, layer);
	dropdown.draw(graphics,left,top,layer);
	if (listener.flag) {
		list.draw(graphics, left, top+2, layer);
	}

	// to do implent lize. dont forget flag. if flag is true
	// draw 2 controllers if flase only one (button)
}

ComboBox::~ComboBox()
{
}

