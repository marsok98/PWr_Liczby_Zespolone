#include "Statystyka.hh"
#include <iostream>
using namespace std;




void Wyswietl(Statystyka_odpowiedzi Statystyka)
{
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  
	cout<<"Ilosc wykonanych dzialan: "<<Statystyka.ilosc_dzialan<<endl;
	cout<<"Ilosc poprawnych: "<<Statystyka.ilosc_poprawnych<<endl;
	cout<<"Ilosc blednych:  "<<Statystyka.ilosc_dzialan-Statystyka.ilosc_poprawnych<<endl;
	Statystyka.procent=(float)100*Statystyka.ilosc_poprawnych/Statystyka.ilosc_dzialan;
	cout<<"Wynik procentowy poprawnych odpowiedzi: "<<Statystyka.procent<<"%"<<endl;
}




