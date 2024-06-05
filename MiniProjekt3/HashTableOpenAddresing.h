#pragma once
#include "Dictionary.h"

// Struktura reprezentujaca element w tablicy hashujacej 
struct Item
{
	int key; // klucz elementu 
	int value; // wartosc elementu 
};


class HashTableOpenAddresing : public Dictionary
{
private:
	Item** arr;
	int arrSize; // rozmiar tablicy 
public:
	HashTableOpenAddresing(int arrSize);
	HashTableOpenAddresing(const HashTableOpenAddresing& hashMap);
	~HashTableOpenAddresing();
	HashTableOpenAddresing& operator=(const HashTableOpenAddresing& hashMap);

	virtual bool insert(int key, int value) override;
	virtual void remove(int key) override;
	virtual bool contains(int key) override;
	virtual int get(int key) override;

	virtual void clean() override;
	virtual void cleanAndResize(int size) override;

	int hash(int key) // funkcja hashujaca obliczajaca indeks dla podanego klucza 
	{
		return key % arrSize; // reszta z dzielenia klucza przez rozmiar tablicy 
	}
	int findIndex(int key);

};

