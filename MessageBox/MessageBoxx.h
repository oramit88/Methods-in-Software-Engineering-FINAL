#pragma once
#include "../SoftwareEng/Control.h"
#include "../Button/Button.h"
#include "../Panel/Panel.h"

class OnClickOk : public MouseListener
{
	public:
		OnClickOk() { }
		void MousePressed(int x, int y, bool isLeft)
		{
			cout << "OK";
			getchar();
	
		}
	private:
};

class OnClickCancel : public MouseListener
{
public:
	bool flag = true;
	void MousePressed(int x, int y, bool isLeft) {
		if (flag) {
			flag = false;
		}
	}
private:
};



class MessageBoxx :public Panel
{

private:
	string _title;
	string _text;
	OnClickOk ok;
	OnClickCancel cancel;
protected:
	Button _ok, _cancelled; 
public:
	MessageBoxx(int height, int width) :Panel(width, height), _ok(4), _cancelled(10) {
		setZIndex(4);
		_ok.setZIndex(5);
		_ok.SetText("OK");
		
		_ok.SetBorder(BorderType::Single);
		_ok.AddListener(ok);
		//_ok.setLeft(_left);
		//_ok.setTop(_top + 3);
		Panel::AddControl(_ok, getLeft(), getTop() + 1);

		//_cancelled.setLeft(_left + _width - 1 - _cancelled.getWidth());
		//_cancelled.setTop(_top + 3);
		_cancelled.SetText("Cancel");
		_cancelled.setZIndex(5);
		_cancelled.SetBorder(BorderType::Single);
		_cancelled.AddListener(cancel);
		Panel::AddControl(_cancelled, getLeft()+3, getTop()+1 );
	}
	void draw(Graphics graphics, int left, int top, int layer);
	void SetText(string text) { _text = text; }
	void SetTitle(string title) { _title = title; }

	void keyDown(WORD code, CHAR chr) {};
	void mousePressed(int x, int y, bool ifFirstButton);
	bool canGetFocus() { return false; }
	~MessageBoxx();
};

