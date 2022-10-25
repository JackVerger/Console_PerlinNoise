#include "header.h"

class Color
{
	private :
		string name;
		int code;

	public :

		//Constructor
		Color(string newName, int newCode);
		//Color(Color& colorToCopy);

		//Getters
		string getName();
		int getCode();

		//Setters
		void setName(string newName);
		void setCode(int newCode);
};

