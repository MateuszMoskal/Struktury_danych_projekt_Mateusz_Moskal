#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	ilosc = 0;
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list) : DoublyLinkedList()
{
	skopiuj(list);
}
DoublyLinkedList::~DoublyLinkedList()
{
	skasuj();
}
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& list)
{
	skasuj();
	skopiuj(list);
	return *this;
}

void DoublyLinkedList::wyczysc()
{
	this->~DoublyLinkedList();
	head = nullptr;
	tail = nullptr;
	ilosc = 0;
}

//ok
void DoublyLinkedList::dodajNaPoczatek(int dane)
{
	Element2* element = new Element2;
	element->dane = dane;
	element->pop = nullptr;
	element->nast = head;
	if (head == nullptr)
	{
		head = element;
		tail = element;
	}
	else
	{
		head->pop = element;
		head = element;
	}

	ilosc++;
}

//ok
void DoublyLinkedList::dodajNaKoniec(int dane)
{
	Element2* element = new Element2;
	element->dane = dane;
	element->nast = nullptr;
	element->pop = nullptr;

	if (tail == nullptr)
	{
		head = element;
		tail = element;
	}
	else
	{
		tail->nast = element;
		element->pop = tail;
		tail = element;
	}
	ilosc++;
}

//ok
bool DoublyLinkedList::dodaj(int index, int dane)
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
	if (index == ilosc)
	{
		dodajNaKoniec(dane);
		return true;
	}
	if (head == nullptr)
	{
		return false;
	}
	Element2* przed = znajdzElementPrzed(index);
	if (przed == nullptr)
	{
		return false;
	}
	Element2* za = przed->nast;

	Element2* nowy = new Element2;
	nowy->dane = dane;
	nowy->nast = za;
	przed->nast = nowy;
	nowy->pop = przed;
	if (przed == tail)
	{
		tail = nowy;
		nowy->nast = nullptr;
	}
	else
	{
		nowy->nast = za;
	}
	ilosc++;

	return true;
}
//ok
bool DoublyLinkedList::usun(int index)
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
	if (index == ilosc - 1)
	{
		return usunZKonca();
	}
	Element2* przed = znajdzElementPrzed(index);
	if (przed == nullptr)
	{
		return false;
	}

	Element2* doUsuniecia = przed->nast;
	if (doUsuniecia == nullptr)
	{
		return false;
	}
	Element2* za = doUsuniecia->nast;
	przed->nast = za;
	if (doUsuniecia == tail)
	{
		tail = przed;
	}
	else
	{
		za->pop = przed;
	}

	delete doUsuniecia;

	ilosc--;
	return true;

}

bool DoublyLinkedList::usunZPoczateku()
{
	if (head == nullptr)
	{
		return false;
	}
	Element2* doUsuniecia = head;
	head = head->nast;
	if (head != nullptr)
	{
		head->pop = nullptr;
	}
	else
	{
		tail = nullptr;
	}

	delete doUsuniecia;
	ilosc--;
	return true;
}
bool DoublyLinkedList::usunZKonca()
{
	if (tail == nullptr)
	{
		return false;
	}
	Element2* doUsuniecia = tail;
	tail = tail->pop;

	if (tail != nullptr)
	{
		tail->nast = nullptr;
	}
	else
	{
		head = nullptr;
	}

	delete doUsuniecia;
	ilosc--;
	return true;
}

//ok
int DoublyLinkedList::dajIlosc() const
{
	return ilosc;
}
//ok
int DoublyLinkedList::dajEmenet(int index) const
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

	Element2* przed = znajdzElementPrzed(index);

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


//ok
void DoublyLinkedList::wypisz() const
{
	cout << "[";
	Element2* kursos = head;
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

Element2* DoublyLinkedList::znajdzElementPrzed(int index) const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	if (index == 0)
	{
		return nullptr;
	}
	if (index == ilosc)
	{
		return tail;
	}
	if (index <= ilosc / 2)
	{
		return znajdzElementPrzedOdProdzu(index);
	}
	else
	{
		return znajdzElementPrzedOdTylu(index);
	}
}

Element2* DoublyLinkedList::znajdzElementPrzedOdProdzu(int index) const
{
	Element2* pom = head;

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
Element2* DoublyLinkedList::znajdzElementPrzedOdTylu(int index) const
{
	//int ostatniIndex = ilosc - 1;
	//int ileDoTylu = ostatniIndex - index + 1;
	int ileDoTylu = ilosc - index;

	Element2* kursor = tail;
	for (int i = 0; i < ileDoTylu && kursor != nullptr; i++)
	{
		kursor = kursor->pop;
	}

	return kursor;
}

void DoublyLinkedList::skopiuj(const DoublyLinkedList& list)
{
	Element2* kursor = list.head;

	while (kursor != nullptr)
	{
		dodajNaKoniec(kursor->dane);
		kursor = kursor->nast;
	}
}

void DoublyLinkedList::skasuj()
{
	while (head != nullptr)
	{
		Element2* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia;
	}
	tail = nullptr;
}

