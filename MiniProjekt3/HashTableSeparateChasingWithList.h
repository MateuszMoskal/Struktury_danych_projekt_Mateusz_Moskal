#pragma once
#include "Dictionary.h"
#include "HeadSinglyLinkedList.h"
class HashTableSeparateChasingWithList : public Dictionary
{
private:
	HeadSinglyLinkedList* arr; // wskaznik na tablice wskaznikow do do list jednokierunkowych z jednym wskaznikiem (head)
	int arrSize; // rozmiar tablicy 

public:
	HashTableSeparateChasingWithList(int arrSize);
	HashTableSeparateChasingWithList(const HashTableSeparateChasingWithList& hashMap);
	~HashTableSeparateChasingWithList();
	HashTableSeparateChasingWithList& operator=(const HashTableSeparateChasingWithList& hashMap);

	virtual bool insert(int key, int value) override;
	virtual void remove(int key) override;
	virtual bool contains(int key) override;
	virtual int get(int key) override;

	virtual void clean() override;
	virtual void cleanAndResize(int size) override;

private:
	int hash(int key) // funkcja hashujaca obliczajaca indeks dla podanego klucza 
	{
		return key % arrSize; // reszta z dzielenia klucza przez rozmiar tablicy 
	}
};

