#include "Menu.h"
#include "Pobieranie.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;


Menu::Menu(PriorytaryQueue* kolejka, string nazwa)
{
	this->kolejka = kolejka; // wskaznik do kolejki 
	this->nazwa = nazwa;
}
void Menu::uruchom()
{
	int wybor = 0;
	while (wybor != 10)
	{
		wypiszMenu(); //wyswetlenie menu dla kolejki 
		wybor = Pobieranie::pobierzInt("wybor", 1, 10);

		switch (wybor)
		{
		case 1:
			wypisz();
			break;
		case 2:
			wypiszIlosc();
			break;
		case 3:
			wyczysc();
			break;
		case 4:
			wczytajZPliku();
			break;
		case 5:
			stworzLosowe();
			break;
		case 6:
			dodaj();
			break;
		case 7:
			wyciagnij();
			break;
		case 8:
			podejrzyj1Element();
			break;
		case 9:
			zmodyfikujPriorytet();
			break;
		}
	}
	cout << endl;
}
void Menu::wypiszMenu()
{
	cout << "Menu kolejki z implementacja jako " << endl;
	cout << "1 - wypisz kolejke" << endl;
	cout << "2 - wypisz ilosc kolejki" << endl;
	cout << "3 - wyczysc kolejke" << endl;
	cout << "4 - wczytaj dane z pliku do kolejki" << endl;
	cout << "5 - uzupelnij kolejke" << " losowymi danymi" << endl;
	cout << "6 - dodaj element do kolejki " << endl;
	cout << "7 - wyciagnij 1 element z kolejki " << endl;
	cout << "8 - podejrzyj element w kolejce " << endl;
	cout << "9 - zmodyfikuj priorytet wybranego elementu " << endl;
	cout << "10 - przejdz do menu glownego" << nazwa << endl;
	cout << endl;
}
// metoda usuwajaca wszystkie elementy kolejki 
void Menu::wyczysc()
{
	kolejka->clean();
	cout << "kolejka zostala wyczyszczona" << endl;
}
// Wczytanie danych z pliku do kolejki
void Menu::wczytajZPliku()
{
	string nazwaPliku = Pobieranie::pobierzString("nazwe pliku", 3, 1000);

	ifstream plik(nazwaPliku); // otwarcie pliku do odczytu 

	if (!plik.good())
	{
		cout << "nie udalo sie poprawnie otworzyc pliku" << endl;
		return;
	}
	kolejka->clean();
	int liczba;
	int priorytet;
	while (plik >> liczba && plik >> priorytet)
	{
		kolejka->insert(liczba, priorytet); // wstawienie elementu do kolejki 
	}
	plik.close();
	cout << "pomyslnie wczytano plik " << endl;
}
void Menu::stworzLosowe()
{
	int wielkosc = Pobieranie::pobierzInt("ilosc elementow jaka ma zawierac kolejka", 1, 12);
	kolejka->clean();
	for (int i = 0; i < wielkosc; i++)
	{
		kolejka->insert(rand(), rand()); // wstawianie losowego elementu do kolejki 
	}
}

void Menu::dodaj()
{
	int dane = Pobieranie::pobierzInt("wartosc elementu", -1000000, 1000000); // pobranie wartosci elementu od uzytkownika
	int priorytet = Pobieranie::pobierzInt("priorytet", -1000000, 1000000); // pobranie priorytetu elementu od uzytkownika 
	kolejka->insert(dane, priorytet);
}
void Menu::wyciagnij()
{
	int dane = kolejka->extractMax();
	cout << "element wyciagniety z kolejki ma wartosc: " << dane << endl;
}
void Menu::podejrzyj1Element()
{
	int dane = kolejka->peek(); // pobranie wartosci najblizszego elementu w kolejce 
	cout << "najblizszy element w kolejce ma wartosc: " << dane << endl;
}
void Menu::zmodyfikujPriorytet()
{
	int dane = Pobieranie::pobierzInt("wartosc elementu", -1000000, 1000000);
	int priorytet = Pobieranie::pobierzInt("nowy priorytet", -1000000, 1000000);
	kolejka->modyfyKey(dane, priorytet); // zmiana priorytetu danego elementu w kolejce 
}
void Menu::wypisz()
{
	cout << nazwa << ":" << endl;
	kolejka->print(); // wyswietlenie elementow kolejki 
}
void Menu::wypiszIlosc()
{
	cout << "ilosc elementow w kolejce = " << kolejka->getSize() << endl; // zwraca ilosc elementow w kolejce 
}