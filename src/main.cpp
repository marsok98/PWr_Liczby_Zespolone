#include <iostream>
#include <cstring>
#include "BazaTestu.hh"
#include "Statystyka.hh"




using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny, plik." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  Statystyka_odpowiedzi Statystyka = {0,0,0};

  
  if(strcmp(argv[1], "plik"))
  {
    while (PobierzNastepnePytanie(&BazaT,&WyrZ_PytanieTestowe))
      ObslugaPytan(Statystyka,WyrZ_PytanieTestowe);
  }
  else
  {
    Test_z_Pliku(Statystyka);
  }

  Wyswietl(Statystyka);
  
}
