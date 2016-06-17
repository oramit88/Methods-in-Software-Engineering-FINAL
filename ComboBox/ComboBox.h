#pragma once
#include "../Button/Button.h"
#include "../Radiolist/Radiolist.h"

struct DropdownButtonListener : public MouseListener {
	DropdownButtonListener() {}
	bool flag = false;
	void MousePressed(int x, int y, bool isLeft){
		if (flag) {
			flag = false;
		}
		else {
			flag = true;
		}
	}
};


class ComboBox : public Control {
	Button dropdown;
	Radiolist list;
	DropdownButtonListener listener;
	int panelLeft = 0;
	int panelTop = 0;

public:
	ComboBox(int width, vector<string> options) :Control(width, 3 + options.size() + 2),
		dropdown(width), list(options.size() + 2, width, options) {
		dropdown.SetText(options[0]);
		dropdown.AddListener(listener);
		dropdown.SetBorder(BorderType::Single);
		list.SetBorder(BorderType::Single);
	}
	void mousePressed(int x, int y, bool ifFirstButton);
	void draw(Graphics graphics, int left, int top, int layer);
	void keyDown(WORD code, CHAR chr) {}//todo
	bool canGetFocus() { return true; }
	~ComboBox();
};