#include "Style.h"
#include "PerlinNoise.h"

class Signal
{
	private :
		char symbol;
		int width;
		int posCol;
		int posLig;
		double pnPosX;
		double pnPosY;
		double pnPosZ;
		Style style;
		PerlinNoise pn;

	public :
		Signal(char newSymbol, int newWidth, Color textColor, Color bgColor, unsigned int seed);

		char getSymbol();
		int getWidth();
		int getPosCol();
		int getPosLig();

		void displaySignal();
		void updateSignal();
};

