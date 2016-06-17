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
	void SetValue(string value) { Label::SetText(value); }
<<<<<<< HEAD
	bool canGetFocus() { return false; }
=======
>>>>>>> d9b1bcf2e745e7573b4ba23f428e48e86b21f68c
	void AddListener(MouseListener &listener) { listeners.push_back(&listener); }
	void mousePressed(int x, int y, bool ifFirstButton);
	~Button();
};

