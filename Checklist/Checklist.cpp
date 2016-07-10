#include "Checklist.h"


void Checklist::draw(Graphics graphics, int left, int top, int layer) {	//TODO COLORS
	if (layer != getZIndex()) {
		return;
	}
	Control::draw(graphics, _left + left, _top + top, layer);
	panelLeft = left;
	panelTop = top;
	int vector_size = _options.size();
	graphics.moveTo(left + _left + 1 , top  + _top +1);
	for (int i = 0;i < vector_size;i++) {
		graphics.write(_options[i]);
		graphics.moveTo(left + _left + 1, top + _top + i + 2);
	}
}
void Checklist::keyDown(WORD code, CHAR chr) {
	if (!isVisible()) {
		return;
	}
	switch (code) {
		case VK_UP: {
			if (logicalPosition > 0) {
				logicalPosition--;
			}
			else {
				logicalPosition = _options.size()-1;
			}
			break;
		}
		case VK_DOWN:{
			if (logicalPosition < _options.size() - 1) {
				logicalPosition++;
			}
			else {
				logicalPosition = 0;
			}
			break;
		}
		case VK_RETURN: {
			selectOption();
			break;
		}
		case VK_SPACE: {
			selectOption();
			break;
		}
	}
}

void Checklist::mousePressed(int x, int y, bool ifFirstButton) {
	if (!ifFirstButton || !isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height) || 
		x != _left + panelLeft + 2) {
		return;
	}
	if (isVisible()) {
	Control::setFocus(*this);
	int pressed = y - panelTop - _top - 1;
	if (pressed >= _options.size()) {
		return;
	}
	logicalPosition = pressed;
	selectOption();
	}
	
}

void Checklist::SelectIndex(size_t index){
	logicalPosition = index;
	selectOption();
}
void Checklist::DeselectIndex(size_t index){
	logicalPosition = index;
	selectOption();
}
void  Checklist::selectOption() {
	if (optionsSelected[logicalPosition]) {
		optionsSelected[logicalPosition] = false;
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, " ");
	}
	else {
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, "X");
		optionsSelected[logicalPosition] = true;
	}
}

bool Checklist::indexInVector() {
	return optionsSelected[logicalPosition];
}
vector<size_t> Checklist::GetSelectedIndices() { 
	vector<size_t> result;
	for (int i = 0; i < optionsSelected.size();i++) {
		if (optionsSelected[i] == true) {
			result.push_back(i);
		}	
	}
	return result;
}

Checklist::~Checklist()
{
}
