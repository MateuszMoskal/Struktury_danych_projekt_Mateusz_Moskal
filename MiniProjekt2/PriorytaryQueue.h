#pragma once

class PriorytaryQueue
{
public:
	virtual void insert(int item, int priorytary) = 0; // funkcja sluzy do wstawiania elementu do kolejki 
	virtual int extractMax() = 0; // funkcja sluzy do usuwania i wyswietlania elementu o najwyzszym priorytecie
	virtual int peek() = 0; // funkcja s³uzy do wyswietlania elementu o najwyzszym priorytecie
	virtual void modyfyKey(int item, int priorytary) = 0; // funkcja s³u¿y do modyfikowania priorytetu danego elementu 
	virtual void clean() = 0; // funkcja usuwa wszystkie elementy z kolejki priorytetowej 
	virtual int getSize() = 0; // funkcja zwraca aktualny rozmiar kolejki priorytetowej 
	virtual void print() = 0; // funkcja zwracaj¹ca zawartosc kolejki 
};
