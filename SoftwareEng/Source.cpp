/*
#include"../Label/Label.h"
#include "Control.h"
int main() {
	Graphics graphics;
	Label label(10);
	label.SetText("hello");
	label.SetBorder(BorderType::Single);
	label.draw(graphics,1, 1, 0);
	graphics.setCursorVisibility(false);
	getchar();
	return 0;
}
*/

#include <string>
#include "EventEngine.h"
//#include "TextBox.h"
#include"../Label/Label.h"
#include"../Panel/Panel.h"
//#include "Button.h"
//#include "Panel.h"
//#include "NumericBox.h"
//#include "ComboBox.h"
using namespace std;
/*
struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.setForeground(Color::Red);
	}
private:
	Control &_c;
};
*/
int main(int argc, char **argv)
{
	Label lName(20);
	lName.SetText("Name: ");

	Label lAddress(20);
	lAddress.SetText("Address:");
	Label lCountry(20);
	lCountry.SetText("Counrty:");
	Label lSex(20);
	lSex.SetText("Sex:");
	Label lInterests(20);
	lInterests.SetText("Interests:");
	Label lAge(20);
	lAge.SetText("Age:");
	
//	TextBox tName(20);
//	tName.setText("Sherlock Holmes");
//	tName.setBorder(BorderType::Single);
//	TextBox tAddress(25);
//	tAddress.setText("221B Baker Street, London");
//	tAddress.setBorder(BorderType::Single);
//	ComboBox cCountry({ "Israel", "Great Britain", "United States" }, 20);
//	cCountry.setSelectedIndex(1);
//	cCountry.setBorder(BorderType::Single);
//	Radiolist rSex(2, 15, { "Male", "Female" });
//	rSex.setBorder(BorderType::Single);
//	Checklist clInterests(3, 15, { "Sports", "Books", "Movies" });
//	clInterests.selectIndex(1);
//	clInterests.setBorder(BorderType::Single);
//	NumericBox nAge(15, 18, 120);
//	nAge.setValue(23);
//	nAge.setBorder(BorderType::Single);
//	MyListener listener(tAddress);
//	Button bSubmit(10);
//	bSubmit.setText("Submit");
//	bSubmit.addListener(listener);
//	bSubmit.setBorder(BorderType::Double);
	lName.SetBorder(BorderType::Single);
	lAddress.SetBorder(BorderType::Single);
	lCountry.SetBorder(BorderType::Single);
	Panel main;
	main.AddControl(lName, 10, 3);
	main.AddControl(lAddress, 1, 9);
	main.AddControl(lCountry, 1, 18);
	//main.AddControl(lSex, 1, 11);
	//main.AddControl(lInterests, 1, 15);
	//main.AddControl(lAge, 1, 20);
	/*
	main.addControl(tName, 25, 2);
	main.addControl(tAddress, 25, 5);
	main.addControl(cCountry, 25, 8);
	main.addControl(rSex, 25, 11);
	main.addControl(clInterests, 25, 15);
	main.addControl(nAge, 25, 20);

	main.addControl(bSubmit, 1, 22);
*/
	//Control::setFocus(tName);

	EventEngine engine;
	engine.run(main);
//	Graphics g;
//	main.draw(g, 0, 0, 0);
	return 0;
}

