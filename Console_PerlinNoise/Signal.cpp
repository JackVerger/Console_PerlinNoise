#include "Signal.h"

Signal::Signal(char newSymbol, int newWidth, Color textColor, Color bgColor)
	: symbol(newSymbol), width(newWidth), style(textColor, bgColor)
{

}

char Signal::getSymbol()
{
	return symbol;
}

int Signal::getWidth()
{
	return width;
}