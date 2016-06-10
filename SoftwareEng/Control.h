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
	
protected:
	Graphics graphics;
	HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
	BorderType _border = BorderType::None;
	ForegroundColor _foregroundColor;
	BackgroundColor _backgroundColor;
	bool _isVisible;
	bool _isFocused;
	int _width, _height,_top,_left;
	static Control* _inFocus;
public:

	static Control* getFocus() { return _inFocus; }

	Control(int width, int height) :_width(width), _height(height), _top(0),_left(0){}
	~Control() {};
	virtual void moveCursorToFocusedControl(){}
	static void setFocus(Control &control) {
		_inFocus = &control;
		_inFocus->moveCursorToFocusedControl();
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
	virtual void SetForeground(ForegroundColor color) { _foregroundColor = color; }
	virtual void SetBackground(BackgroundColor color) { _backgroundColor = color; }
	virtual void SetBorder(BorderType border) { _border = border; }
	virtual void draw(Graphics graphics,int left, int top, int layer);
	virtual void keyDown(WORD code, CHAR chr) = 0;
	virtual void mousePressed(int x, int y, bool ifFirstButton) = 0;
	virtual bool canGetFocus() = 0;
	virtual void getAllControls(vector<Control*> *controls){}


	/* for debaging*/
	void debag(Graphics _graphics, int text) {
		_graphics.moveTo(15, 15);
		stringstream ss;
		ss << text << "";
		_graphics.write(ss.str());
		getchar();
	}
	void debag(Graphics _graphics, string text) {
		_graphics.moveTo(15, 15);
		stringstream ss;
		ss << text << "";
		_graphics.write(ss.str());
		getchar();
	}

};

