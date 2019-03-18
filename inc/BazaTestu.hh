#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"
#include "Statystyka.hh"


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
};


/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );
/*
 * Udostepnia nastepne pytanie z bazy.
 */
bool PobierzNastepnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );

/* 
 * Realizuje obsluge pytan w postaci pobierania pytania z bazy, obliczenia go, pobranie odpowiedzi uzytkownika
 * Sprawdzenie tej odpowiedzi oraz obsluga statystyki
 */
void ObslugaPytan(Statystyka_odpowiedzi & Statystyka, WyrazenieZesp WyrZ_PytanieTestowe);


/*
 * Realizuje wczytywanie wyrazen z pliku tekstowego
 */
void Test_z_Pliku(Statystyka_odpowiedzi &Statystyka);

#endif
