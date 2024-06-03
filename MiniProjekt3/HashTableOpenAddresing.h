#pragma once
#include "Dictionary.h"

#include "Dictionary.h"

struct Item
{
	int key;
	int value;
};


class HashTableOpenAddresing : public Dictionary
{
private:
	Item** arr;
	int arrSize;
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

	int hash(int key)
	{
		return key % arrSize;
	}
	int findIndex(int key);

};

