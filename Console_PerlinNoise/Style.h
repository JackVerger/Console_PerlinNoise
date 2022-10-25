#include "header.h"
#include "Color.h"

class Style
{
	private :
		Color textColor;
		Color bgColor;
		char symbol;

	public :

		//Constructor
		Style(Color newTextColor, Color newBgColor, char newSymbol);

		//Methods
		void apply();
		void reset();
};

