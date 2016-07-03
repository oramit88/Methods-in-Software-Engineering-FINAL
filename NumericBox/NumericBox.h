#pragma once
#include "../SoftwareEng/Control.h"
#include "../Button/Button.h"
#include "../Panel/Panel.h"

class OnClickPlus : public MouseListener
{
		public:
			bool needToAdd = false;
			int currentNum;
			void MousePressed(int x, int y, bool isLeft)
			{
				needToAdd = true;
				currentNum++;

			}
		private:
};

class OnClickMinus : public MouseListener
{
		public:
			bool needToReduce = false;
			int currentNum;
			void MousePressed(int x, int y, bool isLeft) {
				needToReduce = true;
				currentNum--;
			}	
		private:
};





class NumericBox :public Panel
{
private:
	int _val,_maxVal;
	OnClickPlus plus;
	OnClickMinus minus;
protected:
	Button _plus, _minus; 


public:
	NumericBox(int height, int width,int maxVal) :Panel(width, height), _plus(3), _minus(3),_maxVal(maxVal) {
		setZIndex(4);
		_plus.setZIndex(5);
		_plus.SetText("+");
		_plus.SetBorder(BorderType::Single);
		_plus.AddListener(plus);
		Panel::AddControl(_plus, getLeft(), getTop() + 1);
		
		_minus.SetText("-");
		_minus.setZIndex(5);
		_minus.SetBorder(BorderType::Single);

		minus.currentNum = GetValue();

		_minus.AddListener(minus);
		Panel::AddControl(_minus, getLeft() + 3, getTop() + 1);
	}
	void draw(Graphics graphics, int left, int top, int layer);
	void SetValue(int val) { 
		_val = val;
		minus.currentNum = _val;
		plus.currentNum = _val;
	}
	int GetValue() {return _val; }
	void keyDown(WORD code, CHAR chr) {};
	void mousePressed(int x, int y, bool ifFirstButton);
	bool canGetFocus() { return false; }
	~NumericBox();
};

