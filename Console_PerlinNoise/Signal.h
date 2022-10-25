#include "Style.h"

class Signal
{
	private :
		char symbol;
		int width;
		Style style;

	public :
		Signal(char newSymbol, int newWidth, Color textColor, Color bgColor);

		char getSymbol();
		int getWidth();
};

