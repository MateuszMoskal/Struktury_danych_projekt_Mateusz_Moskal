#include "Menu.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include "Pobieranie.h"

using namespace std;

Menu::Menu(Kontener* kontener, string nazwa)
{
	this->kontener = kontener;
	this->nazwa = nazwa;

}
void Menu::uruchom()
{
	int wybor = 0;
	while (wybor != 12)
	{
		wypiszMenu();
		wybor = Pobieranie::pobierzInt("wybor", 1, 12);

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
			dodajNaPoczatek();
			break;
		case 7:
			dodajNaWybranyIndex();
			break;
		case 8:
			dodajNaKoniec();
			break;
		case 9:
			usunZPoczatku();
			break;
		case 10:
			usunZWybranegoIndeksu();
			break;
		case 11:
			usunZKonca();
			break;
		}
	}
	cout << endl;
}
void Menu::wypiszMenu()
{
	cout << "Menu " << nazwa << endl;
	cout << "1 - wypisz " << nazwa << endl;
	cout << "2 - wypisz ilosc " << nazwa << endl;
	cout << "3 - wyczysc " << nazwa << endl;
	cout << "4 - wczytaj dane z pliku do " << nazwa << endl;
	cout << "5 - uzupelnij " << nazwa << " losowymi danymi" << endl;
	cout << "6 - dodaj element na poczatej " << nazwa << endl;
	cout << "7 - dodaj element w wybrane miejsce " << nazwa << endl;
	cout << "8 - dodaj element na koniec " << nazwa << endl;
	cout << "9 - usun element z poczatku " << nazwa << endl;
	cout << "10 - usun element z wybranego miejsca " << nazwa << endl;
	cout << "11 - usun element z koniea " << nazwa << endl;
	cout << "12 - przejdz do menu glownego" << nazwa << endl;
	cout << endl;
}

void Menu::wypisz()
{
	cout << nazwa << endl;
	kontener->wypisz();
}
void Menu::wypiszIlosc()
{
	cout << "ilosc elementow w " << nazwa << " = " << kontener->dajIlosc() << endl;
}

void Menu::wyczysc()
{
	kontener->wyczysc();
	cout << "kontener " << nazwa << " zostal wyczyszczony" << endl;
}
void Menu::wczytajZPliku()
{
	string nazwaPliku = Pobieranie::pobierzString("nazwe pliku", 3, 1000);

	ifstream plik(nazwaPliku);

	if (!plik.good())
	{
		cout << "nie udalo sie poprawnie otworzyc pliku" << endl;
		return;
	}
	kontener->wyczysc();
	int liczba;
	while (plik >> liczba)
	{
		kontener->dodajNaKoniec(liczba);
	}
	plik.close();
	cout << "pomyslnie wczytano plik " << endl;
}
void Menu::stworzLosowe()
{
	int wielkosc = Pobieranie::pobierzInt("ilosc elementow jaka ma zawierac kontener", 1, 12);
	kontener->wyczysc();
	for (int i = 0; i < wielkosc; i++)
	{
		kontener->dodajNaKoniec(rand());
	}
}
void Menu::dodajNaPoczatek()
{
	int dane = Pobieranie::pobierzInt("podaj wartosc elementu ktoryma zostac dodany na poczatek", -1000000, 1000000);
	kontener->dodajNaPoczatek(dane);
}

void Menu::dodajNaWybranyIndex()
{
	int dane = Pobieranie::pobierzInt("podaj wartosc elementu ktoryma zostac dodany na poczatek", -1000000, 1000000);
	int index = Pobieranie::pobierzInt("podaj index na ktory ma zostac dodany element", 0, kontener->dajIlosc());
	kontener->dodaj(index, dane);
}

void Menu::dodajNaKoniec()
{
	int dane = Pobieranie::pobierzInt("podaj wartosc elementu ktoryma zostac dodany na koniec", -1000000, 1000000);
	kontener->dodajNaKoniec(dane);
}

void Menu::usunZPoczatku()
{
	if (kontener->dajIlosc() == 0)
	{
		cout << "nie mozna usuwac z " << nazwa << " poniewaz kontener jest pusty" << endl;
		return;
	}
	kontener->usunZPoczateku();
	cout << "usunieto poczatkowy element z " << nazwa << endl;

}
void Menu::usunZWybranegoIndeksu()
{
	if (kontener->dajIlosc() == 0)
	{
		cout << "nie mozna usuwac z " << nazwa << " poniewaz kontener jest pusty" << endl;
		return;
	}
	int index = Pobieranie::pobierzInt("podaj index na ktory ma zostac dodany element", 0, kontener->dajIlosc());
	kontener->usun(index);
	cout << "usunieto element o indexie " << index << " z " << nazwa << endl;
}
void Menu::usunZKonca()
{
	if (kontener->dajIlosc() == 0)
	{
		cout << "nie mozna usuwac z " << nazwa << " poniewaz kontener jest pusty" << endl;
		return;
	}
	kontener->usunZKonca();
	cout << "usunieto koncowy element z " << nazwa << endl;
}

