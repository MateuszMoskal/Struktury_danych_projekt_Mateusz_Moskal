#pragma once
#include <string>
#include "Kontener.h"

using namespace std;

class Menu
{
private:
	Kontener* kontener;
	string nazwa;
public:
	Menu(Kontener* kontener, string nazwa);
	void uruchom();
private:
	void wypiszMenu();
	void wyczysc();
	void wczytajZPliku();
	void stworzLosowe();

	void dodajNaKoniec();
	void dodajNaWybranyIndex();
	void dodajNaPoczatek();

	void usunZPoczatku();
	void usunZWybranegoIndeksu();
	void usunZKonca();

	void wypisz();
	void wypiszIlosc();


};
