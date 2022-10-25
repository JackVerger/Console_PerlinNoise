#include "Style.h"

//Constructor
Style::Style(Color newTextColor, Color newBgColor)
	: textColor(newTextColor.getName(), newTextColor.getCode()), bgColor(newBgColor.getName(), newBgColor.getCode())
{
	
}


//Method to apply the style (text and background colors) to the console
void Style::applyStyle()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, bgColor.getCode() * 16 + textColor.getCode());
}




