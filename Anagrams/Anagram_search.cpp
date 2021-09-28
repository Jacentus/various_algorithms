#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string slowo; //slowo do wyszukania
fstream slownik; //zmienna plikowa przechowujaca slownik


int main()
{
	cout << "***************************************************" << endl;
	cout << "PROGRAM SZUKA ANAGRAMOW W SLOWNIKU JEZYKA POLSKIEGO." << endl;
	cout << "***************************************************" << endl;
	
	while (true) //petla pozwalajaca na wielokrotne wyszukiwanie
	{
		slownik.open("slownik.txt", ios::in);
		int licznik = 0;
		cout << "Anagramow jakiego slowa chcesz wyszukac? Wpisz slowo: ";
		cin >> slowo; cout << endl;
		string nie_strac = slowo;
		sort(slowo.begin(), slowo.end());
		
		if (slownik.good() == false) { cout << "Nie udalo sie otworzyc pliku :(" << endl; break; }

		string przechowaj; 
		while (!slownik.eof()) 
		{
			getline(slownik, przechowaj);
			string nie_strac = przechowaj; 
			sort(przechowaj.begin(), przechowaj.end()); 
			
			if (przechowaj == slowo) //jesli posortowana wczytana licznia jest rowna posortowanemu szukanemu slowu to wykonaj jak nizej
			{ 
				licznik++;
				cout << "Anagram nr " << licznik << " to: " << nie_strac << ". " << endl; 
			}
		} cout << endl;
		slownik.close();
		cout << "Czy chcesz wyszukac anagramu raz jeszcze? [Y/N]    ";
		char TN;
		cin >> TN;
		TN = toupper(TN);
		if (TN == 'N') {break; } 
	}

	cout << "Do widzenia!" << endl;

	system("Pause");

	return (0);
}
