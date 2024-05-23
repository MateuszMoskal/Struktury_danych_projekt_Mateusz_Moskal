#pragma once
#include "Dictionary.h"
#include "HeadSinglyLinkedList.h"
class HashTableSeparateChasingWithList : public Dictionary
{
private:
	HeadSinglyLinkedList* arr;
	int arrSize;

public:
	HashTableSeparateChasingWithList(int arrSize);
	HashTableSeparateChasingWithList(const HashTableSeparateChasingWithList& hashMap);
	~HashTableSeparateChasingWithList();
	HashTableSeparateChasingWithList& operator=(const HashTableSeparateChasingWithList& hashMap);

	virtual void insert(int key, int value) override;
	virtual void remove(int key) override;
	virtual bool contains(int key) override;
	virtual int get(int key) override;

	int hash(int key)
	{
		return key % arrSize;
	}
};