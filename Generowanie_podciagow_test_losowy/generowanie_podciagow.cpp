#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int m, n;
double prawdopodobienstwo;

int main()
{
	srand(time(NULL));
	cout << "Wczytaj wielkosc listy: ";
	cin >> n;
	cout << "Wczytaj wielkosc podciagu: ";
	cin >> m;
	double licznik = (double)m; //aby nie zmieniac wartosci m;
	double mianownik = (double)n;

	//double *tablica = new double(n);
	//int numer_w_tablicy = 0;

	for (int i = 1; i <= n; i++)
	{

		double prawdopodobienstwo = licznik / mianownik; 

	//	if (licznik == 0) { cout << "Zapelnilem podciag! Zrywam petle!" << endl; break; }
	
	//	cout << "Prawdopodobienstwo: " << prawdopodobienstwo << endl;		
	//	cout << "Wykonuje petle for " << i + 1 << " raz..." << endl;
		double czy_wchodzi = ((double)rand() / (RAND_MAX));

	//	cout << "Wylosowana liczba: " << czy_wchodzi << endl;

		if (czy_wchodzi < prawdopodobienstwo)
		{
	//		cout << "Dziala if gdy wylosowalem liczbe! Do podciagu zaliczam liczbe: ";
			cout << i <<endl;
			licznik--;
			mianownik--;
			//tablica[numer_w_tablicy] = i;
			//numer_w_tablicy++;
		}
		else
		{
			
	//		cout << "Nie trafilem, zmniejszam mianownik" << endl;
			mianownik--;
		}
		
	//	cout << "Licznik: " << licznik<<endl;
	}

	//cout << "Wygenerowany podci¹g to: ";
//	for (int i = 0; i < m; i++)
	//{
//		cout<<tablica[i] << " ";
//	}

	system("Pause");

	return (0);
}