#pragma once

#include "PriorytaryQueue.h"
#include <string>

using namespace std;

class Menu
{
private:
	PriorytaryQueue* kolejka; // Wskaznik na kolejke priorytetowa
	string nazwa; // nazwa kolejki 
public:
	Menu(PriorytaryQueue* kolejka, string nazwa);
	void uruchom(); // uruchamianie menu 
private:
	void wypiszMenu(); // metoda wyswietlajaca opcje z menu 
	void wyczysc();//clean
	void wczytajZPliku(); // metoda wczytujaca dane do kolejki z pliku 
	void stworzLosowe(); // metoda stwarzajaca losowe dane do kolejki 

	void dodaj();//insert(int item, int priorytary);
	void wyciagnij();//extractMax()
	void podejrzyj1Element();//peek();
	void zmodyfikujPriorytet();//modyfyKey(int item, int priorytary);

	void wypisz();//wyswietlenie zawartosci kolejki 
	void wypiszIlosc();// getSize();








};

