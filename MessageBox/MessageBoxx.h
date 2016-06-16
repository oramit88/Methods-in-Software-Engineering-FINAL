#pragma once
#include "../SoftwareEng/Control.h"
#include "../Button/Button.h"

class OnClickOk : public MouseListener
{
public:
	OnClickOk(Control &c) : _c(c) { }
	void MousePressed(int x, int y, bool isLeft)
	{
		_c.SetBorder(BorderType::None);
	}
private:
	Control &_c;
};

class OnClickCancel : public MouseListener
{
public:
	OnClickCancel() {}
	void MousePressed(int x, int y, bool isLeft)
	{

	}
};



class MessageBoxx :public Control
{
private:
	string _title;
	string _text;
protected:
	Button _ok, _cancelled; //dima
public:
	MessageBoxx(int height, int width) :Control(width, height), _ok(4), _cancelled(10) {
		_ok.SetText("OK");
		_ok.SetBorder(BorderType::Single);
		_cancelled.SetText("Cancel");
		_cancelled.SetBorder(BorderType::Single);
		OnClickOk ok(_cancelled);
		_ok.AddListener(ok);
		OnClickCancel cancel;
		_cancelled.AddListener(cancel);
	}
	void draw(Graphics graphics, int left, int top, int layer);
	void SetText(string text) { _text = text; }
	void SetTitle(string title) { _title = title; }

	void keyDown(WORD code, CHAR chr) {};
	void mousePressed(int x, int y, bool ifFirstButton);
	bool canGetFocus() { return false; }
	~MessageBoxx();
};

