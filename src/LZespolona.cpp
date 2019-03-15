#include "LZespolona.hh"
#include <iostream>
#include <iomanip>
using namespace std;

ostream & operator << (ostream & wyj, LZespolona Skl1)
{
	if(Skl1.re == 0)
		wyj<<"("<<Skl1.im<<"i)";
	else if(Skl1.im == 0)
		wyj<<"("<<Skl1.re<<")";
	else if(Skl1.im == 1)
		wyj<<"("<<Skl1.re<<"+i)";
	else if(Skl1.im == -1)
		wyj<<"("<<Skl1.re<<"-i)";
	else
		wyj<<"("<<Skl1.re<<showpos<<Skl1.im<<"i)"<<noshowpos;
	return wyj;
}



istream & operator >> (istream & wej, LZespolona &Skl1)
{
	char znak;
	double wczytana;

	wej >> znak;
	
	if(wej.fail())
		return wej;

	if(znak != '(')
	{
		wej.setstate(ios::failbit);
		return wej;
	}

	wej >> wczytana;
	if(wej.fail())
		return wej;

	Skl1.re = wczytana;

	wej >> wczytana;
	if(wej.fail())
		return wej;

	Skl1.im = wczytana;

	wej >> znak;
	if(wej.fail())
		return wej;

	if(znak != 'i')
	{
		wej.setstate(ios::failbit);
		return wej;
	}

	wej >> znak;
	if(wej.fail())
		return wej;

	if(znak != ')')
	{
		wej.setstate(ios::failbit);
		return wej;
	}
	return wej;
}


double Modul2(LZespolona Skl1)             //Funkcja wyliczajaca modul do kwadratu z danej liczby zespolonej
{
	double Wynik = (Skl1.re * Skl1.re + Skl1.im * Skl1.im);
	return Wynik;
}

LZespolona Sprzezenie(LZespolona Skl1)    
{
	LZespolona Wynik;

	Wynik.re = Skl1.re;
	Wynik.im =-Skl1.im;
	return Wynik;
}

LZespolona operator / (LZespolona Skl1, double dzielnik)  //Realizuje dzielenie liczby zespolonej przez typ double
{
	LZespolona Wynik;
	if(dzielnik){                     //Sprawdzenie czy dzielnik aby napewno jest rozny od zera
		Wynik.re = Skl1.re / dzielnik;
		Wynik.im = Skl1.im / dzielnik;
		return Wynik;
	}
	else{
		cerr<<"Nie mozna dzielic przez zero\n";
		exit(0);
	}
}

LZespolona operator + (LZespolona Skl1, LZespolona Skl2)
{
  	LZespolona  Wynik;

  	Wynik.re = Skl1.re + Skl2.re;
  	Wynik.im = Skl1.im + Skl2.im;
  	return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
	LZespolona Wynik;

	Wynik.re = Skl1.re - Skl2.re;
	Wynik.im = Skl1.im - Skl2.im;
	return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
	LZespolona Wynik;

	Wynik.re=((Skl1.re * Skl2.re) - (Skl1.im * Skl2.im));
	Wynik.im=((Skl2.im * Skl1.re) + (Skl1.im * Skl2.re));
	return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
	LZespolona Wynik;
	LZespolona Licznik;
	double Mianownik;

	Licznik = Skl1 * Sprzezenie(Skl2);
	Mianownik = Modul2(Skl2);

	Wynik = Licznik / Mianownik;           //wykorzystanie przeciazenie dla struktury i liczby typu double

	return Wynik;

}

bool operator == (LZespolona Prawidlowa, LZespolona Do_Porownania)
{
	if(Prawidlowa.re == Do_Porownania.re && Prawidlowa.im == Do_Porownania.im) return true;
	else return false;
}

