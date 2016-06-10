#include "Checklist.h"


void Checklist::draw(Graphics graphics, int left, int top, int layer) {	//TODO COLORS
	Control::draw(graphics, _left + left, _top + top, layer);
	panelLeft = left;
	panelTop = top;
	int vector_size = _options.size();
	graphics.moveTo(left + _left + 1 , top  + _top +1);
	for (int i = 0;i < vector_size;i++) {
		graphics.write(_options[i]);
		graphics.moveTo(left + _left + 1, top + _top + i + 2);
	}
	moveCursorToFocusedControl();
	/*
	Component::draw();
	CONSOLE_CURSOR_INFO cci = { 100, TRUE };
	SetConsoleCursorInfo(_handle, &cci);
	int vector_size = _data.size();
	COORD temp = _position.getStartCord();
	temp.X++;
	temp.Y++;
	SetConsoleCursorPosition(_handle, temp);

	for (int i = 0; i < vector_size;i++){
		if (i == 0) {
	
			DWORD wAttr;
			if (needFirstYellow) {
				 wAttr = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(_handle, wAttr);
				needFirstYellow = false;
			}
			cout << _data[i]<<endl;
			wAttr = _textColor | _backgroundColor;
			SetConsoleTextAttribute(_handle, wAttr);
			temp.Y++;
			
		}
		else {//next 
			SetConsoleCursorPosition(_handle, temp);
			cout << _data[i] << endl;
			temp.Y++;
		}
}
	*/
}
void Checklist::keyDown(WORD code, CHAR chr) {
	if (code == 0x46) { // F key for debaging
		_graphics.moveTo(15, 15);
		stringstream ss;
		for (int i = 0; i < _selectedIndices.size();i++) {
			ss << _selectedIndices[i] << ",";
			_graphics.write(ss.str());
		}
		getchar();
	}
	switch (code) {
		case VK_UP: {
			if (logicalPosition > 0) {
				logicalPosition--;
				//	 _graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
			}
			else {
				logicalPosition = _options.size()-1;
			}
			break;
		}
		case VK_DOWN:{
			if (logicalPosition < _options.size() - 1) {
				logicalPosition++;
			//	 _graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
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
	}
}

void Checklist::mousePressed(int x, int y, bool ifFirstButton) {
	if (!ifFirstButton || !isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height) || 
		x != _left + panelLeft + 2) {
		return;
	}

	int pressed = y - panelTop - 2;	
	if (pressed >= _options.size()) {
		return;
	}
	logicalPosition = pressed;
	selectOption();
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
	if (indexInVector()) {
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, " ");
		for (int i = 0; i < _selectedIndices.size();i++) {// BAG 
			if (_selectedIndices[i] == logicalPosition) {
				_selectedIndices.erase(_selectedIndices.begin() + i);
			}
		}
	}
	else {
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, "X");
		_selectedIndices.push_back(logicalPosition);
	}
}

bool Checklist::indexInVector() {
	for (int i = 0; i < _selectedIndices.size();i++) {
		if (_selectedIndices[i] == logicalPosition) {
			return true;
		}
	}
	return false;
}

Checklist::~Checklist()
{
}
