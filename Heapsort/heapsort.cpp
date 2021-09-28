#include <iostream>
#include <time.h>

using namespace std;

int n; //wielkosc tablicy

void utworz_kopiec(int tablica[], int wielkosc, int i);// n = wielkosc tablicy i = indeks korzenia kopca

void heapsort(int tablica[], int wielkosc);

void pokazTablice(int tablica[], int wielkosc);

int main()
{
	srand(time(NULL));

	cout << "Jak duza tablice mam utworzyc? Podaj liczbe: ";
	cin >> n;

	int* tablica = new int[n];

	cout << "Czy chcesz wpisac liczby do tablicy? Jesli nie, liczby beda losowe z przedzialu od 1 do 50. [Y/N]" << endl;
	char wybor;
	cin >> wybor;
	wybor = toupper(wybor);
	if (wybor == 'Y')
	{
		cout << "Twoje liczby: ";
		for (int i = 0; i < n; i++)
		{
			cin >> tablica[i];
		}
	}
	else if (wybor == 'N')
	{
		for (int i = 0; i < n; i++)
		{
			tablica[i] = rand() % 50 + 1;
		}
	}
	else { cout << "Bledny wybor! Do widzenia"; exit(0); }

	cout << "Twoja tablica: ";

	pokazTablice(tablica, n);

	cout << "Bede sortowal tablice przez kopcowanie." << endl;

	heapsort(tablica, n);

	cout << "Posortowana tablica: "; 
	
	pokazTablice(tablica, n);

	system("Pause");

	return (0);
}

void utworz_kopiec(int tablica[], int wielkosc, int i)// n = wielkosc tablicy i = indeks korzenia kopca
{
	int max = i;
	int tmp;

	int lewysyn = 2 * i + 1;
	int prawysyn = (2 * i + 2);

	if (lewysyn < wielkosc && tablica[lewysyn] > tablica[max]) // je¿eli indeks lewegosyna nie wyszedl poza tablice oraz wartosc lewego syna jest wieksza ni¿ wartosc korzenia (ktora jest zmienna po kazdej iteracji)
	{
		max = lewysyn; //to za indeks korzenia przyjmuje indeks lewegosyna
	}
	if (prawysyn < wielkosc && tablica[prawysyn] > tablica[max])
	{
		max = prawysyn; //analogicznie w odniesieniu do prawegosyna
	}
	if (max != i) //jezeli indeks najwiekszego elementu w tablicy to nie jest juz indeks korzenia to zamieniam miejscami ten element z korzeniem
	{
		tmp = tablica[i];
		tablica[i] = tablica[max]; //najwiekszy element przekazany do korzenia
		tablica[max] = tmp; //po przeniesieniu najwiekszego przekazujemy tam wartosc korzenia 
		utworz_kopiec(tablica, wielkosc, max);
	}
}

void heapsort(int tablica[], int wielkosc)
{
	int tmp;
	for (int i = wielkosc / 2 - 1; i >= 0; i--)
	{
		utworz_kopiec(tablica, wielkosc, i);
	}
	for (int i = wielkosc - 1; i >= 0; i--)
	{
		tmp = tablica[0];
		tablica[0] = tablica[i];
		tablica[i] = tmp;
		utworz_kopiec(tablica, i, 0);
	}
}

void pokazTablice(int tablica[], int wielkosc)
{
	for (int i = 0; i < wielkosc; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}