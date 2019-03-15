#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel, Bledny_znak };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
*/

struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Operator wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

ostream & operator << (ostream & wyj, Operator Op);
ostream & operator << (ostream & wyj, WyrazenieZesp WyrZ);
istream & operator >> (istream & wej, Operator &Op);
istream & operator >> (istream & wej, WyrazenieZesp &WyrZ);


LZespolona Oblicz(WyrazenieZesp  WyrZ);

#endif
