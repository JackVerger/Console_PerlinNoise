#include "Coloration.h"

//Constructor
Coloration::Coloration(string newTextColorName, string newBgColorName, int newTextColorCode, int newBgColorCode, char newSymbol)
	: textColorName(newTextColorName), bgColorName(newBgColorName), textColorCode(newTextColorCode), bgColorCode(newBgColorCode), symbol(newSymbol)
{

}

//Method to apply the color to the console
void Coloration::apply()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, bgColorCode * 16 + textColorCode);
}

//Method to reset the color of the console to a default white (code 7)
void Coloration::reset()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 7);
}



/*
0 : Black
1 : Blue
2 : Green
3 : Cyan
4 : Red
5 : Purple
6 : Yellow (Dark)
7 : Default white
8 : Grey
9 : Bright blue
10 : Bright green
11 : Bright cyan
12 : Bright red
13 : Pink/Magenta
14 : Yellow
15 : Bright white
*/