#pragma once
#include "Elementy.h"
#include "Kontener.h"

class HeadSinglyLinkedList : public Kontener
{
private:
	Element* head;
	int ilosc;
public:
	HeadSinglyLinkedList();
	HeadSinglyLinkedList(const HeadSinglyLinkedList& list);
	~HeadSinglyLinkedList();
	HeadSinglyLinkedList& operator=(const HeadSinglyLinkedList& list);

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
	void skopiuj(const HeadSinglyLinkedList& list);
	void skasuj();

};