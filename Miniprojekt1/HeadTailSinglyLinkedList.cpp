#include "HeadTailSinglyLinkedList.h"
#include <iostream>

using namespace std;

HeadTailSinglyLinkedList::HeadTailSinglyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	ilosc = 0;
}
HeadTailSinglyLinkedList::HeadTailSinglyLinkedList(const HeadTailSinglyLinkedList& list) : HeadTailSinglyLinkedList()
{
	skopiuj(list);
}
HeadTailSinglyLinkedList::~HeadTailSinglyLinkedList()
{
	skasuj();
}
HeadTailSinglyLinkedList& HeadTailSinglyLinkedList::operator=(const HeadTailSinglyLinkedList& list)
{
	skasuj();
	skopiuj(list);
	return *this;
}

void HeadTailSinglyLinkedList::wyczysc()
{
	this->~HeadTailSinglyLinkedList();
	head = nullptr;
	tail = nullptr;
	ilosc = 0;
}

void HeadTailSinglyLinkedList::dodajNaPoczatek(int dane)
{
	Element* element = new Element;
	element->dane = dane;
	element->nast = head;
	head = element;

	if (tail == nullptr)
	{
		tail = head;
	}

	ilosc++;
}

void HeadTailSinglyLinkedList::dodajNaKoniec(int dane)
{
	Element* element = new Element;
	element->dane = dane;
	element->nast = nullptr;

	if (tail == nullptr)
	{
		head = element;
		tail = element;
	}
	else
	{
		tail->nast = element;
		tail = element;
	}
	ilosc++;
}

bool HeadTailSinglyLinkedList::dodaj(int index, int dane)
{
	if (index < 0)
	{
		return false;
	}
	if (index == 0)
	{
		dodajNaPoczatek(dane);
		return true;
	}
	if (head == nullptr)
	{
		return false;
	}
	Element* przed = znajdzElementPrzed(index);
	if (przed == nullptr)
	{
		return false;
	}
	Element* nowy = new Element;
	nowy->dane = dane;
	nowy->nast = przed->nast;
	przed->nast = nowy;
	if (przed == tail)
	{
		tail = nowy;
	}
	ilosc++;

	return true;
}

bool HeadTailSinglyLinkedList::usun(int index)
{
	if (index < 0)
	{
		return false;
	}

	if (head == nullptr)
	{
		return false;
	}

	if (index == 0)
	{
		Element* doUsuniecia = head;
		head = head->nast;
		if (doUsuniecia == tail)
		{
			tail = nullptr;
		}
		delete doUsuniecia;
		ilosc--;
		return true;
	}

	Element* przed = znajdzElementPrzed(index);
	if (przed == nullptr)
	{
		return false;
	}

	Element* doUsuniecia = przed->nast;
	if (doUsuniecia == nullptr)
	{
		return false;
	}
	przed->nast = doUsuniecia->nast;
	if (doUsuniecia == tail)
	{
		tail = przed;
	}
	delete doUsuniecia;

	ilosc--;
	return true;

}

bool HeadTailSinglyLinkedList::usunZPoczateku()
{
	if (head == nullptr)
	{
		return false;
	}

	Element* doUsuniecia = head;
	head = head->nast;
	if (head == nullptr)
	{
		tail = nullptr;
	}

	delete doUsuniecia;
	ilosc--;
	return true;
}
bool HeadTailSinglyLinkedList::usunZKonca()
{
	return usun(ilosc - 1);
}

int HeadTailSinglyLinkedList::dajIlosc() const
{
	return ilosc;
}

int HeadTailSinglyLinkedList::dajEmenet(int index) const
{
	if (index < 0)
	{
		return false;
	}

	if (head == nullptr)
	{
		return false;
	}

	if (index == 0)
	{
		return head->dane;
	}
	if (index == ilosc - 1)
	{
		return tail->dane;
	}

	Element* przed = znajdzElementPrzed(index);

	if (przed != nullptr)
	{
		return 0;
	}
	if (przed->nast != nullptr)
	{
		return 0;
	}
	return przed->nast->dane;
}


void HeadTailSinglyLinkedList::wypisz() const
{
	cout << "[";
	Element* kursos = head;
	if (kursos != nullptr)
	{
		cout << kursos->dane;
		kursos = kursos->nast;
	}

	while (kursos != nullptr)
	{
		cout << ", " << kursos->dane;
		kursos = kursos->nast;
	}

	cout << "]" << endl;
}

Element* HeadTailSinglyLinkedList::znajdzElementPrzed(int index) const
{
	if (index == 0)
	{
		return nullptr;
	}
	if (head == nullptr)
	{
		return nullptr;
	}

	Element* pom = head;

	for (int i = 1; i < index; i++)
	{
		if (pom->nast == nullptr)
		{
			return nullptr;
		}
		pom = pom->nast;
	}
	return pom;
}

void HeadTailSinglyLinkedList::skopiuj(const HeadTailSinglyLinkedList& list)
{
	Element* kursor = list.head;

	while (kursor != nullptr)
	{
		dodajNaKoniec(kursor->dane);
		kursor = kursor->nast;
	}
}

void HeadTailSinglyLinkedList::skasuj()
{
	while (head != nullptr)
	{
		Element* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia;
	}
	tail = nullptr;
}

