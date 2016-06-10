#include "Radiolist.h"

void Radiolist::selectOption() {
	
	if (selectedPosition == logicalPosition) {
		_options[selectedPosition].replace(1, 1, " ");
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		selectedPosition = -1;
		return;
	}
	if (selectedPosition != -1) {
		_options[selectedPosition].replace(1, 1, " ");
	}
	selectedPosition = logicalPosition;
	_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
	_options[selectedPosition].replace(1, 1, "X");
}

Radiolist::~Radiolist()
{
}
