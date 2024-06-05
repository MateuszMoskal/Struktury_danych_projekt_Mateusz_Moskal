#pragma once
struct ItemList
{
	int key; // klucz elementu 
	int value; // wartosc elementu 
	ItemList* nast; // wskaznik na nastepny element w liscie 
};

class HeadSinglyLinkedList
{
private:
	ItemList* head; // wskaznik na pierwszy element w liscie 
	int count; // liczba elementow 
public:
	HeadSinglyLinkedList(); // konstruktor 
	HeadSinglyLinkedList(const HeadSinglyLinkedList& list); // konstruktor kopiujacy 
	~HeadSinglyLinkedList(); // destruktor 
	HeadSinglyLinkedList& operator=(const HeadSinglyLinkedList& list); // operator przypisania 

	void wyczysc(); // usuwa wszystkie elementy 

	void addOrUpdate(int key, int value); //
	bool remove(int key);
	int dajIlosc() const;
	void wypisz() const;
	ItemList* findItem(int key) const;
private:
	bool removeFromBegin(); // usuwa pierwszy element z listy
	ItemList* findItemBefore(int key) const; // Znajduje element poprzedzaj¹cy element o podanym kluczu

	void copy(const HeadSinglyLinkedList& list); // kopiowanie zawartosci listy 
};