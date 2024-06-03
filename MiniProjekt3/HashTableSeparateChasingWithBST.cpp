#include "HashTableSeparateChasingWithBST.h"

HashTableSeparateChasingWithBST::HashTableSeparateChasingWithBST(int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new BinarySearchTree[arrSize];
}
HashTableSeparateChasingWithBST::HashTableSeparateChasingWithBST(const HashTableSeparateChasingWithBST& hashMap)
{
	this->arrSize = hashMap.arrSize;
	this->arr = new BinarySearchTree[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = hashMap.arr[i];//uruchomi sie operator przypisania
	}
}
HashTableSeparateChasingWithBST::~HashTableSeparateChasingWithBST()
{
	delete[] arr;
}
HashTableSeparateChasingWithBST& HashTableSeparateChasingWithBST::operator=(const HashTableSeparateChasingWithBST& hashMap)
{
	delete[] arr;
	this->arrSize = hashMap.arrSize;
	this->arr = new BinarySearchTree[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = hashMap.arr[i];//uruchomi sie operator przypisania
	}
	return *this;
}

bool HashTableSeparateChasingWithBST::insert(int key, int value)
{
	arr[hash(key)].AddOrUpdate(key, value);
	return true;
}
void HashTableSeparateChasingWithBST::remove(int key)
{
	arr[hash(key)].remove(key);

}
bool HashTableSeparateChasingWithBST::contains(int key)
{
	return arr[hash(key)].findItem(key) != nullptr;
}
int HashTableSeparateChasingWithBST::get(int key)
{
	return arr[hash(key)].findItem(key)->value;
}

void HashTableSeparateChasingWithBST::clean()
{
	cleanAndResize(arrSize);
}
void HashTableSeparateChasingWithBST::cleanAndResize(int size)
{
	HashTableSeparateChasingWithBST::~HashTableSeparateChasingWithBST();
	this->arrSize = size;
	this->arr = new BinarySearchTree[arrSize];
}
