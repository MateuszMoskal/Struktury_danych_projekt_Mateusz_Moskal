#pragma once
#include "Elementy.h"
#include "Kontener.h"

class HeadSinglyLinkedList : public Kontener
{
private:
	Element* head; // wskaźnik na listę jednokierunkową 
	int ilosc;
public:
	HeadSinglyLinkedList(); // konstruktor 
	HeadSinglyLinkedList(const HeadSinglyLinkedList& list); // konstruktor kopiujący
	~HeadSinglyLinkedList(); // destruktor 
	HeadSinglyLinkedList& operator=(const HeadSinglyLinkedList& list);

	void wyczysc() override; // czyszczenie listy 

	void dodajNaPoczatek(int dane) override; // dodawanie metody na początek 
	void dodajNaKoniec(int dane) override; // dodawanie metody na koniec 
	bool dodaj(int index, int dane) override; // dodawanie metody na losowe miejsce 
	bool usun(int index) override; // usuwanie metody z losowego miejsca 
	bool usunZPoczateku() override; // usuwanie metody z początku 
	bool usunZKonca() override; // usuwanie metody z końca 
	int dajIlosc() const override; // wypisanie ilosci elementów 
	int dajEmenet(int index) const override; // wypisanie danego elementu
	void wypisz() const override; // wypisanie elementów 

private:
	Element* znajdzElementPrzed(int index) const; // znajdowanie elementu przed podanym indeksie 
	void skopiuj(const HeadSinglyLinkedList& list);
	void skasuj();

};