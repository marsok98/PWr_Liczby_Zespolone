#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include "LZespolona.hh"


struct Statystyka_odpowiedzi {
	unsigned int ilosc_dzialan;
	unsigned int ilosc_poprawnych;
	unsigned int procent;
};

void Wyswietl(Statystyka_odpowiedzi Statystyka );


#endif

	