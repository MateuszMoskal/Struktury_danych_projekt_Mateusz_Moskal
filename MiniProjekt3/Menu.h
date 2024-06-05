#pragma once
#include <string>
#include "Dictionary.h"
using namespace std;

class Menu
{
private:
	Dictionary* dictionary;
	string name;

public:
	Menu(Dictionary* dictionary, string name); // inicjalizuje wskaznik na slownik 
	void run(); // uruchomienie menu 
private:
	void wypiszMenu(); // wypisanie dostepnych opcji w menu 
	void wyczysc(); // usuniecie elementow ze slownika 
	void wczytajZPliku(); // wczytanie danych z pliku 
	void stworzLosowe(); // tworzenie losowych danych i dodanie ich do slownika 

	void dodaj(); // dodanie nowego elementu 
	void znajdz(); // znalezienie i wypisanie elementu o podanym kluczu
	void usun(); // usuniecie elementu o podanymm kluczu


};


