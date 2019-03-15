#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
#include <fstream>
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
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

  
  /*
  while (PobierzNastepnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    ObslugaPytan(Statystyka,WyrZ_PytanieTestowe);
  }
  
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  Wyswietl(Statystyka);
  */

  fstream plik;
  plik.open("plik.txt",ios::in);

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
  Wyswietl(Statystyka);



  

}
