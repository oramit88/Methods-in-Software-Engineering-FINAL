
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
<<<<<<< HEAD
#include <string>
#include "EventEngine.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void MousePressed(int x, int y, bool isLeft)
=======
using namespace std;
Graphics graphics;
class MyListener : public MouseListener
{
public:
	MyListener(Control &c) : _c(c) { }
	void MousePressed( int x, int y, bool isLeft)
>>>>>>> d9b1bcf2e745e7573b4ba23f428e48e86b21f68c
	{
		_c.SetBorder(BorderType::None);
	}
private:
	Control &_c;
};
int main(int argc, char **argv)
{
<<<<<<< HEAD
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
	TextBox tName(30);
	tName.SetText("Sherlock Holmes");
	tName.SetBorder(BorderType::Single);
	TextBox tAddress(30);
	tAddress.SetText("221B Baker Street, London");
	tAddress.SetBorder(BorderType::Single);
	ComboBox cCountry(20,{ "Israel", "Great Britain", "United States" });
	//cCountry.SetSelectedIndex(1);
	cCountry.SetBorder(BorderType::Single);
	Radiolist rSex(4, 15, { "Male", "Female" });
	rSex.SetBorder(BorderType::Single);
	Checklist clInterests(6, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	clInterests.SetBorder(BorderType::Single);
	//NumericBox nAge(15, 18, 120);
	//nAge.setValue(23);
	//nAge.setBorder(BorderType::Single);
	MyListener listener(tAddress);
=======
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
>>>>>>> d9b1bcf2e745e7573b4ba23f428e48e86b21f68c
	Button bSubmit(10);
	bSubmit.SetText("Submit");
	bSubmit.AddListener(listener);
	bSubmit.SetBorder(BorderType::Double);
	Panel main;
<<<<<<< HEAD
	main.AddControl(lName, 1, 2);
	main.AddControl(lAddress, 1, 5);
	main.AddControl(lCountry, 1, 8);
	main.AddControl(lSex, 1, 11);
	main.AddControl(lInterests, 1, 15);
	main.AddControl(lAge, 1, 20);
	main.AddControl(tName, 10, 2);
	main.AddControl(tAddress, 10, 5);
	main.AddControl(cCountry, 10, 8);
	main.AddControl(rSex, 10, 11);
	main.AddControl(clInterests, 10, 15);
	//main.AddControl(nAge, 25, 20);

	main.AddControl(bSubmit, 1, 15);
	Control::setFocus(tName);
	EventEngine engine;
	engine.run(main);
	return 0;
}
=======
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

>>>>>>> d9b1bcf2e745e7573b4ba23f428e48e86b21f68c
