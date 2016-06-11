#pragma once
#include "../Checklist/Checklist.h"
class Radiolist:public Checklist
{
	 int selectedPosition = -1;
	 void selectOption();
public:
	Radiolist(int height, int width, vector<string> options):Checklist(height,width,options){}
	size_t GetSelectedIndex() { return selectedPosition; }
	void SetSelecdetIndex(size_t index) { selectedPosition = index; }
	~Radiolist();
	bool canGetFocus() { return true; }
	/*for debaging only*/
	void keyDown(WORD code, CHAR chr) {
		if (code == 0x46) { // F key for debaging
			debag(_graphics, selectedPosition);
		}
		Checklist::keyDown(code,chr);
	}
};


