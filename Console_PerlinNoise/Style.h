#include "header.h"
#include "Color.h"

class Style
{
	private :
		Color textColor;
		Color bgColor;

	public :

		//Constructor
		Style(Color newTextColor, Color newBgColor);

		//Methods
		void applyStyle();
};

