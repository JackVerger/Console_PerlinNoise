#include "Color.h"

//Constructor
Color::Color(string newName, int newCode)
	: name(newName), code(newCode)
{

}


//Getter of the name
string Color::getName()
{
	return name;
}

//Getter of the color code
int Color::getCode()
{
	return code;
}


//Setter of the name
void Color::setName(string newName)
{
	name = newName;
}

//Setter of the color code
void Color::setCode(int newCode)
{
	code = newCode;
}

void Color::applyColor()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, code);
}

void Color::applyColor(int textCode)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, code*16 + textCode);
}
