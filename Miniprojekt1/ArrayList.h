#pragma once
#include "Kontener.h"

class ArrayList : public Kontener
{
private:
	int* tab; // WskaŸnik do tablicy przechowuj¹cej elementy 
	int ilosc;
	int wielkosc;
public:
	ArrayList(); // Konstruktor 
	ArrayList(const ArrayList& arrayList); // Konstruktor kopiuj¹cy
	~ArrayList(); //Destruktor
	ArrayList& operator=(const ArrayList& arrayList); // Przeci¹¿enie operatora

	void wyczysc() override; // metoda usuwaj¹ca tablicê

	void dodajNaPoczatek(int dane) override; // metoda dodaj¹ca element na pocz¹tku 
	void dodajNaKoniec(int dane) override; // metoda dodaj¹ca element na koniec 
	bool dodaj(int index, int dane) override; // metoda dodaj¹ca element w losowe miejsce w liœcie
	bool usun(int index) override; // metoda usuwaj¹ca element z losowego miejsca w liœcie
	bool usunZPoczateku() override; // metoda usuwaj¹ca element z pocz¹tku 
	bool usunZKonca() override; // metoda usuwaj¹ca element z koñca 

	int dajIlosc() const override; // metoda zwracaj¹ca liczbê elementów 
	int dajEmenet(int index) const override; // metoda zwracaj¹ca element na podanym indeksie 
	void wypisz() const override; // metoda wypisuj¹ca zawartoœæ tablicy 

	// override zabezpiecza przed przes³anianiem funkcji z klasy pochodnej funkcji z klasy bazowej

private:
	void zwiekszTablice(); // metoda do zwiêkszania rozmiaru tablicy 
};


