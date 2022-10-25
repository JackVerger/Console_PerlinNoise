#include "Signal.h"
#include "PerlinNoise.h"

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


int signalQuantitySelection()
{
	int quantity;

	cout << "SIGNAL NUMBER SELECTION" << endl << endl;
	cout << "Please, enter the number of signals who will be displayed on the screen" << endl;

	//The user enters the chosen quantity of signal
	do
	{
		cout << endl << "Your choice : ";
		cin >> quantity;

		//If the quantity is not valid, we tell the user
		if (quantity <= 0)
		{
			cout << "Please, enter a positive value" << endl;
		}
	} while (quantity <= 0);

	system("cls");

	return quantity;
}




int main()
{
	//Initialize the random seed
	srand(time(NULL));

	//Reinitialize the style of the console
	resetStyle();

	//Variables declaration
	vector<Color> colorsTab;
	vector<Signal> signalTab;
	int colorIndex = -1;
	int signalQuantity = 0;
	char symbol = ' ';
	int width = -1;

	//We read the list of colors in the dedicated file
	readColors(colorsTab);

	//The user enters the number of signal
	signalQuantity = signalQuantitySelection();

	for (int i = 1; i <= signalQuantity; i++)
	{
		//The user enters the symbol of the signal
		symbol = symbolSelection();

		//Then he enters the width of the signal
		width = widthSelection();

		//Then he choses the color of the signal text
		colorIndex = textColorMenu(colorsTab, symbol, width);
		Color symbolColor(colorsTab[colorIndex].getName(), colorsTab[colorIndex].getCode());

		//Then the color of the signal background 
		colorIndex = bgColorMenu(colorsTab, colorIndex, symbol, width);
		Color bgColor(colorsTab[colorIndex].getName(), colorsTab[colorIndex].getCode());

		//We initialize the corresponding Style object
		Style newStyle(symbolColor, bgColor);

		//We create the corresponding signal with all these information
		Signal newSignal(symbol, width, symbolColor, bgColor, rand() % 100);

		//And finally add it to the signal vector
		signalTab.push_back(newSignal);
	}
	

	while (true)
	{
		for (int i = 0; i < signalTab.size(); i++)
		{
			//We update the position of the signal according of its Perlin noise array
			signalTab[i].updateSignal();

			//We display the signal
			signalTab[i].displaySignal();
		}

		Sleep(5);
	}
	
	return 0;
}
