#pragma once
#include <string>
#include "Kontener.h"

using namespace std;

class Menu
{
private:
	Kontener* kontener; // wskaźnik na obiekt klasy kontener 
	string nazwa; // nazwa menu 
public:
	Menu(Kontener* kontener, string nazwa);
	void uruchom(); // uruchomienie menu 
private:
	void wypiszMenu();
	void wyczysc(); 
	void wczytajZPliku(); // wczytywanie danych z pliku do kontenera 
	void stworzLosowe(); // metoda tworząca losowe dane 

	void dodajNaKoniec();
	void dodajNaWybranyIndex();
	void dodajNaPoczatek();

	void usunZPoczatku();
	void usunZWybranegoIndeksu();
	void usunZKonca(); 

	void wypisz(); // metoda wypisująca zawartość kontenera 
	void wypiszIlosc(); // metoda wypisująca ilość elementów 


};
