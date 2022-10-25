#include "Style.h"

//Constructor
Style::Style(Color newTextColor, Color newBgColor, char newSymbol)
	: textColor(newTextColor.getName(), newTextColor.getCode()), bgColor(newBgColor.getName(), newBgColor.getCode()), symbol(newSymbol)
{
	
}


//Method to apply the style (text and background colors) to the console
void Style::apply()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, bgColor.getCode() * 16 + textColor.getCode());
}

//Method to reset the color of the console to a default white (code 7) on a black background
void Style::reset()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 7);
}


