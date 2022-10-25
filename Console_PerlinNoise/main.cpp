#include "Style.h"
#include <typeinfo>

void goToLigCol(int ligne, int colonne)
{
	COORD myCoord;

	myCoord.X = colonne;
	myCoord.Y = ligne;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoord);
}

//Method to reset the color of the console to a default white (code 7) on a black background
void resetStyle()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, 7);
}


void readColors(vector<Color>& colorsTab)
{
	string colorName;
	int colorCode;

	//Opening the file in reading mod
	ifstream file;
	file.open("colors.txt", ios::in | ios::binary);

	//Reading the entire file 
	while (!file.eof())
	{
		file >> colorName >> colorCode;
		colorsTab.push_back(Color(colorName, colorCode));
	}

	//Closing the file
	file.close();
}


void displayColors(vector<Color> colorsTab)
{
	//We go through the color vector
	for (int i = 0; i < colorsTab.size(); i++)
	{
		cout << " - " << i << "\t";

		//We apply the text color only if it isn't black (not visible on a black background)
		if (colorsTab[i].getName() != "Black")
		{
			colorsTab[i].applyColor();
		}
		
		//We display the color name
		cout << colorsTab[i].getName();

		//We reset the default white color if it has been previously changed
		if (colorsTab[i].getName() != "Black")
		{
			resetStyle();
		}

		cout << endl;
	}
}


void displayColors(vector<Color> colorsTab, int textCode)
{
	//We go through the color vector
	for (int i = 0; i < colorsTab.size(); i++)
	{
		cout << " - " << i << "\t";

		//We apply the background color and display the text in the previously chosen text color
		colorsTab[i].applyColor(textCode);
		
		//We display the color name
		cout << colorsTab[i].getName();

		//We reset the console style to Default White
		resetStyle();
		
		cout << endl;
	}
}


int textColorMenu(vector<Color> colorsTab)
{
	int colorIndex;
	cout << "STYLE SELECTION : Text color" << endl << endl;
	cout << "Please, select the color of the signal symbol :" << endl;

	displayColors(colorsTab);

	do
	{
		cout << endl << "Your choice : ";
		cin >> colorIndex;

		if (colorIndex < 0 || colorIndex > 15)
		{
			cout << "Please, chose a valid color." << endl;
		}
	} while (colorIndex < 0 || colorIndex > 15);

	system("cls");
	
	return colorIndex;
}


int bgColorMenu(vector<Color> colorsTab, int textCode)
{
	int colorIndex;
	cout << "STYLE SELECTION : Background color" << endl << endl;
	cout << "Please, select the color of the signal symbol background :" << endl;

	displayColors(colorsTab, textCode);

	do
	{
		cout << endl << "Your choice : ";
		cin >> colorIndex;

		if (colorIndex < 0 || colorIndex > 15)
		{
			cout << "Please, chose a valid color." << endl;
		}
	} while (colorIndex < 0 || colorIndex > 15);

	system("cls");

	return colorIndex;
}


int main()
{
	vector<Color> colorsTab;
	int colorIndex;

	readColors(colorsTab);

	colorIndex = textColorMenu(colorsTab);
	
	Color symbolColor(colorsTab[colorIndex].getName(), colorsTab[colorIndex].getCode());

	colorIndex = bgColorMenu(colorsTab, colorIndex);
	Color bgColor(colorsTab[colorIndex].getName(), colorsTab[colorIndex].getCode());

	Style newStyle(symbolColor, bgColor);



	//int compteur = 0;
	//int compteurLi = 0;
	//cout << "A A" << endl;
	//fflush(stdout);
	//while (true)
	//{
	//	compteur++;
	//	compteurLi++;
	//	if (compteur >= 10)
	//	{
	//		compteur = 0;
	//	}

	//	goToLigCol(compteurLi, compteur);
	//	printf("B\n");
	//}


	return 0;
}
