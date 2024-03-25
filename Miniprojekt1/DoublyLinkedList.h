#pragma once
#include "Kontener.h"
struct Element2
{
	int dane;
	Element2* nast;
	Element2* pop;
};

class DoublyLinkedList : public Kontener
{
private:
	Element2* head;
	Element2* tail;
	int ilosc;
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& list);
	~DoublyLinkedList();
	DoublyLinkedList& operator=(const DoublyLinkedList& list);

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
	Element2* znajdzElementPrzed(int index) const;
	Element2* znajdzElementPrzedOdProdzu(int index) const;
	Element2* znajdzElementPrzedOdTylu(int index) const;
	void skopiuj(const DoublyLinkedList& list);
	void skasuj();
};
