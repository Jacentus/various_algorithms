#include <iostream>

using namespace std;

int n=9; 
int p; 
int tablica[9];

int binary_search(int *tablica, int n, int p);

int main()
{

	/*do
	{
		cout << "Jak duza tablice chcesz utworzyc?" << endl;
		cin >> n;
	} while (n <= 0);

	int *tablica = new int [n];*/

	cout << "Jaka liczbe p bedaca wielokrotnoscia liczby 10 (gdzie p<=100) chcesz wyszukac?" << endl;
	cin >> p;

	int tablica[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90}; 
	cout << "Liczby w tablicy: ";
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