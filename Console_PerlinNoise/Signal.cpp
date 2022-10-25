#include "Signal.h"

//Constructor
Signal::Signal(char newSymbol, int newWidth, Color textColor, Color bgColor, unsigned int seed)
	: symbol(newSymbol), width(newWidth), style(textColor, bgColor), pn(seed)
{
	posCol = 0;
	posLig = 0;
	pnPosX = 0.0;
	pnPosY = 0.0;
	pnPosZ = 0.0;
}

//Getter of the symbol
char Signal::getSymbol()
{
	return symbol;
}

//Getter of the width
int Signal::getWidth()
{
	return width;
}

//Getter of the position (colonne) in the console
int Signal::getPosCol()
{
	return posCol;
}

//Getter of the position (line) in the console
int Signal::getPosLig()
{
	return posLig;
}


void Signal::displaySignal()
{
	//We apply the style of the signal
	style.applyStyle();

	//Update the position of the cursos in the console
	goToLigCol(posLig, posCol);

	//We then display the symbol of the signal according to the width of this signal
	for (int i = 0; i < width; i++)
	{
		cout << symbol;
	}

	//And finally reset the style of the console
	resetStyle();
}


void Signal::updateSignal()
{
	//We read the value in the 3D Perlin array
	posCol = int(pn.noise(pnPosX, pnPosY, pnPosZ) * double(TAILLE_ECRAN) - width);

	//We increase the value of X for the next value
	pnPosX += 0.01;

	//We increase the position of the line
	posLig++;
}