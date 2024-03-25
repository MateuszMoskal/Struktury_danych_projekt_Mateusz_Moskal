#pragma once
#include "Kontener.h"

class ArrayList : public Kontener
{
private:
	int* tab; // Wska�nik do tablicy przechowuj�cej elementy 
	int ilosc;
	int wielkosc;
public:
	ArrayList(); // Konstruktor 
	ArrayList(const ArrayList& arrayList); // Konstruktor kopiuj�cy
	~ArrayList(); //Destruktor
	ArrayList& operator=(const ArrayList& arrayList); // Przeci��enie operatora

	void wyczysc() override; // metoda usuwaj�ca tablic�

	void dodajNaPoczatek(int dane) override; // metoda dodaj�ca element na pocz�tku 
	void dodajNaKoniec(int dane) override; // metoda dodaj�ca element na koniec 
	bool dodaj(int index, int dane) override; // metoda dodaj�ca element w losowe miejsce w li�cie
	bool usun(int index) override; // metoda usuwaj�ca element z losowego miejsca w li�cie
	bool usunZPoczateku() override; // metoda usuwaj�ca element z pocz�tku 
	bool usunZKonca() override; // metoda usuwaj�ca element z ko�ca 

	int dajIlosc() const override; // metoda zwracaj�ca liczb� element�w 
	int dajEmenet(int index) const override; // metoda zwracaj�ca element na podanym indeksie 
	void wypisz() const override; // metoda wypisuj�ca zawarto�� tablicy 

	// override zabezpiecza przed przes�anianiem funkcji z klasy pochodnej funkcji z klasy bazowej

private:
	void zwiekszTablice(); // metoda do zwi�kszania rozmiaru tablicy 
};


