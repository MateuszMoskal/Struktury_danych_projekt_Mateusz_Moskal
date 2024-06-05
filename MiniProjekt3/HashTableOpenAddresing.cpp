#include "HashTableOpenAddresing.h"


// konstruktor 
HashTableOpenAddresing::HashTableOpenAddresing(int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new Item * [arrSize]; // tablica wskaznikow 

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = nullptr;
	}
}

// konstruktor kopiujacy 
HashTableOpenAddresing::HashTableOpenAddresing(const HashTableOpenAddresing& hashMap)
{
	this->arrSize = hashMap.arrSize;
	this->arr = new Item * [arrSize];

	// kopiowanie elementow z istniejacej listy 
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = new Item;
		if (hashMap.arr == nullptr)
		{
			arr[i] = nullptr;
		}
		else
		{
			*arr[i] = *hashMap.arr[i]; // kopiowanie wartosci elementu 
		}
	}
}

// destruktor 
HashTableOpenAddresing::~HashTableOpenAddresing()
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] != nullptr)
		{
			delete arr[i];
		}
	}
	delete[] arr; // usuniecie tablicy (bez elementow)
}
HashTableOpenAddresing& HashTableOpenAddresing::operator=(const HashTableOpenAddresing& hashMap)
{
	HashTableOpenAddresing::~HashTableOpenAddresing();
	this->arrSize = hashMap.arrSize;
	this->arr = new Item * [arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = new Item;
		if (hashMap.arr == nullptr)
		{
			arr[i] = nullptr;
		}
		else
		{
			*arr[i] = *hashMap.arr[i];
		}
	}
	return *this;
}

// Funkcja wstawiajaca nowy element 
bool HashTableOpenAddresing::insert(int key, int value)
{

	int indexStart = hash(key); // okreslenie indeksu startowego 
	int index;
	for (int i = 0; i < arrSize; i++)
	{
		index = (i + indexStart) % arrSize;
		if (arr[index] == nullptr)
		{
			arr[index] = new Item;
			arr[index]->key = key; // ustawienie klucza 
			arr[index]->value = value; // ustawienie wartosci 
			return true;
		}
	}

	return false;
}
// Usuniecie elementu o danym kluczu 
void HashTableOpenAddresing::remove(int key)
{
	int index = findIndex(key); // znalezienie pozadanego indeksu 
	if (index != -1)
	{
		delete arr[index];
		arr[index] = nullptr;
	}
}

// Funkcja sprawdzajaca wystapienie elementu o danym kluczu
bool HashTableOpenAddresing::contains(int key)
{
	return findIndex(key) != -1;
}

// Funkcja zwarcajaca wartosc elementu 
int HashTableOpenAddresing::get(int key)
{
	return arr[findIndex(key)]->value;
}

// Czyszczenie tablicy 
void HashTableOpenAddresing::clean()
{
	cleanAndResize(arrSize);
}

// Czyszczenie i ustawienie nowego rozmiaru 
void HashTableOpenAddresing::cleanAndResize(int size)
{
	HashTableOpenAddresing::~HashTableOpenAddresing();
	this->arrSize = size;
	this->arr = new Item * [arrSize];
}

// Funkcja znajdujaca podany indeks elementu 
int HashTableOpenAddresing::findIndex(int key)
{
	int indexStart = hash(key);
	//if (arr[indexStart] != nullptr && arr[indexStart]->key==key)
//	{
//		return indexStart;
//	}
	int index;
	for (int i = 0; i < arrSize; i++)
	{
		index = (i + indexStart) % arrSize;
		if (arr[i] == nullptr)
		{
			return -1;
		}
		if (arr[i]->key == key)
		{
			return i;
		}
	}

	return -1;
}