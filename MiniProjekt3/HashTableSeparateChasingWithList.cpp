#include "HashTableSeparateChasingWithList.h"


// konstruktor 
HashTableSeparateChasingWithList::HashTableSeparateChasingWithList(int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new HeadSinglyLinkedList[arrSize]; // tworzenie tablicy list jednokierunkowych  
}
HashTableSeparateChasingWithList::HashTableSeparateChasingWithList(const HashTableSeparateChasingWithList& hashMap)
{
	this->arrSize = hashMap.arrSize;
	this->arr = new HeadSinglyLinkedList[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = hashMap.arr[i]; //uruchomi sie operator przypisania
	}

}
HashTableSeparateChasingWithList::~HashTableSeparateChasingWithList()
{
	delete[] arr; // usuniecie tablicy list 
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

// Funkcja wstawiaj¹ca nowy element do tablicy
bool HashTableSeparateChasingWithList::insert(int key, int value)
{
	arr[hash(key)].addOrUpdate(key, value);
	return true;
}

// Funkcja usuwaj¹ca element o danym kluczu
void HashTableSeparateChasingWithList::remove(int key)
{
	arr[hash(key)].remove(key);
}
bool HashTableSeparateChasingWithList::contains(int key)
{
	return arr[hash(key)].findItem(key) != nullptr;
}

// Funkcja zwracaj¹ca wartoœæ elementu o danym kluczu
int HashTableSeparateChasingWithList::get(int key)
{
	return arr[hash(key)].findItem(key)->value;
}

// Funkcja czyszczaca
void HashTableSeparateChasingWithList::clean()
{
	cleanAndResize(arrSize);
}

// Funkcja czyszczaca i zmieniajaca rozmiar 
void HashTableSeparateChasingWithList::cleanAndResize(int size)
{
	HashTableSeparateChasingWithList::~HashTableSeparateChasingWithList();
	this->arrSize = size;
	this->arr = new HeadSinglyLinkedList[arrSize];
}