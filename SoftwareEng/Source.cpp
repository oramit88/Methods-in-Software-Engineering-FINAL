
#include <string>
#include "EventEngine.h"
#include "../TextBox/TextBox.h"
#include"../Label/Label.h"
#include"../Panel/Panel.h"
#include "../Checklist/Checklist.h"
#include "../Radiolist/Radiolist.h"
using namespace std;

int main(int argc, char **argv)
{
//	Label lName(20);
	//lName.SetText("Name: ");

	//TextBox tx1(25);
	//tx1.SetText("Daria is the king");
	//Checklist cl1(9, 15, { "Sports", "Books", "Movies" ,"Movies1"});
	Radiolist cl1(10, 20, { "Sports", "Books", "Movies" ,"Movies1","Movies2","Movies3","Movies4","Movies5"});
	cl1.SetBorder(BorderType::Single);
	Panel main(0,0);
	main.AddControl(cl1, 1, 1);
	Control::setFocus(cl1);
	EventEngine engine;
	engine.run(main);
	return 0;
}

