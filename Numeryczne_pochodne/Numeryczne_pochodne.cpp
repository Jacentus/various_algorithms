#include <iostream>
#include <math.h>
 
using namespace std;

double funkcja(double);
double pierwsza_pochodna(double x, double h);
double druga_pochodna(double x, double h);

double x;
double h;

int main()
{
	cout << "Podaj wspolrzedna X punktu: ";
	cin >> x;
	cout << "Podaj wartosc wspolczynnika h: ";
	cin >> h;


	/*cout << "Wartosc Y w punkcie: " << x <<" " << funkcja(x) << endl;

	cout << "Dane przekazane w pochodnych: funkcja(x+h): " << funkcja(x+h) << " funkcja(x-h): " << funkcja(x-h) << " dwa razy h: " << (2 * h) << " Dwa razy funkcja od X: "<<(2*funkcja(x))<<endl;
	*/


	cout << "Wartosc pierwszej pochodnej: " << pierwsza_pochodna(x, h) << endl;
	cout << "Wartosc drugiej pochodnej: " << druga_pochodna(x, h) << endl;

	system("Pause");

	return (0);
}

double funkcja(double x)
{
	return (pow(x, 2)) + (5 * x) + 3;
}

/*double funkcja(double x)
{
	return (sin(x)* cos(x)) / (x*x - (6* pow(x, 5)));
}*/


double pierwsza_pochodna(double x, double h)
{
	return (funkcja(x + h) - funkcja(x - h)) / (2 * h);
}

double druga_pochodna(double x, double h)
{
	return (funkcja(x + h) + funkcja(x - h)) - (2 * funkcja(x)) / (h*h);
}