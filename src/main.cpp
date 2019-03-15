#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

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
  LZespolona Poprawny_Wynik;
  LZespolona Odp_Uzytkownika;
  Statystyka_odpowiedzi Statystyka = {0,0,0};

  
  
  while (PobierzNastepnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    Statystyka.ilosc_dzialan++;
    cout<<"\n:? Podaj wynik operacji: ";
    cout<<WyrZ_PytanieTestowe;

    Poprawny_Wynik = Oblicz(WyrZ_PytanieTestowe);

    cout<<"\n   Twoja odpowiedz: ";
    cin>>Odp_Uzytkownika;
    for(int i = 2; i>=1 && cin.fail() ; i--)
    {
      cin.clear();
      cin.ignore(1000,'\n');
      cout<<"Blad zapisu liczby,";
      cout<<" sprobuj jeszcze raz\n";
      cout<<"Zostalo jeszcze: "<<i<<" prob\n";
      cout<<"Twoja odpowiedz: ";
      cin>>Odp_Uzytkownika;
    }
      cin.clear();
    if(Poprawny_Wynik == Odp_Uzytkownika){
      Statystyka.ilosc_poprawnych++;
      cout<<":) Odpowiedz poprawna\n";

    }else{ 
      cout<<":( Blad. Poprawny Wynik to: ";
      cout<<Poprawny_Wynik;
      cout<<endl;
    }


  }
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  Wyswietl(Statystyka);
//Test dla wczytania calego wyrazenia zespolonego z konsoli a nastepnie obliczenie go

  cout<<"Podaj dzialanie a podam wynik"<<endl;
  cin>>WyrZ_PytanieTestowe;
  while(WyrZ_PytanieTestowe.Op == Bledny_znak)
  {
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Zostal wpisany nieprawidlowy znak\n";
    cin>>WyrZ_PytanieTestowe;
  }
  Poprawny_Wynik = Oblicz(WyrZ_PytanieTestowe);
  cout<<Poprawny_Wynik;
  cout<<endl;
  

}
