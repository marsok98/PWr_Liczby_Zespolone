#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZespolona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

ostream & operator << (ostream & wyj, LZespolona Skl1);


istream & operator >> (istream & wej, LZespolona &Skl1);





double Modul2(LZespolona Skl1);
LZespolona Sprzezenie(LZespolona Skl1);


LZespolona  operator / (LZespolona  Skl1,  double dzielnik );

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

bool 	    operator == (LZespolona Prawidlowa, LZespolona Do_Porownania);

istream & wczytaj_i_sprawdz_znak(istream &wej,char znak_prawidlowy);
istream & wczytaj_sprawdz_zapisz_liczbe(istream &wej, double &liczba);


#endif
