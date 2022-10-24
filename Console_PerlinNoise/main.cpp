#include "Coloration.h"
#include <typeinfo>


void goToLigCol(int ligne, int colonne)
{
	COORD myCoord;

	myCoord.X = colonne;
	myCoord.Y = ligne;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), myCoord);
}



int main()
{
	Coloration couleur("Bright Red", "Black", 12, 0, 'A');
	couleur.apply();
	couleur.reset();


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
