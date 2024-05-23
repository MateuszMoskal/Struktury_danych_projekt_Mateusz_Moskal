#include "HashTableSeparateChasingWithList.h"

HashTableSeparateChasingWithList::HashTableSeparateChasingWithList(int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new HeadSinglyLinkedList[arrSize];
}
HashTableSeparateChasingWithList::HashTableSeparateChasingWithList(const HashTableSeparateChasingWithList& hashMap)
{
	this->arrSize = hashMap.arrSize;
	this->arr = new HeadSinglyLinkedList[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = hashMap.arr[i];//uruchomi sie operator przypisania
	}

}
HashTableSeparateChasingWithList::~HashTableSeparateChasingWithList()
{
	delete[] arr; //tu uruchomia sie destruktory list
}
HashTableSeparateChasingWithList& HashTableSeparateChasingWithList::operator=(const HashTableSeparateChasingWithList& hashMap)
{
	delete[] arr;
	this->arrSize = hashMap.arrSize;
	this->arr = new HeadSinglyLinkedList[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = hashMap.arr[i];//uruchomi sie operator przypisania
	}
	return *this;
}

void HashTableSeparateChasingWithList::insert(int key, int value)
{
	arr[hash(key)].addOrUpdate(key, value);
}
void HashTableSeparateChasingWithList::remove(int key)
{
	arr[hash(key)].remove(key);
}
bool HashTableSeparateChasingWithList::contains(int key)
{
	return arr[hash(key)].findItem(key) != nullptr;
}
int HashTableSeparateChasingWithList::get(int key)
{
	return arr[hash(key)].findItem(key)->value;
}