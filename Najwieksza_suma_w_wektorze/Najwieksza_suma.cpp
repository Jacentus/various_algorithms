#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int ile_liczb, wybor;
int maxsofar = 0;
int maxhere = 0;
int indeks_pierwszy = 0;
int indeks_ostatni = 0;
int tmp_indeks = 0; 

int main()
{
	srand(time(NULL));
	cout << "************************************************" << endl;
	cout << "*** PROGRAM LICZY NAJWIEKSZA SUME W WEKTORZE ***" << endl;
	cout << "************************************************" << endl;
	cout << "Jak duza tablice liczb chcesz utworzyc? " << endl; 
	cout << "Wielkosc Twojej tablicy: "; cin >> ile_liczb;
	
	cout << "Czy chcesz wpisac liczby, czy je wylosowac?" << endl;
	cout << "1. Wylosuj. 2. Wypisz"<<endl; 
	do {
		cout << "Twoj wybor: "; cin >> wybor;
	} while (!(wybor == 1 || wybor == 2));

	int* tablica = new int[ile_liczb];

	switch (wybor)
	{
	case 1: {	cout << "Umieszcze w w tablicy liczby losowe z przedzialu od - 10 do 10." << endl; 
				for (int i = 0; i < ile_liczb; i++)
				{
					tablica[i] = rand() % 21 - 10; //random od -10 do 10
				} break; }

	case 2: { for (int i = 1; i <= ile_liczb; i++) { cout << "Wprowadz " << i << " liczbe: "; cin >> tablica[i - 1]; cout << endl; }break; }
	}

	cout << "Liczby w Twojej tablicy: ";
		for (int i = 0; i < ile_liczb; i++)
		{
			cout << tablica[i]<<" ";
		}
			cout << endl;

	for (int k = 0; k < ile_liczb; k++) 
	{
			if (maxhere + tablica[k] > 0)     /*jezeli maxhere plus tablica o indeksie k jest wieksze od 0, to maxhere powiekszam o wartosc z tablicy o indeksie k. 
												Nie wykonuje sie wtedy instrukcja warunkowa ponizej i moze nie wykonac sie instrukcja warunkowa if jeszcze nizej, np. kiedy wartosc tablica[k] jest < 0 ! */
				{
					maxhere = maxhere + tablica[k];
				}
			else if (maxhere + tablica[k] < 0) //w przeciwnym razie nadal za wartosc maxhere uznaje zero
				{
					tmp_indeks = k+1; /*zmienna do tymczasowego przechowywania indeksu tablicy (tego, ktory bedzie pierwszy) i przypisania go do zmiennej indeks pierwszy.
										Bedzie ona zawsze rowna k+1 bo je¿eli maxhere + tablica[0] < 0 to z pewnoscia od tego indeksu k nie zaczniemy naszej podtablicy*/
					maxhere = 0;
				}
		if (maxsofar < maxhere) //jezeli maxsofar jest mniejsze niz maxhere to przypisuje do maxsofar wartosc maxhere.
		{
			maxsofar = maxhere;
			indeks_pierwszy = tmp_indeks; //pierwszym indeksem bedzie wartosc przechowana w instrukcji warunkowej wyzej
			indeks_ostatni = k;
		}
	}
	
	cout << "Suma zaczyna sie od " << indeks_pierwszy << " i konczy na " << indeks_ostatni<< " indeksie" << endl;
	cout << "Najwieksza suma w wektorze to: " << maxsofar << endl;

	system("Pause");

	return (0);
}
