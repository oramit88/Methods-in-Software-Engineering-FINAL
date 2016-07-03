#include "MessageBoxx.h"



MessageBoxx::~MessageBoxx()
{
}

void MessageBoxx::draw(Graphics graphics, int left, int top, int layer) {
	if (cancel.flag) {
		Panel::draw(graphics, left, top, layer);
		graphics.write(left + 1, top + 1, _title);
		graphics.write(left + 1, top + 2, _text);
	}
}

void MessageBoxx::mousePressed(int x, int y, bool ifFirstButton) {
	//cout << "x is:" << x;
	//cout << "y is:" << y;
	//_ok.mousePressed(x, y, ifFirstButton);//crush 
//	cout << "aaa" << x;
	Panel::mousePressed(x, y, ifFirstButton);
}



