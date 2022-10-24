#include "header.h"

using namespace std;

class Coloration
{
	private :
		string textColorName;
		string bgColorName;
		int textColorCode;
		int bgColorCode;
		char symbol;

	public :

		//Constructor
		Coloration(string newTextColorName, string newBgColorName, int newTextColorCode, int newBgColorCode, char newSymbol);

		//Methods
		void apply();
		void reset();
};

