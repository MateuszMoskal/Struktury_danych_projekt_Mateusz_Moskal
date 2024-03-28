#pragma once
#include "Elementy.h"
#include "Kontener.h"

class HeadTailSinglyLinkedList : public Kontener
{
private:
	Element* head; // pierwszy wskaźnik
	Element* tail; // drugi wskaźnik 
	int ilosc;
public:
	HeadTailSinglyLinkedList(); // konstruktor 
	HeadTailSinglyLinkedList(const HeadTailSinglyLinkedList& list); // konstruktor kopiujący
	~HeadTailSinglyLinkedList(); // destruktor 
	HeadTailSinglyLinkedList& operator=(const HeadTailSinglyLinkedList& list); // operator przypisania 

	void wyczysc() override;

	void dodajNaPoczatek(int dane) override;
	void dodajNaKoniec(int dane) override;
	bool dodaj(int index, int dane) override;
	bool usun(int index) override;
	bool usunZPoczateku() override;
	bool usunZKonca() override;
	int dajIlosc() const override;
	int dajEmenet(int index) const override;
	void wypisz() const override;

private:
	Element* znajdzElementPrzed(int index) const;
	void skopiuj(const HeadTailSinglyLinkedList& list);
	void skasuj();
};