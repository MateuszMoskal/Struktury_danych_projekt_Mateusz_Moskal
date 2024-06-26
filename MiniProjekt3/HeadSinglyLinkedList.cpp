#include "HeadSinglyLinkedList.h"
#include <iostream>

using namespace std;

// konstruktor 
HeadSinglyLinkedList::HeadSinglyLinkedList()
{
	head = nullptr;
	count = 0;
}
// konstruktor kopiujacy 
HeadSinglyLinkedList::HeadSinglyLinkedList(const HeadSinglyLinkedList& list) : HeadSinglyLinkedList()
{
	copy(list);
}
// destruktor 
HeadSinglyLinkedList::~HeadSinglyLinkedList()
{
	while (head != nullptr)
	{
		ItemList* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia;
	}
}
// operator przypisania 
HeadSinglyLinkedList& HeadSinglyLinkedList::operator=(const HeadSinglyLinkedList& list)
{
	this->~HeadSinglyLinkedList();
	copy(list); // skopiowanie danych z listy 
	return *this;
}

// funkcja czyszczaca liste
void HeadSinglyLinkedList::wyczysc()
{
	this->~HeadSinglyLinkedList();
	head = nullptr;
	count = 0; // zresetowanie licznika 
}

// Funkcja dodająca lub aktualizująca element
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

// Funkcja usuwająca element o podanym kluczu
bool HeadSinglyLinkedList::remove(int key)
{
	if (head == nullptr)
	{
		return false;
	}
	if (head->key == key)
	{
		return removeFromBegin(); // usuniecie elementu z poczatku listy 
	}

	ItemList* before = findItemBefore(key); // Znalezienie elementu poprzedzającego
	if (before == nullptr)
	{
		return false;
	}

	ItemList* toRemove = before->nast; // zmalezienie elementu do usuniecia 
	if (toRemove == nullptr)
	{
		return false;
	}
	before->nast = toRemove->nast;
	delete toRemove; // usuniecie elementu 
	count--; // zmniejszenie licznika 
	return true;

}

// Funkcja usuwająca element z początku listy
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

// Funkcja zwracająca liczbę elementów w liście
int HeadSinglyLinkedList::dajIlosc() const
{
	return count;
}

// Funkcja wypisująca elementy listy
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

// Funkcja wyszukująca element o podanym kluczu
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
	ItemList* before = findItemBefore(key); // Znalezienie elementu poprzedzającego
	if (before == nullptr)
	{
		return nullptr;
	}
	return before->nast; // Zwracanie elementu następującego po poprzedzającym
}

// Funkcja wyszukująca element poprzedzający element o podanym kluczu
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

// Funkcja kopiująca elementy
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