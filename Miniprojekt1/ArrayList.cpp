#include "ArrayList.h"
#include <iostream>

using namespace std;


ArrayList::ArrayList()
{
	wielkosc = 10; // pocz�tkowy rozmiar tablicy
	ilosc = 0; // pocz�tkowa liczba element�w
	tab = new int[wielkosc]; // inicjalizacja tablicy dynamicznej
}

ArrayList::ArrayList(const ArrayList& arrayList) {
	wielkosc = arrayList.wielkosc;
	ilosc = arrayList.ilosc;
	tab = new int[wielkosc];
	for (int i = 0; i < ilosc; i++)
	{
		tab[i] = arrayList.tab[i]; // kopiuje zawartosc 
	}
}

ArrayList::~ArrayList()
{
	delete[] tab; // zwalniam pami�� przy usuwaniu obiektu.
}

void ArrayList::wyczysc()
{
	this->~ArrayList(); // wywo�uje destruktor i powracam do pocz�tkowych warto�ci z Array List::Array List()
	wielkosc = 10;
	ilosc = 0;
	tab = new int[wielkosc];
}

ArrayList& ArrayList::operator=(const ArrayList& arrayList) {
	if (this != &arrayList) { // Sprawdzenie, czy nie przypisujemy obiektu do samego siebie
		ilosc = arrayList.ilosc;
		if (wielkosc != arrayList.wielkosc)
		{
			delete[] tab; // zwalniam pamiec jezeli rozmiary r�ni� si� 
			tab = new int[arrayList.wielkosc];
		}
		for (int i = 0; i < ilosc; i++)
		{
			tab[i] = arrayList.tab[i];
		}

	}
	return *this; // Zwracam referencj� do obiektu, aby umo�liwi� �a�cuchowe przypisania
}

void ArrayList::dodajNaPoczatek(int element)
{
	dodaj(0, element); // Wywo�uje metod� dodaj�c� element na pocz�tek
}

void ArrayList::dodajNaKoniec(int element)
{
	if (ilosc == wielkosc)
	{
		zwiekszTablice(); // Zwi�kszam tablic� je�eli nie jest zape�niona i dodaj� element na ko�cu 
	}
	tab[ilosc] = element;
	ilosc++;
}

bool ArrayList::dodaj(int index, int element)
{
	if (ilosc == wielkosc)
	{
		zwiekszTablice();
	}

	if (index < 0 || ilosc < index)
	{
		return false; // Sprawdzam czy indeks jest poprawny 
	}

	for (int i = ilosc; i >= index; i--)
	{
		tab[i] = tab[i - 1]; // Przesuwam elementy w prawo
	}
	tab[index] = element; // Wstawiam nowy element 
	ilosc++;
}

bool ArrayList::usun(int index)
{
	if (index < 0 || ilosc <= index)
	{
		return false;
	}

	if (ilosc < wielkosc / 3 && wielkosc>10)
	{
		wielkosc = wielkosc / 2; // Zmniejszam rozmiar tablicy je�eli nie spe�nione zosta�y warunki powy�ej
		int* nowa = new int[wielkosc];

		int j = 0;
		for (int i = 0; i < ilosc; i++)
		{
			if (i != index)
			{
				nowa[j] = tab[i];
				j++;
			}
		}
		delete[] tab; // zwalniam star� tablic�
		tab = nowa; // przypisuje elementy do nowej tablicy 
	}
	else
	{
		for (int i = index; i < ilosc - 1; i++)
		{
			tab[i] = tab[i + 1]; // Przesuwam elementy w lewo 
		}
	}
	ilosc--; // Zmniejszam liczb� element�w 
	return true;
}

bool ArrayList::usunZPoczateku()
{
	return usun(0); // Usuwam element z pocz�tku listy 
}
bool ArrayList::usunZKonca()
{
	return usun(ilosc - 1); // Usuwam element z ko�ca listy 
}

int ArrayList::dajIlosc() const
{
	return ilosc; // Zwracam liczb� element�w 
}

int ArrayList::dajEmenet(int index) const
{
	return tab[index]; // Zwracam element kt�ry znajduje si� na danym indeksie
}


void ArrayList::zwiekszTablice()
{
	wielkosc = wielkosc * 2; // Zwi�kszenie rozmiaru tablicy 
	int* nowa = new int[wielkosc];
	for (int i = 0; i < ilosc; i++)
	{
		nowa[i] = tab[i]; // kopiuje zawarto��
	}
	delete[] tab;
	tab = nowa;
}

void ArrayList::wypisz() const
{
	cout << "[";
	if (ilosc > 0)
	{
		cout << dajEmenet(0); // Wypisuje pierwszy element 
	}
	for (int i = 1; i < dajIlosc(); i++)
	{
		cout << ", " << dajEmenet(i);
	}
	cout << "]" << endl;
}

