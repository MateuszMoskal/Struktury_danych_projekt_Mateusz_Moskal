#pragma once
#include "Dictionary.h"
#include "BinarySearchTree.h"
class HashTableSeparateChasingWithBST : public Dictionary // klasa dziedziczy po klasie Dictionary 
{
private:
	BinarySearchTree* arr; // wskaznik na tablice wskaznikow do drzew binarnych 
	int arrSize; // rozmiar tablicy 

public:
	HashTableSeparateChasingWithBST(int arrSize);
	HashTableSeparateChasingWithBST(const HashTableSeparateChasingWithBST& hashMap);
	~HashTableSeparateChasingWithBST();
	HashTableSeparateChasingWithBST& operator=(const HashTableSeparateChasingWithBST& hashMap);

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

