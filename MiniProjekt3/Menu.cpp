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
		wypiszMenu(); // Wyœwietlenie menu
		wybor = ConsoleReader::readInt("wybor", 1, 7);

		switch (wybor)
		{
		case 1:
			wczytajZPliku();
			break;
		case 2:
			stworzLosowe(); // Losowe dane 
			break;
		case 3:
			wyczysc(); // Wyczysc s³ownik
			break;
		case 4:
			dodaj(); // Dodaj element do s³ownika
			break;
		case 5:
			znajdz(); // Znajdz element w s³owniku
			break;
		case 6:
			usun(); // // Usun element ze s³ownika
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

// Funkcja czyszcz¹ca s³ownik i ustawiaj¹ca nowy rozmiar
void Menu::wyczysc()
{
	dictionary->cleanAndResize(ConsoleReader::readInt("wybor", 5, 10000000));
	cout << "wyczyszczono slownik i nadano mu nowy rozmiar" << endl;
}
// Funkcja wczytuj¹ca dane z pliku
void Menu::wczytajZPliku()
{
	string nazwaPliku = ConsoleReader::readString("nazwe pliku", 3, 1000);

	ifstream plik(nazwaPliku); // Otwarcie pliku

	if (!plik.good())
	{
		cout << "nie udalo sie poprawnie otworzyc pliku" << endl;
		return;
	}
	dictionary->clean(); // Czyszczenie slownika
	int key;
	int value;
	while (plik >> key && plik >> value)
	{
		dictionary->insert(key, value); // Wstawienie kluczy i wartoœci do s³ownika
	}
	plik.close(); // Zamkniêcie pliku
	cout << "pomyslnie wczytano plik " << endl;
}

// Funkcja tworz¹ca losowe dane
void Menu::stworzLosowe()
{
	int wielkosc = ConsoleReader::readInt("ilosc elementow jaka ma zawierac kolejka", 1, 12);
	dictionary->clean();
	for (int i = 0; i < wielkosc; i++)
	{
		dictionary->insert(rand(), rand()); // Wstawienie losowych wartoœci do s³ownika
	}
}
// Funkcja dodaj¹ca element do s³ownika
void Menu::dodaj()
{
	int key = ConsoleReader::readInt("wartosc klucza", -1000000, 1000000);
	int value = ConsoleReader::readInt("wartosc", -1000000, 1000000);
	dictionary->insert(key, value); // Wstawienie klucza i wartoœci do s³ownika
}

// Funkcja znajduj¹ca element w s³owniku
void Menu::znajdz()
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
// Funkcja usuwaj¹ca element ze s³ownika
void Menu::usun()
{
	int key = ConsoleReader::readInt("wartosc klucza", -1000000, 1000000);
	if (dictionary->contains(key))
	{
		dictionary->remove(key); // Usuniêcie elementu
		cout << "usunieto element o podanym kluczu" << endl;
	}
	else
	{
		cout << "nie znaleziono elementu o podanym kluczu" << endl;
	}
}

