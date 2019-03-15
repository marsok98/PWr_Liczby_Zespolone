#include "Statystyka.hh"
#include <iostream>
using namespace std;




void Wyswietl(Statystyka_odpowiedzi Statystyka )
{
	cout<<"Ilosc wykonanych dzialan: "<<Statystyka.ilosc_dzialan<<endl;
	cout<<"Ilosc poprawnych: "<<Statystyka.ilosc_poprawnych<<endl;
	cout<<"Ilosc blednych:  "<<Statystyka.ilosc_dzialan-Statystyka.ilosc_poprawnych<<endl;
	Statystyka.procent=(float)100*Statystyka.ilosc_poprawnych/Statystyka.ilosc_dzialan;
	cout<<"Wynik procentowy poprawnych odpowiedzi: "<<Statystyka.procent<<"%"<<endl;
}


void ObslugaPytan(Statystyka_odpowiedzi & Statystyka, WyrazenieZesp WyrZ_PytanieTestowe)
{
	
	LZespolona Poprawny_Wynik;
 	LZespolona Odp_Uzytkownika;

 	
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


