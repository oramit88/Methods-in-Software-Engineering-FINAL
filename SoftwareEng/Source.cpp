
#include <string>
#include "EventEngine.h"
#include "../TextBox/TextBox.h"
#include"../Label/Label.h"
#include"../Panel/Panel.h"
#include "../Checklist/Checklist.h"
#include "../Radiolist/Radiolist.h"
#include "../Button/Button.h"
#include "../ComboBox/ComboBox.h"
#include "MouseListener.h"
#include "Graphics.h"
#include"../MessageBox/MessageBoxx.h"
using namespace std;
Graphics graphics;
class MyListener : public MouseListener
{
public:
	MyListener(Control &c) : _c(c) { }
	void MousePressed( int x, int y, bool isLeft)
	{
		_c.SetBorder(BorderType::None);
	}
private:
	Control &_c;
};
int main(int argc, char **argv)
{
	MessageBoxx msgBox(8, 20);
	msgBox.SetBorder(BorderType::Single);
	msgBox.SetTitle("MegBox Title");
	msgBox.SetText("My MegBox Text");

	Label lName(20);
	lName.SetText("Name: ");
	lName.SetBorder(BorderType::Single);
	Radiolist rSex(6, 15, { "Male", "Female" });
	rSex.SetBorder(BorderType::Single);
	Checklist clInterests(6, 15, { "Sports", "Books", "Movies" });
	ComboBox clInterests2(30, { "select hobbies:", "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	clInterests.SetBorder(BorderType::Single);
	clInterests2.SetBorder(BorderType::Double);
	MyListener listener(lName);
	Button bSubmit(10);
	bSubmit.SetText("Submit");
	bSubmit.AddListener(listener);
	bSubmit.SetBorder(BorderType::Double);
	Panel main;
	main.AddControl(lName, 6, 10);
	main.AddControl(rSex, 1, 1);
	main.AddControl(msgBox, 15, 15);
	//main.AddControl(clInterests, 10, 1);
	main.AddControl(clInterests2, 25, 1);
	main.AddControl(bSubmit, 20, 8);
	Control::setFocus(rSex);
	EventEngine engine;
	engine.run(main);
	return 0;
}

