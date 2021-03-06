#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>	// for testing
#include "Graphics.h"
using namespace std;
enum class BorderType { Single, Double, None };
enum class ForegroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };
enum class BackgroundColor { Red, Blue, Green, Purple, Teal, Yellow, White, Black };

class Control
{
	int _zIndex = 0;
	bool _isVisible;
	bool _isFocused;
	ForegroundColor _foregroundColor;
	BackgroundColor _backgroundColor;
protected:
	Graphics graphics;
	HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
	BorderType _border = BorderType::None;


	int _width, _height,_top,_left;
	
	static Control* _inFocus;
public:

	static Control* getFocus() { return _inFocus; }

	Control(int width, int height) :_width(width), _height(height), _top(0),_left(0),_isVisible(true){}
	~Control() {};
	static void setFocus(Control &control) {
		_inFocus = &control;
		_inFocus->nowInFocus();
		control.setZIndex(5);
	}
	int getZIndex() {
		return _zIndex;
	}
	void setZIndex(int zIndex) {
		_zIndex = zIndex;
	}
	int getWidth() {
		return _width;
	}
	void setTop(int top) {
		 _top=top;
	}

	int getTop() {
		return _top;
	}
	void setLeft(int left) {
		_left = left;
	}

	int getLeft() {
		return _left;
	}

	virtual void Show() {
		_isVisible = true;
	}
	virtual void Hide() {
		_isVisible = false;
	}
	bool isVisible() {
		return _isVisible;
	}


	virtual void SetForeground(ForegroundColor color) { _foregroundColor = color; }
	virtual void SetBackground(BackgroundColor color) { _backgroundColor = color; }
	virtual void SetBorder(BorderType border) { _border = border; }
	virtual void draw(Graphics graphics,int left, int top, int layer);
	virtual void keyDown(WORD code, CHAR chr) = 0;
	virtual void mousePressed(int x, int y, bool ifFirstButton) = 0;
	virtual bool canGetFocus() = 0;
	virtual void getAllControls(vector<Control*> *controls){ controls->push_back(this);}
	virtual void nowInFocus(){}
};

