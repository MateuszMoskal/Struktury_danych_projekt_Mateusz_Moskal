#include "Menu.h"
#include "ConsoleReader.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

Menu::Menu(Dictionary* dictionary, string name)
{
	this->dictionary = dictionary;
	this->name = name;
}
void Menu::run()
{
	int wybor = 0;
	while (wybor != 7)
	{
		wypiszMenu();
		wybor = ConsoleReader::readInt("wybor", 1, 7);

		switch (wybor)
		{
		case 1:
			wczytajZPliku();
			break;
		case 2:
			stworzLosowe();
			break;
		case 3:
			wyczysc();
			break;
		case 4:
			dodaj();
			break;
		case 5:
			znajdz();
			break;
		case 6:
			usun();
			break;
		}
		cout << endl;
	}
}

void Menu::wypiszMenu()
{
	cout << "Menu kolejki z implementacja jako " << name << endl;
	cout << "1 - wczytaj dane z pliku do slownika" << endl;
	cout << "2 - uzupelnij slownik losowymi danymi" << endl;
	cout << "3 - wyczysc slownik" << endl;
	cout << "4 - dodaj element do slownika" << endl;
	cout << "5 - znajdz element o podanym kluczu" << endl;
	cout << "6 - usun element ze slownika" << endl;
	cout << "7 - przejdz do menu glownego" << endl;
	cout << endl;
}

void Menu::wyczysc()//virtual void clean() = 0;
{
	dictionary->cleanAndResize(ConsoleReader::readInt("wybor", 5, 10000000));
	cout << "wyczyszczono slownik i nadano mu nowy rozmiar" << endl;
}
void Menu::wczytajZPliku()
{
	string nazwaPliku = ConsoleReader::readString("nazwe pliku", 3, 1000);

	ifstream plik(nazwaPliku);

	if (!plik.good())
	{
		cout << "nie udalo sie poprawnie otworzyc pliku" << endl;
		return;
	}
	dictionary->clean();
	int key;
	int value;
	while (plik >> key && plik >> value)
	{
		dictionary->insert(key, value);
	}
	plik.close();
	cout << "pomyslnie wczytano plik " << endl;
}

void Menu::stworzLosowe()
{
	int wielkosc = ConsoleReader::readInt("ilosc elementow jaka ma zawierac kolejka", 1, 12);
	dictionary->clean();
	for (int i = 0; i < wielkosc; i++)
	{
		dictionary->insert(rand(), rand());
	}
}

void Menu::dodaj()//virtual void insert(int item, int priorytary) = 0;
{
	int key = ConsoleReader::readInt("wartosc klucza", -1000000, 1000000);
	int value = ConsoleReader::readInt("wartosc", -1000000, 1000000);
	dictionary->insert(key, value);
}
void Menu::znajdz()//virtual void insert(int item, int priorytary) = 0;
{
	int key = ConsoleReader::readInt("wartosc klucza", -1000000, 1000000);
	if (dictionary->contains(key))
	{
		cout << "element o podanym kluczu to:" << dictionary->get(key);
	}
	else
	{
		cout << "nie znaleziono elementu o podanym kluczu" << endl;
	}
}

void Menu::usun()
{
	int key = ConsoleReader::readInt("wartosc klucza", -1000000, 1000000);
	if (dictionary->contains(key))
	{
		dictionary->remove(key);
		cout << "usunieto element o podanym kluczu" << endl;
	}
	else
	{
		cout << "nie znaleziono elementu o podanym kluczu" << endl;
	}
}

