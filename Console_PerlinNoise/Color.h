#include "header.h"

class Color
{
	private :
		string name;
		int code;

	public :

		//Constructor
		Color(string newName, int newCode);

		//Getters
		string getName();
		int getCode();

		//Setters
		void setName(string newName);
		void setCode(int newCode);

		void applyColor();
		void applyColor(int textCode);
};

