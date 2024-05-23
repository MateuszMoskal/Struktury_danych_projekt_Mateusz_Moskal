#pragma once
#include "Dictionary.h"

struct Item
{
	int key;
	int value;
};


class HashTableOpenAddresing : public Dictionary
{
	Item** arr;
	int arrSize;

	HashTableOpenAddresing(int arrSize);
	HashTableOpenAddresing(const HashTableOpenAddresing& hashMap);
	~HashTableOpenAddresing();
	HashTableOpenAddresing& operator=(const HashTableOpenAddresing& hashMap);

	virtual void insert(int key, int value) override;
	virtual void remove(int key) override;
	virtual bool contains(int key) override;
	virtual int get(int key) override;

	int hash(int key)
	{
		return key % arrSize;
	}
	int findIndex(int key);

};