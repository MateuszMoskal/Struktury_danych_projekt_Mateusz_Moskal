#include "HeadSinglyLinkedList.h"

#include <iostream>

using namespace std;

// konstruktor 
HeadSinglyLinkedList::HeadSinglyLinkedList()
{
	head = nullptr;
	size = 0;
}

// konstruktor kopiujacy 
HeadSinglyLinkedList::HeadSinglyLinkedList(const HeadSinglyLinkedList& list) : HeadSinglyLinkedList()
{
	copy(list); // wywolanie funkcji kopiujacej 
}

// destruktor 
HeadSinglyLinkedList::~HeadSinglyLinkedList()
{
	while (head != nullptr)
	{
		Element* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia; // usuniecie elementu z pamieci listy 
	}
}
// operator przypisania 
HeadSinglyLinkedList& HeadSinglyLinkedList::operator=(const HeadSinglyLinkedList& list)
{
	this->~HeadSinglyLinkedList(); // wywolanie destruktora 
	copy(list);
	return *this; // zwrocenie referencji do obiektu 
}

void HeadSinglyLinkedList::insert(int value, int priorytary)
{
	Element* listItem = new Element;
	listItem->value = value; // przypisanie wartosci
	listItem->priorytary = priorytary; // przypisanie priorytetu 
	listItem->nast = nullptr;

	if (head == nullptr) // jesli lista jest pusta 
	{
		head = listItem; // nowy element staje sie head
		size++; // zwiekszenie rozmiaru 
		return;
	}
	if (priorytary > head->priorytary) // jesli nowy element ma wiekszy priorytet niz head 
	{
		listItem->nast = head; // nowy element staje sie head
		head = listItem;
		size++; // zwiekszenie rozmiaru 
		return;
	}

	insert(head, listItem); // wstawiam element w odpowiednie miejsce 
	size++;
}

void HeadSinglyLinkedList::insert(Element* itemBeforeStart, Element* itemInserted)
{

	while (itemBeforeStart->nast != nullptr && itemBeforeStart->nast->priorytary >= itemInserted->priorytary)
	{
		itemBeforeStart = itemBeforeStart->nast;
	}
	if (itemBeforeStart->nast != nullptr)
	{
		Element* efter = itemBeforeStart->nast;
		itemBeforeStart->nast = itemInserted;
		itemInserted->nast = efter;
	}
	else
	{
		itemBeforeStart->nast = itemInserted;
	}
}

// modyfikacja priorytetu elementu 
void HeadSinglyLinkedList::modyfyKey(int value, int priorytary)
{
	if (head == nullptr)
	{
		return;
	}
	if (head->value == value)
	{
		if (head->priorytary == priorytary)
		{
			return;
		}
		if (priorytary > head->priorytary)
		{
			head->priorytary = priorytary;
			return;
		}

		//priorytary < head->priorytary
		if (head->nast == nullptr)
		{
			head->priorytary = priorytary;
			return;
		}
		if (head->nast->priorytary <= priorytary)
		{
			head->priorytary = priorytary;
			return;
		}

		Element* modyfied = head;
		head = head->nast;
		modyfied->nast = nullptr;
		modyfied->priorytary = priorytary;

		insert(head, modyfied);
	}
	else
	{
		Element* before = findItemBefore(value);
		if (before == nullptr)
		{
			return;
		}
		Element* modyfied = before->nast;
		before->nast = modyfied->nast;
		modyfied->nast = nullptr;
		if (modyfied->priorytary <= priorytary)
		{
			modyfied->priorytary = priorytary;
			if (head->priorytary < modyfied->priorytary)
			{
				modyfied->nast = head;
				head = modyfied;
			}
			else
			{
				insert(head, modyfied);
			}
		}
		else
		{
			modyfied->priorytary = priorytary;
			insert(before, modyfied);
		}
	}
}

// usuniecie wszystkich elementow listy
void HeadSinglyLinkedList::clean()
{
	this->~HeadSinglyLinkedList();
	head = nullptr;
	size = 0;
}

//  usuniecie i zwrocenie elementu z najwiekszym priorytetem 
int HeadSinglyLinkedList::extractMax()
{
	Element* toDelete = head;
	head = head->nast;
	size--;
	int value = toDelete->value;
	delete toDelete;
	return value;
}


int HeadSinglyLinkedList::peek()
{
	return head->value; // zwrocenie wartosci elementu o najwiekszym priorytecie 
}

// rozmiar listy 
int HeadSinglyLinkedList::getSize()
{
	return size;
}

// wyswietlenie listy
void HeadSinglyLinkedList::print()
{
	Element* pom = head;
	while (pom != nullptr)
	{
		cout << "(klucz:" << pom->priorytary << ", wartosc:" << pom->value << ") ";
		if (pom->nast != nullptr)
		{
			cout << ", ";
		}
		pom = pom->nast;
	}
	cout << endl;
}

// kopiowanie listy 
void HeadSinglyLinkedList::copy(const HeadSinglyLinkedList& list)
{
	Element* kursor = list.head;
	Element* kursorKoncowy = nullptr;
	if (kursor != nullptr)
	{
		head = new Element;
		head->value = kursor->value;
		head->nast = nullptr;
		kursor = kursor->nast;
		kursorKoncowy = head;
	}

	while (kursor != nullptr)
	{
		Element* nowy = new Element;
		nowy->value = kursor->value;
		nowy->nast = nullptr;
		kursorKoncowy->nast = nowy;
		kursorKoncowy = kursorKoncowy->nast;
		kursor = kursor->nast;
	}
	size = list.size;
}

// znajdowanie elementu przed elementem o danej wartosci 
Element* HeadSinglyLinkedList::findItemBefore(int value) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	if (head->value == value)
	{
		return nullptr;
	}

	Element* pom = head;

	while (pom->nast != nullptr && pom->nast->value != value)
	{
		pom = pom->nast;
	}
	if (pom->nast != nullptr)
	{
		return pom;
	}
	return nullptr;
}