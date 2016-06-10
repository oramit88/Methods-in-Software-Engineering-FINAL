#pragma once
#include "../SoftwareEng/Control.h"
#include "../SoftwareEng/Graphics.h"
class Checklist : public Control
{

;
protected:
	vector<size_t> _selectedIndices;
	vector <string> _options;
	int logicalPosition = 0;
	int cursorPosX;
	int cursorPosY;
	int panelLeft = 0;
	int panelTop = 0;
	Graphics _graphics;
	virtual void selectOption();
	bool indexInVector();
public:
	Checklist(int height, int width, vector<string> options):Control(width,height),_options(options){
		int size = _options.size();
		for (int i = 0; i < size; i++) {
			_options[i].insert(0, "[ ] ");
		}
		cursorPosX = _left +2;
		cursorPosY = _top + 1;
	}
	 void moveCursorToFocusedControl() {
		 _graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_graphics.setCursorVisibility(true);
	}

	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	vector<size_t> GetSelectedIndices() { return _selectedIndices; }
	 void draw(Graphics graphics, int left, int top, int layer);
	 void keyDown(WORD code, CHAR chr);
	 void mousePressed(int x, int y, bool ifFirstButton) ;
	 bool canGetFocus() { return true; }
	~Checklist();
};
