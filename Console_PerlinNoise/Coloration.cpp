#include "Coloration.h"

Coloration::Coloration(string newMainColorName, string newBgColorName, int newMainColorCode, int newBgColorCode)
	: mainColorName(newMainColorName), bgColorName(newBgColorName), mainColorCode(newMainColorCode), bgColorCode(newBgColorCode)
{

}

void Coloration::apply()
{
	//Creating the command in a string containing the BG color and the MAIN color
	string strCommand = "color ";
	strCommand += bgColorCode;
	strCommand += mainColorCode;


	//Calculating the size of the corresponding char*
	int n = strCommand.length() + 1;

	//Creating the char* command
	char* charCommand = new char[n];

	//Copying the string command in the char array
	strcpy_s(charCommand, n, strCommand.c_str());

	//Applying the command
	system(charCommand);

	cout << endl << strCommand;
}
