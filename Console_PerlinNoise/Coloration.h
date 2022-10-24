#include "header.h"

using namespace std;

class Coloration
{
	private :
		string mainColorName;
		string bgColorName;
		int mainColorCode;
		int bgColorCode;

	public :

		//Constructor
		Coloration(string newMainColorName, string newBgColorName, int newMainColorCode, int newBgColorCode);

		void apply();
};

