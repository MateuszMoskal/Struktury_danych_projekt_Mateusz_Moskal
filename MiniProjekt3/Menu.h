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
	Menu(Dictionary* dictionary, string name);
	void run();
private:
	void wypiszMenu();
	void wyczysc();
	void wczytajZPliku();
	void stworzLosowe();

	void dodaj();
	void znajdz();
	void usun();


};


