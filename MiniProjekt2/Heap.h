#pragma once

#include "PriorytaryQueue.h"

struct Item
{
	int priorytary; // priorytet elementu 
	int value; // wartosc elementu 
};

class Heap : public PriorytaryQueue
{
private:
	Item* arr; // tablica przechowujaca elementy kolejki priorytetowej
	int size;
	int maxSize; // maksymalny rozmiar 
public:
	Heap(); // konstruktor dla kopca 
	Heap(const Heap& arrayList); // konstruktor kopiujacy 
	~Heap(); // destruktor dla kopca 
	Heap& operator=(const Heap& arrayList); // operator przypisania 

	void insert(int item, int priorytary) override;
	int extractMax() override;
	int peek() override;
	void modyfyKey(int item, int priorytary) override;
	void clean() override;
	int getSize() override;
	void print() override;
private:
	void moveLeft(int index); // Metoda przesuwajaca element w lewo w celu naprawy struktury kopca (zapytac)
	void moveRight(int index); // Metoda przesuwajaca element w prawo w celu naprawy struktury kopca (zapytac)

	void decreaseArray(); // Metoda zmniejszajaca rozmiar tablicy
	void increaseArray(); // Metoda zwiekszajaca rozmiar tablicy
	int findIndex(int item); // Metoda znajdujaca indeks elementu o danej wartoœci
};
