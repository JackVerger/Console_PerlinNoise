#include "Style.h"
#include <typeinfo>

void goToLigCol(int ligne, int colonne)
{
	COORD myCoord;

	myCoord.X = colonne;
	myCoord.Y = ligne;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoord);
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
	for (int i = 0; i < colorsTab.size(); i++)
	{
		cout << colorsTab[i].getName() << colorsTab[i].getCode() << endl;
		cout << "oui" << endl;
		cout << typeid(colorsTab[i]).name() << endl << endl;
	}
}



int main()
{
	vector<Color> colorsTab;
	
	Color test("Test", 0);
	cout << "test : " << typeid(test).name() << endl;

	readColors(colorsTab);
	displayColors(colorsTab);


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
