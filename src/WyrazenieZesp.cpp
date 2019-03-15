#include "WyrazenieZesp.hh"
#include <iostream>
using namespace std;



ostream & operator << (ostream & wyj, Operator Op)          //Wyswietlanie operatora pomiedzy liczbami zespolonymi
{
	switch(Op)
	{							
		case Op_Dodaj:
			wyj<<'+';
			break;
		case Op_Odejmij:
			wyj<<'-';
			break;
		case Op_Mnoz:
			wyj<<'*';
			break;
		case Op_Dziel:
			wyj<<'/';
			break;
	}
	return wyj;
}

ostream & operator << (ostream & wyj, WyrazenieZesp WyrZ)
{
	wyj<<WyrZ.Arg1;
	wyj<<WyrZ.Op;
	wyj<<WyrZ.Arg2;
	return wyj;
}

istream & operator >> (istream & wej, Operator &Op)
{
	char temp;
	wej>>temp;
	switch(temp)
	{
		case '+':
			Op = Op_Dodaj;
			return wej;
		case '-':
			Op = Op_Odejmij;
			return wej;
		case '*':
			Op = Op_Mnoz;
			return wej;
		case '/':
			Op = Op_Dziel;
			return wej;
		default:
			wej.setstate(ios::failbit);
			return wej;
	}
}

istream & operator >> (istream & wej, WyrazenieZesp &WyrZ)
{
	wej>>WyrZ.Arg1;
	wej>>WyrZ.Op;
	wej>>WyrZ.Arg2;
	return wej;
}


LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
	LZespolona Wynik;
	switch(WyrZ.Op)
	{          								 //W zaleznosci od uzytego operatora oblicza wartosci wyrazen
		case Op_Dodaj:
			Wynik = WyrZ.Arg1 + WyrZ.Arg2;
			return Wynik;
		case Op_Odejmij:
			Wynik = WyrZ.Arg1 - WyrZ.Arg2;
			return Wynik;
		case Op_Mnoz:
			Wynik = WyrZ.Arg1 * WyrZ.Arg2;
			return Wynik;
		case Op_Dziel:
			Wynik = WyrZ.Arg1 / WyrZ.Arg2;
			return Wynik;
		default:
			exit(0);
	}
}

