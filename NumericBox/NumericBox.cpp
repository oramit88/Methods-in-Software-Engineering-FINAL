#include "NumericBox.h"


NumericBox::~NumericBox()
{
}

void NumericBox::draw(Graphics graphics, int left, int top, int layer) {
	Panel::draw(graphics, left, top, layer);
	int realVal = GetValue();
	graphics.write(left + 1, top + 1, to_string(realVal));
	if (minus.needToReduce) {
		SetValue(minus.currentNum);
	}
	if (plus.needToAdd) {
		SetValue(plus.currentNum);
	}


	
}

void NumericBox::mousePressed(int x, int y, bool ifFirstButton) {
	Panel::mousePressed(x, y, ifFirstButton);
}
