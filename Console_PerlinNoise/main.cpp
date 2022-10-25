#include "Signal.h"

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


void displayColors(vector<Color> colorsTab, char symbol, int width)
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
		cout << colorsTab[i].getName() << "\t";

		if (colorsTab[i].getName().size() < 8)
		{
			cout << "\t";
		}

		//We display the future rendering
		for (int j = 1; j <= width; j++)
		{
			cout << symbol;
		}

		//We reset the default white color if it has been previously changed
		if (colorsTab[i].getName() != "Black")
		{
			resetStyle();
		}

		cout << endl;
	}
}


void displayColors(vector<Color> colorsTab, int textCode, char symbol, int width)
{
	//We go through the color vector
	for (int i = 0; i < colorsTab.size(); i++)
	{
		cout << " - " << i << "\t";

		//We apply the background color and display the text in the previously chosen text color
		colorsTab[i].applyColor(textCode);
		
		//We display the color name
		cout << colorsTab[i].getName() << "\t";

		if (colorsTab[i].getName().size() < 8)
		{
			cout << "\t";
		}

		//We display the future rendering
		for (int j = 1; j <= width; j++)
		{
			cout << symbol;
		}

		//We reset the console style to Default White
		resetStyle();
		
		cout << endl;
	}
}


int textColorMenu(vector<Color> colorsTab, char symbol, int width)
{
	int colorIndex;

	cout << "STYLE SELECTION : Text color" << endl << endl;
	cout << "Please, select the color of the signal symbol :" << endl;

	//We display the available colors
	displayColors(colorsTab, symbol, width);

	//The user has to enter the index of the chosen color
	do
	{
		cout << endl << "Your choice : ";
		cin >> colorIndex;

		//If the index is not valid, we tell the user
		if (colorIndex < 0 || colorIndex > 15)
		{
			cout << "Please, chose a valid color." << endl;
		}
	} while (colorIndex < 0 || colorIndex > 15);

	system("cls");
	
	return colorIndex;
}


int bgColorMenu(vector<Color> colorsTab, int textCode, char symbol, int width)
{
	int colorIndex;

	cout << "STYLE SELECTION : Background color" << endl << endl;
	cout << "Please, select the color of the signal symbol background :" << endl;

	//We display the available colors
	displayColors(colorsTab, textCode, symbol, width);

	do
	{
		cout << endl << "Your choice : ";
		cin >> colorIndex;

		//If the index is not valid, we tell the user
		if (colorIndex < 0 || colorIndex > 15)
		{
			cout << "Please, chose a valid color." << endl;
		}
	} while (colorIndex < 0 || colorIndex > 15);

	system("cls");

	return colorIndex;
}

char symbolSelection()
{
	char symbol;

	cout << "SYMBOL SELECTION" << endl << endl;
	cout << "Please, enter the symbol of the signal (except SPACE character)." << endl;

	//The user enters the chosen symbol
	cout << endl << "Your choice : ";
	cin >> symbol;

	system("cls");

	return symbol;
}


int widthSelection()
{
	int width;

	cout << "WIDTH SELECTION" << endl << endl;
	cout << "Please, enter the width of the signal (only positive odd value)." << endl;

	//The user enters the chosen width of the signal
	do
	{
		cout << endl << "Your choice : ";
		cin >> width;

		//If the width is not valid, we tell the user
		if (width%2 == 0 || width < 1)
		{
			cout << "Please, chose a positive odd value." << endl;
		}
	} while (width % 2 == 0 || width < 1);

	system("cls");

	return width;
}


int main()
{
	vector<Color> colorsTab;
	int colorIndex = -1;
	char symbol = ' ';
	int width = -1;

	readColors(colorsTab);

	symbol = symbolSelection();
	width = widthSelection();

	colorIndex = textColorMenu(colorsTab, symbol, width);
	Color symbolColor(colorsTab[colorIndex].getName(), colorsTab[colorIndex].getCode());

	colorIndex = bgColorMenu(colorsTab, colorIndex, symbol, width);
	Color bgColor(colorsTab[colorIndex].getName(), colorsTab[colorIndex].getCode());

	Style newStyle(symbolColor, bgColor);

	//Signal newSignal(symbol, width, symbolColor, bgColor);




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
