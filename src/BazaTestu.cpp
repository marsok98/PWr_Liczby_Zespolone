#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include "BazaTestu.hh"


using namespace std;

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {1,0}},
  };


static WyrazenieZesp TestTrudny[] = 
  { {{2.66,9.77},     Op_Dodaj,   {2.44,88.54}},
    {{8.44,7.22},     Op_Odejmij, {7.45,44.66}},
    {{567.22,78.72},  Op_Mnoz,    {55.78,123.66}},
    {{723.55,1234.6}, Op_Dziel,   {45.72,164.88}},
  };




/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *   
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}




/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych 
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *       
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) 
  {
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  else if(!strcmp(sNazwaTestu, "trudny"))
  {
    UstawTest(wskBazaTestu,TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }
  else if (!strcmp(sNazwaTestu, "plik"))
  {
    return true;
  }
  else
  {
    cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
    return false;
  }  
}



/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
bool PobierzNastepnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}



/*void Test_z_Pliku(Statystyka_odpowiedzi &Statystyka, WyrazenieZesp WyrZ_PytanieTestowe)
{
  fstream plik;
  string nazwa_pliku;
  cin>>nazwa_pliku;
  plik.open(nazwa_pliku,ios::in);
  if(!plik.good())
  {
    cerr<<"Blad otwarcia pliku\n";
    exit(0);
  }

  while(!plik.eof()){
      plik>>WyrZ_PytanieTestowe;
      if(plik.fail())
      {
        cerr<<"\nNapotkano bledne wyrazenie, zostalo ono pominiete\n";
        plik.clear();
        plik.ignore(1000,'\n');
      }
      else
      {
        ObslugaPytan(Statystyka,WyrZ_PytanieTestowe);
      }
  }
  plik.close();
}
*/