
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
	/*
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
	*/
//	TextBox tName(20);
//	tName.SetText("Sherlock Holmes");
//	tName.SetBorder(BorderType::Single);
//	TextBox tAddress(25);
//	tAddress.setText("221B Baker Street, London");
//	tAddress.setBorder(BorderType::Single);
//	ComboBox cCountry({ "Israel", "Great Britain", "United States" }, 20);
//	cCountry.setSelectedIndex(1);
//	cCountry.setBorder(BorderType::Single);
	Radiolist rSex(6, 15, { "Male", "Female" });
	rSex.SetBorder(BorderType::Single);
	Checklist clInterests(6, 15, { "Sports", "Books", "Movies" });
	Checklist clInterests2(6, 15, { "Sports", "Books", "Movies" });
	clInterests.SelectIndex(1);
	clInterests.SetBorder(BorderType::Single);
	clInterests2.SetBorder(BorderType::Double);
//	NumericBox nAge(15, 18, 120);
//	nAge.setValue(23);
//	nAge.setBorder(BorderType::Single);
//	MyListener listener(tAddress);
//	Button bSubmit(10);
//	bSubmit.setText("Submit");
//	bSubmit.addListener(listener);
//	bSubmit.setBorder(BorderType::Double);
	Panel main;
	/*
	main.AddControl(lName, 1, 2);
	main.AddControl(lAddress, 1, 5);
	main.AddControl(lCountry, 1, 8);
	main.AddControl(lSex, 1, 11);
	main.AddControl(lInterests, 1, 15);
	main.AddControl(lAge, 1, 20);
	*/
//	main.AddControl(tName, 25, 2);
//	main.AddControl(tAddress, 25, 5);
//	main.AddControl(cCountry, 25, 8);
	main.AddControl(rSex, 1, 1);
	main.AddControl(clInterests, 10, 1);
	main.AddControl(clInterests2, 25, 1);
//	main.AddControl(nAge, 25, 20);

//	main.addControl(bSubmit, 1, 22);
	Control::setFocus(rSex);
	EventEngine engine;
	engine.run(main);
	return 0;
}

