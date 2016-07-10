
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
#include"../NumericBox/NumericBox.h"
#include <string>
#include "EventEngine.h"


using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void MousePressed(int x, int y, bool isLeft)
	{
		_c.SetBorder(BorderType::None);
	}
private:
	Control &_c;
};
int main(int argc, char **argv)
{
	Panel main(60, 60); //panel(height,width)
	main.SetBorder(BorderType::Single); //only for testing
	
	Checklist clInterests(6, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	clInterests.SetBorder(BorderType::Single);
	main.AddControl(clInterests, 20, 10);

	TextBox tAddress(30);
	tAddress.SetValue("TextBox..221B Baker Street");
	tAddress.SetBorder(BorderType::Single);
	MyListener listener(tAddress);
	main.AddControl(tAddress, 28, 10);	
	
	Label lInterests(20);
	lInterests.SetValue("Label: Interests:");
	main.AddControl(lInterests, 28, 14);

	MessageBoxx msgBox(25, 8);
	msgBox.SetTitle("msgBox TITLE:");
	msgBox.SetText("this is my msgBox");
	msgBox.SetBorder(BorderType::Single);
	main.AddControl(msgBox, 28, 1 );
	
	ComboBox cCountry(18, { "Israel", "italy", "Germany" });
	cCountry.SetSelectedIndex(1);
	cCountry.SetBorder(BorderType::Single);
	main.AddControl(cCountry, 0, 1);
		
	NumericBox numBox(11, 0,20); //(width,minVal,maxVal)
	numBox.SetValue(10);//set the current value
	numBox.SetBorder(BorderType::Single);
	main.AddControl(numBox, 0, 20);
	
	

	Radiolist rSex(5, 15, { "Male", "Female" }); //(height, int width, vector<string> options)
	rSex.SetBorder(BorderType::Single);
	main.AddControl(rSex, 6, 10);
	
	Control::setFocus(cCountry);
	EventEngine engine;
	engine.run(main);
	return 0;
}