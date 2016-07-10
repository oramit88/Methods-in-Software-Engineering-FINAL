#include "Control.h"

Control* Control::_inFocus = nullptr;

 void Control::draw(Graphics graphics, int left, int top, int layer) {
	 if (layer != getZIndex()) {
		 return;
	 }
	string borderCharHorizontal;
	string borderCharVertical;
	
	int newXPos = left;
	int newYPos = top;
	
	graphics.moveTo(newXPos,newYPos);

	switch (_border) {
		case BorderType::Single: {
			borderCharVertical = "-";
			borderCharHorizontal = "|";
			break;
		}
		case BorderType::Double: {
			borderCharVertical = "=";
			borderCharHorizontal = "||";
			break;
		}
		case BorderType::None: {
			borderCharVertical = " ";
			borderCharHorizontal = " ";
		}
	}
	
	for (int rows = 0; rows <_height; rows++) {
		for (int col = 0; col < _width; col++) {
			if (col == 0 || col == (_width - 1) || rows == 0 || (rows == _height - 1)) {
				if(rows == 0 || (rows == _height - 1)){
					cout<<borderCharVertical;
				}
				else {
					cout <<borderCharHorizontal;
				}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		newYPos++;
		graphics.moveTo(newXPos, newYPos);
	}
}
