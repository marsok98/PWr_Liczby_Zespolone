#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH


/*Struktura modelujaca statystyke zawierajaca dane na temat poprawnych odpowiedzi uzytkownika*/
struct Statystyka_odpowiedzi {
	unsigned int ilosc_dzialan;
	unsigned int ilosc_poprawnych;
	unsigned int procent;
};

void Wyswietl(Statystyka_odpowiedzi Statystyka);




#endif

	