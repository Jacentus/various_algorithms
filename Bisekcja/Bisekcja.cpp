#include <iostream>

using namespace std;

double eps;  //dokladnosc z jaka wyznaczamy miejsce zerowe
double a; //lewy kraniec przedzialu
double b; //prawy kraniec przedzialu

double bisekcja(double, double, double);
double f(double s);

int main()
{
	
	while (true)
	{
		cout << "Podaj lewy kraniec przedzialu: " << endl;
		cin >> a;
		cout << "Podaj prawy kraniec przedzialu: " << endl;
		cin >> b;
		cout << "Podaj dokladnosc z jaka chcesz wyznaczyc miejsce zerowe: " << endl;
		cin >> eps;

		if (f(a)*f(b) < 0)
			{
				double wynik = bisekcja(a, b, eps);

				cout << endl << "Miejsce zerowe funkcji to x = " << wynik << endl;
			}
		
		else cout << "W zadanym przedziale nie ma miejsca zerowego!" << endl;
		
		cout << "---------------------------------------------------------------" << endl;
	}
	system("Pause");

	return (0);
}

double bisekcja(double a, double b, double eps)
{
	double s;
	while ((b - a) > eps)
	{
		s = (a + b) / 2;
		if (f(s) == 0)
		{
			break;
		}
		else
		{
			if (f(a)*f(s) < 0)
			{
				b = s;
//				wynik = s; //wynikiem jest ostatnio znany srodek
			}
			else if (f(b)*f(s) < 0)
			{
				a = s;
//				wynik = s; //wynikiem jest ostatnio znany srodek
			}	
		}
	}

	return (s);
}

double f(double x)//
{
	return x-10;
}