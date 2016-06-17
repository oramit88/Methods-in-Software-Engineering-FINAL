#include "MessageBoxx.h"



MessageBoxx::~MessageBoxx()
{
}

void MessageBoxx::draw(Graphics graphics, int left, int top, int layer) {
	Control::draw(graphics, left, top, layer);
	graphics.write(left + 1, top + 1, _title);
	graphics.write(left + 1, top + 2, _text);
	_ok.draw(graphics, left + 1, top + 3, layer + 1);
	_cancelled.draw(graphics, left + _width - 1 - _cancelled.getWidth(), top + 3, layer + 1);
}

void MessageBoxx::mousePressed(int x, int y, bool ifFirstButton) {
	cout << "x is:" << x;
	cout << "y is:" << y;
	_ok.mousePressed(x, y, ifFirstButton);//crush 
	cout << "aaa" << x;
}



