#pragma once
#include "PriorytaryQueue.h"

struct Element
{
	int value; // wartosc elementu 
	int priorytary; // priorytet elementu 
	Element* nast; // wskaznik na nastepny element 
};

class HeadSinglyLinkedList : public PriorytaryQueue
{
private:
	Element* head; // wskaznik na poczatek listy 
	int size; // rozmiar listy 
public:
	HeadSinglyLinkedList(); // konstruktor listy wiazanej z jednym wskaznikiem 
	HeadSinglyLinkedList(const HeadSinglyLinkedList& list); // konstruktor kopiujacy 
	~HeadSinglyLinkedList(); // destruktor listy wiazanej z jednym wskaznikiem 
	HeadSinglyLinkedList& operator=(const HeadSinglyLinkedList& list); // operator przypisania 

public:
	void insert(int item, int priorytary) override;
	void modyfyKey(int item, int priorytary) override;
	int extractMax() override;
	int peek() override;

	void clean() override;
	int getSize() override;
	void print() override;
private:
	void copy(const HeadSinglyLinkedList& list); // Metoda kopiujaca elementy z jednej listy do drugiej
	Element* findItemBefore(int value) const; // Metoda znajdujaca element przed wskazana wartoscia w kolejce
	void insert(Element* itemBeforeStart, Element* itemInserted); // Metoda wstawiajaca nowy element przed wskazanym elementem w kolejce
};


