#pragma once
#include "Kontener.h"
struct Element2
{
	int dane;
	Element2* nast; // wskaźnik na następny element 
	Element2* pop; // wskaźnik na poprzedni element 
};

class DoublyLinkedList : public Kontener
{
private:
	Element2* head; // wskaźnik pierwszy
	Element2* tail; // wskaźnik drugi
	int ilosc; // liczba elementów 
public:
	DoublyLinkedList(); // inicjalizacja pustej listy
	DoublyLinkedList(const DoublyLinkedList& list); // konstruktor kopiujący tworzący listę
	~DoublyLinkedList(); // destruktor zwalniający pamięć
	DoublyLinkedList& operator=(const DoublyLinkedList& list); // operator przypisania

	void wyczysc() override; // wyczyszczanie zawartości listy 

	void dodajNaPoczatek(int dane) override; // dodanie elementu na początek 
	void dodajNaKoniec(int dane) override;  // dodanie elementu na koniec 
	bool dodaj(int index, int dane) override; // dodanie elementu na dowolne miejsce 
	bool usun(int index) override; // usuwanie elementu z dowolnego miejsca 
	bool usunZPoczateku() override; // usuwanie elementu z początku 
	bool usunZKonca() override; // usuwanie elementu z końca 
	int dajIlosc() const override; // wypisanie ilości elementów 
	int dajEmenet(int index) const override; // wypisanie danego elementu 
	void wypisz() const override; // wypisanie zawartości listy 

private:
	Element2* znajdzElementPrzed(int index) const; // metoda pomocnicza znajdująca element poprzedzający element o podanym indeksie 
	Element2* znajdzElementPrzedOdProdzu(int index) const; // metoda pomocnicza znajdująca element poprzedzający element o podanym indeksie od przodu 
	Element2* znajdzElementPrzedOdTylu(int index) const; // metoda pomocnicza znajdująca element poprzedzający element o podanym indeksie od tyłu 
	void skopiuj(const DoublyLinkedList& list); //metoda kopiująca zawartość listy 
	void skasuj(); // metoda usuwająca elementy listy
};
