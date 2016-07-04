#include "NumericBox.h"


NumericBox::~NumericBox()
{
}

void NumericBox::SetValue(int val) {
	if (val <= _maxVal&&val>=_minVal) {
		_val = val;
		minus.currentNum = _val;
		plus.currentNum = _val;
	}
}


void NumericBox::draw(Graphics graphics, int left, int top, int layer) {
	Panel::draw(graphics, left, top, layer);
	int realVal = GetValue();
	graphics.write(left + 1, top + 1, to_string(realVal));
	if (minus.needToReduce) {
		minus.currentNum--; //new
		SetValue(minus.currentNum);
		minus.needToReduce = false; //new
	}
	if (plus.needToAdd) {
		plus.currentNum++; //new
		SetValue(plus.currentNum);
		plus.needToAdd = false; //new
	}


	
}

void NumericBox::mousePressed(int x, int y, bool ifFirstButton) {
	Panel::mousePressed(x, y, ifFirstButton);
}
