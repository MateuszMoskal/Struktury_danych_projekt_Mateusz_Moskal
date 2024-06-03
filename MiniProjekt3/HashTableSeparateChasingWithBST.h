#pragma once
#include "Dictionary.h"
#include "BinarySearchTree.h"
class HashTableSeparateChasingWithBST : public Dictionary
{
private:
	BinarySearchTree* arr;
	int arrSize;

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
	int hash(int key)
	{
		return key % arrSize;
	}
};

