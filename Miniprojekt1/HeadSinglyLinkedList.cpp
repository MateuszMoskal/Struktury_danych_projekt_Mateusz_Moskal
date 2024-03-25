#include "HeadSinglyLinkedList.h"
#include <iostream>

using namespace std;

HeadSinglyLinkedList::HeadSinglyLinkedList()
{
	head = nullptr;
	ilosc = 0;
}
HeadSinglyLinkedList::HeadSinglyLinkedList(const HeadSinglyLinkedList& list) : HeadSinglyLinkedList()
{
	skopiuj(list);
}
HeadSinglyLinkedList::~HeadSinglyLinkedList()
{
	skasuj();
}
HeadSinglyLinkedList& HeadSinglyLinkedList::operator=(const HeadSinglyLinkedList& list)
{
	skasuj();
	skopiuj(list);
	return *this;
}

void HeadSinglyLinkedList::wyczysc()
{
	this->~HeadSinglyLinkedList();
	head = nullptr;
	ilosc = 0;
}

void HeadSinglyLinkedList::dodajNaPoczatek(int dane)
{
	Element* element = new Element;
	element->dane = dane;
	element->nast = head;
	head = element;
	ilosc++;
}

void HeadSinglyLinkedList::dodajNaKoniec(int dane)
{
	Element* element = new Element;
	element->dane = dane;
	element->nast = nullptr;

	if (head == nullptr)
	{
		head = element;
	}
	else
	{
		Element* pom = head;
		while (pom->nast != nullptr)
		{
			pom = pom->nast;
		}
		pom->nast = element;
	}
	ilosc++;
}

bool HeadSinglyLinkedList::dodaj(int index, int dane)
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
	ilosc++;
	return true;
}

bool HeadSinglyLinkedList::usun(int index)
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
		return usunZPoczateku();
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
	delete doUsuniecia;
	ilosc--;
	return true;

}

bool HeadSinglyLinkedList::usunZPoczateku()
{
	if (head == nullptr)
	{
		return false;
	}

	Element* doUsuniecia = head;
	head = head->nast;
	delete doUsuniecia;
	ilosc--;
	return true;
}
bool HeadSinglyLinkedList::usunZKonca()
{
	return usun(ilosc - 1);
}

int HeadSinglyLinkedList::dajIlosc() const
{
	return ilosc;
}

int HeadSinglyLinkedList::dajEmenet(int index) const
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

void HeadSinglyLinkedList::wypisz() const
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



Element* HeadSinglyLinkedList::znajdzElementPrzed(int index) const
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

void HeadSinglyLinkedList::skopiuj(const HeadSinglyLinkedList& list)
{
	Element* kursor = list.head;
	Element* kursorKoncowy = nullptr;
	if (kursor != nullptr)
	{
		head = new Element;
		head->dane = kursor->dane;
		head->nast = nullptr;
		kursor = kursor->nast;
		kursorKoncowy = head;
	}

	while (kursor != nullptr)
	{
		Element* nowy = new Element;
		nowy->dane = kursor->dane;
		nowy->nast = nullptr;
		kursorKoncowy->nast = nowy;
		kursorKoncowy = kursorKoncowy->nast;
		kursor = kursor->nast;
	}
	ilosc = list.ilosc;
}

void HeadSinglyLinkedList::skasuj()
{
	while (head != nullptr)
	{
		Element* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia;
	}
}

