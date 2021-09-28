#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int n; 
int p; 
//int tablica[9]; //tablica 

void sort_wst(int*, int);
int binary_search(int *tablica, int n, int p);

int main()
{
	srand(time(0));
	do
	{
		cout << "Jak duza tablice chcesz utworzyc?" << endl;
		cin >> n;
	} while (n <= 0);

	int *tablica = new int [n];

	cout << "Jaka liczbe p chcesz wyszukac?" << endl;
	cin >> p;

	if (n <= 10)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Podaj " << i + 1 << " element tablicy: " << endl;
			cin >> tablica[i];
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
			tablica[i] = rand() % (91 - 10);
	}

	//int tablica[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90}; 
	cout << endl << "Liczby w tablicy: ";
	for (int i = 0; i < n; i++)
	{
		
		cout << tablica[i] << " ";
	}

	sort_wst(tablica, n);

	cout << "Liczby w tablicy po posortowaniu: ";
	for (int i = 0; i < n; i++)
	{

		cout << tablica[i] << " ";
	}

	int wynik;

	wynik = binary_search(tablica, n, p);

	if (wynik == -1)
	{
		cout <<endl<< "Twojej liczby nie ma w tablicy!" << endl;
	}
	else
	{
		cout << endl<< "Liczba jest w tablicy na pozycji " << wynik + 1 << endl;
	}

	system("Pause");

	return (0);
}

int binary_search(int *tablica, int n, int p)
{
	int bot = 0;
	int top = n-1;
	int wynik;
	int mid;

	for (;;)
	{
		if (bot > top)
		{
			wynik = -1;
			break;
		}
		else
		{
			mid = (bot + top) / 2;
			if (tablica[mid] < p)
			{
				bot = mid + 1;
			}
			else if (tablica[mid] == p)
			{
				wynik = mid;
				break;
			}
			else if (tablica[mid] > p)
			{
				top = mid - 1;
			}
		}
	}

	return (wynik);
}

void sort_wst(int *tablica, int n)    
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (tablica[j] < tablica[j - 1])
			{
				int max = tablica[j];
				tablica[j] = tablica[j - 1];
				tablica[j - 1] = max;
			}
		}
	}
}
