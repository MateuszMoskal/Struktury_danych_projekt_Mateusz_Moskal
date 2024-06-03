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

bool HashTableOpenAddresing::insert(int key, int value)
{

	int indexStart = hash(key);
	int index;
	for (int i = 0; i < arrSize; i++)
	{
		index = (i + indexStart) % arrSize;
		if (arr[index] == nullptr)
		{
			arr[index] = new Item;
			arr[index]->key = key;
			arr[index]->value = value;
			return true;
		}
	}

	return false;
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

void HashTableOpenAddresing::clean()
{
	cleanAndResize(arrSize);
}
void HashTableOpenAddresing::cleanAndResize(int size)
{
	HashTableOpenAddresing::~HashTableOpenAddresing();
	this->arrSize = size;
	this->arr = new Item * [arrSize];
}

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