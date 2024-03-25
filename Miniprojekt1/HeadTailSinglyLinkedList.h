#pragma once
#include "Elementy.h"
#include "Kontener.h"

class HeadTailSinglyLinkedList : public Kontener
{
private:
	Element* head;
	Element* tail;
	int ilosc;
public:
	HeadTailSinglyLinkedList();
	HeadTailSinglyLinkedList(const HeadTailSinglyLinkedList& list);
	~HeadTailSinglyLinkedList();
	HeadTailSinglyLinkedList& operator=(const HeadTailSinglyLinkedList& list);

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