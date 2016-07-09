
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

//test commit and push

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
	Panel main(60, 60);
	main.SetBorder(BorderType::Single); //for testing
	
	NumericBox nAge(15, 18, 120);
	nAge.SetValue(23);
	nAge.SetBorder(BorderType::Single);



	Label lName(20);
	lName.SetText("Name: ");
	main.AddControl(lName, 1, 2);
	
	
	Label lAddress(20);
	lAddress.SetText("Address:");
	main.AddControl(lAddress, 1, 5);

	Label lCountry(20);
	lCountry.SetText("Counrty:");
	main.AddControl(lCountry, 1, 8);
	
	Label lSex(20);
	lSex.SetText("Sex:");
	main.AddControl(lSex, 1, 11);

	Label lInterests(20);
	lInterests.SetText("Interests:");
	main.AddControl(lInterests, 1, 15);
	
	Label lAge(20);
	lAge.SetText("Age:");
	main.AddControl(lAge, 1, 20);
	
	TextBox tName(30);
	tName.SetText("Sherlock Holmes");
	tName.SetBorder(BorderType::Single);
	main.AddControl(tName, 10, 2);
	

	TextBox tAddress(30);
	tAddress.SetText("221B Baker Street, London");
	tAddress.SetBorder(BorderType::Single);
	MyListener listener(tAddress);
	main.AddControl(tAddress, 10, 5);
	
	
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.SetSelectedIndex(1);
	cCountry.SetBorder(BorderType::Single);
	main.AddControl(cCountry, 10, 8);
	
	
	Radiolist rSex(5, 15, { "Male", "Female" });
	rSex.SetBorder(BorderType::Single);
	main.AddControl(rSex, 0, 0);

	Checklist clInterests(6, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	clInterests.SetBorder(BorderType::Single);
	main.AddControl(clInterests, 10, 15);
	main.AddControl(nAge, 25, 20);


	Button bSubmit(10);
	bSubmit.SetText("Submit");
	bSubmit.AddListener(listener);
	bSubmit.SetBorder(BorderType::Double);
	main.AddControl(bSubmit, 1, 15);
	
	
	MessageBoxx msgBox(25, 8);
	msgBox.SetTitle("msgBox TITLE:");
	msgBox.SetText("this is my msgBox");
	msgBox.SetBorder(BorderType::Single);
	main.AddControl(msgBox, 0, 10);
	
	
	//NumericBox numBox(15, 0,20); //(width,minVal,maxVal)
	//numBox.SetValue(10);//set the current value
	//numBox.SetBorder(BorderType::Single);
	//main.AddControl(numBox, 0, 10);

	Control::setFocus(main);
	EventEngine engine;
	engine.run(main);
	return 0;
}