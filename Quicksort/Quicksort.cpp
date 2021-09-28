#include <iostream>
#include <time.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

int n; //determining the size of an array
void my_quicksort(int *tab, int, int);

int main()
{
	srand(0);
	cout << "How big array should I create?" << endl;
	cin >> n;

	int *array = new int[n];

	cout << "Would you like to put your data? If not, numbers will be random. [Y/N]" << endl;
	char choice;
	cin >> choice;
	choice = toupper(choice);
	if (choice == 'Y')
	{
		cout << "Your numbers: ";
		for (int i = 0; i < n; i++)
		{
			cin >> array[i];
		}
	}
	else if (choice == 'N')
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = 1;//rand()%100+1;
		}
	}
	else { cout << "invalid choice. Goodbye!"; exit(0); }
	
//	cout << "Your array before sorting: ";
	//for (int i = 0; i < n; i++) { cout << array[i] << " "; } cout << endl;

	my_quicksort(array, 0, n-1);

	//cout << "Quicksorting... stand by..." << endl; Sleep(1000);
//	cout << "Your array after sorting: "; for (int i = 0; i < n; i++) { cout << array[i] << " "; } cout << endl;

system("Pause");

return(0);
}

void my_quicksort(int *array, int left, int right) // quicksort dostaje wskaznik do tablicy, numer indeksu lewego kranca tablicy i nr indeksu prawego kranca tablicy
{
	int ax = array[(left + right) / 2]; //wybieramy os - jest to WARTOSC (bo porownojemy). Moze byc losowa, polowa, egal. Int/int zawsze daje liczbe calkowita, nie ma ryzyka, ze sie wykrzaczy
	int p, q, tmp; //zmienna tmp przechowa tymczasowo liczbe (wartosc z tablicy) przy zamianie miejsc.
	p = left; q = right; //przypisujemy naszym zmiennym wartosci INDEKSOW krancow tablic
	do
	{
		while (array[p] < ax) p++; //dopoki nie napotkam liczby wiekszej lub rownej osi ide PO INDEKSIE w prawo
		while (array[q] > ax) q--; //dopoki nie napotkam liczby wiekszej od osi ide PO INDEKSIE w lewo
		if (p <= q) //jezeli indeks pierwszego elementu jest mniejszy lub równy indeksowi drugiego elementu to znaczy, ¿e jeszcze nie spotkaliœmy siê po œrodku i nie skoñczyliœmy sortowaæ!
		{
			tmp = array[p]; //zmienna tymczasowa zeby nie stracic danych
			array[p] = array[q];
			array[q] = tmp;//zamieniamy miejcami 
			p++; //idziemy dalej w prawo
			q--; //idziemy dalej w lewo
		}
	} 
	while (p <= q); //rekurencyjnie wywoluje funkcje quicksort
	if (q > left) my_quicksort(array, left, q);
	if (p < right) my_quicksort(array, p, right);
}