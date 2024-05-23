#include "HashTableOpenAddresing.h"

HashTableOpenAddresing::HashTableOpenAddresing(int arrSize)
{
	this->arrSize = arrSize;
	this->arr = new Item * [arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = nullptr;
	}
}
HashTableOpenAddresing::HashTableOpenAddresing(const HashTableOpenAddresing& hashMap)
{
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
}
HashTableOpenAddresing::~HashTableOpenAddresing()
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] != nullptr)
		{
			delete arr[i];
		}
	}
	delete[] arr;
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

void HashTableOpenAddresing::insert(int key, int value)
{

	int indexStart = hash(key);
	if (arr[indexStart] == nullptr)
	{
		arr[indexStart] = new Item;
		arr[indexStart]->key = key;
		arr[indexStart]->value = value;
		return;
	}
	for (int i = indexStart + 1; i % arrSize != indexStart; i++)
	{
		if (arr[i] != nullptr)
		{
			arr[i]->key = key;
			arr[i]->value = value;
			return;
		}
	}
}
void HashTableOpenAddresing::remove(int key)
{
	int index = findIndex(key);
	if (index != -1)
	{
		delete arr[index];
		arr[index] = nullptr;
	}
}
bool HashTableOpenAddresing::contains(int key)
{
	return findIndex(key) != -1;
}
int HashTableOpenAddresing::get(int key)
{
	return arr[findIndex(key)]->value;
}

int HashTableOpenAddresing::findIndex(int key)
{
	int indexStart = hash(key);
	if (arr[indexStart] != nullptr && arr[indexStart]->key == key)
	{
		return indexStart;
	}
	for (int i = indexStart + 1; i % arrSize != indexStart; i++)
	{
		if (arr[i] != nullptr && arr[i]->key == key)
		{
			return i;
		}
	}
	return -1;
}