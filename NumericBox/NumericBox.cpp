#include "NumericBox.h"


NumericBox::~NumericBox()
{
}

void NumericBox::SetValue(int val) {
	if (val <= _maxVal&&val>=_minVal) { 
		_val = val;
		//updating the two values
		minus.currentNum = _val;
		plus.currentNum = _val;
	}
}


void NumericBox::draw(Graphics graphics, int left, int top, int layer) {
	Panel::draw(graphics, left, top, layer); //drawing the numericBox element (frame+buttons)
	int realVal = GetValue();
	graphics.write(left + 1, top + 1, to_string(realVal)); //printing the current value to the screen.
	if (minus.needToReduce) {//pressing on minus button.
		minus.currentNum--; //reduce the local variable of the button
		SetValue(minus.currentNum); //updating the NumericBox value variable
		minus.needToReduce = false; 
	}
	if (plus.needToAdd) { //pressing on plus button.
		plus.currentNum++; //increase the local variable of the button
		SetValue(plus.currentNum); //updating the NumericBox value variable
		plus.needToAdd = false; 
	}	
}

void NumericBox::mousePressed(int x, int y, bool ifFirstButton) {
	Panel::mousePressed(x, y, ifFirstButton);
}
