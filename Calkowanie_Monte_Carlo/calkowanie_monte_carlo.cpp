#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

double f(double x);
double f1(double x);
double f2(double x);

double calka(double a, double b, int n);

int n; //ilosc losowan punktow w zadanym przedziale
double a; //lewa strona zadanego przedzialu
double b; //prawa strona zadanego przedzialu


int main()
{
	srand(static_cast <unsigned> (time(0)));
	while (true)
	{
		cout << "Podaj lewy kraniec przedzialu: " << endl;
		cin >> a;
		cout << "Podaj prawy kraniec przedzialu: " << endl;
		cin >> b;
		cout << "Podaj ilosc losowan punktow w zadanym przedziale: " << endl;
		cin >> n;

		double wynik = calka(a, b, n);

		cout << endl << "Ca³ka z Twojej funkcji wynosi: " << wynik << endl;

		cout << "---------------------------------------------------------------" << endl;
	}
	system("Pause");

	return (0);
}

double calka(double a, double b, int n)
{

	double suma=0;
	for (int i = 0; i < n; i++)
	{
		double xlos = (((double)rand() / (double)RAND_MAX))*(b - a) + a; //rzutowanie rand na double
		suma = suma + f1(xlos);
	}

	return ((b - a) / n*suma);
		
		// rand();

}

double f(double x) //y=x^2
{
	return x*x;
}


double f1(double x) //y=x^2
{
	return (4*(x*x)-(3*x)+4);
}

double f2(double x) //y=x^2
{
	return (x/sqrt(1+3*x));
}
