#include "HeadSinglyLinkedList.h"
#include <iostream>

using namespace std;

HeadSinglyLinkedList::HeadSinglyLinkedList()
{
	head = nullptr;
	count = 0;
}
HeadSinglyLinkedList::HeadSinglyLinkedList(const HeadSinglyLinkedList& list) : HeadSinglyLinkedList()
{
	copy(list);
}
HeadSinglyLinkedList::~HeadSinglyLinkedList()
{
	while (head != nullptr)
	{
		ItemList* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia;
	}
}
HeadSinglyLinkedList& HeadSinglyLinkedList::operator=(const HeadSinglyLinkedList& list)
{
	this->~HeadSinglyLinkedList();
	copy(list);
	return *this;
}

void HeadSinglyLinkedList::wyczysc()
{
	this->~HeadSinglyLinkedList();
	head = nullptr;
	count = 0;
}

void HeadSinglyLinkedList::addOrUpdate(int key, int value)
{
	ItemList* item = findItem(key);
	if (item != nullptr)
	{
		item->value = value;
	}
	else
	{
		ItemList* element = new ItemList;
		element->key = key;
		element->value = value;
		element->nast = head;
		head = element;
		count++;
	}
}

bool HeadSinglyLinkedList::remove(int key)
{
	if (head == nullptr)
	{
		return false;
	}
	if (head->key == key)
	{
		return removeFromBegin();
	}

	ItemList* before = findItemBefore(key);
	if (before == nullptr)
	{
		return false;
	}

	ItemList* toRemove = before->nast;
	if (toRemove == nullptr)
	{
		return false;
	}
	before->nast = toRemove->nast;
	delete toRemove;
	count--;
	return true;

}

bool HeadSinglyLinkedList::removeFromBegin()
{
	if (head == nullptr)
	{
		return false;
	}

	ItemList* doUsuniecia = head;
	head = head->nast;
	delete doUsuniecia;
	count--;
	return true;
}


int HeadSinglyLinkedList::dajIlosc() const
{
	return count;
}

void HeadSinglyLinkedList::wypisz() const
{
	cout << "[";
	ItemList* kursos = head;
	if (kursos != nullptr)
	{
		cout << kursos->key;
		kursos = kursos->nast;
	}

	while (kursos != nullptr)
	{
		cout << ", " << kursos->key;
		kursos = kursos->nast;
	}

	cout << "]" << endl;
}

ItemList* HeadSinglyLinkedList::findItem(int key) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	if (head->key == key)
	{
		return head;
	}
	ItemList* before = findItemBefore(key);
	if (before == nullptr)
	{
		return nullptr;
	}
	return before->nast;
}

ItemList* HeadSinglyLinkedList::findItemBefore(int key) const
{
	if (head == nullptr)
	{
		return nullptr;
	}

	ItemList* pom = head;

	while (pom->nast != nullptr)
	{
		if (pom->nast->key == key)
		{
			return pom;
		}
		pom = pom->nast;
	}
	return nullptr;
}


void HeadSinglyLinkedList::copy(const HeadSinglyLinkedList& list)
{
	ItemList* kursor = list.head;
	ItemList* kursorKoncowy = nullptr;
	if (kursor != nullptr)
	{
		head = new ItemList;
		head->key = kursor->key;
		head->nast = nullptr;
		kursor = kursor->nast;
		kursorKoncowy = head;
	}

	while (kursor != nullptr)
	{
		ItemList* nowy = new ItemList;
		nowy->key = kursor->key;
		nowy->nast = nullptr;
		kursorKoncowy->nast = nowy;
		kursorKoncowy = kursorKoncowy->nast;
		kursor = kursor->nast;
	}
	count = list.count;
}