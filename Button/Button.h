#pragma once
#include <vector>
#include "../SoftwareEng/MouseListener.h"
#include "../Label/Label.h"
class Button:public Label
{
	vector<MouseListener*> listeners;
	int panelLeft = 0;
	int panelTop = 0;
public:
	Button(int width):Label(width,""){}
	void draw(Graphics graphics, int left, int top, int layer);
	void SetValue(string value) { Label::SetValue(value); }
	bool canGetFocus() { return false; }
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool ifFirstButton);
	~Button();
};

