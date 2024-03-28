#include "HeadSinglyLinkedList.h"
#include <iostream>

using namespace std;

// konstruktor
HeadSinglyLinkedList::HeadSinglyLinkedList()
{
	head = nullptr; // wskaźnik jako nullptr
	ilosc = 0;
}
// konstruktor kopiujący 
HeadSinglyLinkedList::HeadSinglyLinkedList(const HeadSinglyLinkedList& list) : HeadSinglyLinkedList()
{
	skopiuj(list); // skopiowanie zawartości listy 
}

// destruktor 
HeadSinglyLinkedList::~HeadSinglyLinkedList()
{
	skasuj(); // zwolnienie pamięci 
}
HeadSinglyLinkedList& HeadSinglyLinkedList::operator=(const HeadSinglyLinkedList& list)
{
	skasuj();
	skopiuj(list); 
	return *this; // zwrócenie referencji do aktualnej listy 
}

void HeadSinglyLinkedList::wyczysc()
{
	this->~HeadSinglyLinkedList(); // wywołanie destruktora 
	head = nullptr; // ustawienie wskaźnika do puntku podstawowego - nullptr 
	ilosc = 0; // zresetowanie ilości elementów 
}

void HeadSinglyLinkedList::dodajNaPoczatek(int dane)
{
	Element* element = new Element; // utworzenie nowego elementu 
	element->dane = dane;
	element->nast = head; 
	head = element; // ustawienie nowego elementu jako heada listy 
	ilosc++; // zwiekszenie licznika
}

void HeadSinglyLinkedList::dodajNaKoniec(int dane)
{
	Element* element = new Element;
	element->dane = dane;
	element->nast = nullptr;

	if (head == nullptr) // Sprawdzam czy lista jest pusta 
	{
		head = element;
	}
	else
	{
		Element* pom = head;
		while (pom->nast != nullptr)
		{
			pom = pom->nast; // przesuwanie elementu 
		}
		pom->nast = element; // dpdanie elementu na koniec listy 
	}
	ilosc++;
}

bool HeadSinglyLinkedList::dodaj(int index, int dane)
{
	if (index < 0) // sprawdzenie indeksu czy zostałpoprawnie stworzony 
	{
		return false;
	}
	if (index == 0) // dodanie na początek listy 
	{
		dodajNaPoczatek(dane);
		return true;
	}
	if (head == nullptr) // Sprawdzenie czy lista jest pusta 
	{
		return false;
	}
	Element* przed = znajdzElementPrzed(index); // znalezienie elementu poprzedzającego 
	if (przed == nullptr)
	{
		return false;
	}

	Element* nowy = new Element; // nowy element 
	nowy->dane = dane;
	nowy->nast = przed->nast; // przypisanie wskaźnika na następny element 
	przed->nast = nowy;
	ilosc++; // zwiekszenie ilosci
	return true;
}

bool HeadSinglyLinkedList::usun(int index)
{
	if (index < 0) // sprawdzenie indeksu 
	{
		return false;
	}

	if (head == nullptr) // sprawdzenie czy lista jest pusta 
	{
		return false;
	}

	if (index == 0) // warunek usunięcia z początku listy 
	{
		return usunZPoczateku();
	}

	Element* przed = znajdzElementPrzed(index); // znalezienie elementu poprzedzającego 
	if (przed == nullptr)
	{
		return false;
	}

	Element* doUsuniecia = przed->nast; // element do usunięcia 
	if (doUsuniecia == nullptr)
	{
		return false;
	}
	przed->nast = doUsuniecia->nast;
	delete doUsuniecia; // usunięcie elementu 
	ilosc--; // zmniejszenie licznika 
	return true;

}

bool HeadSinglyLinkedList::usunZPoczateku()
{
	if (head == nullptr)
	{
		return false;
	}

	Element* doUsuniecia = head;
	head = head->nast; // przesunięcie wskaźnika na następny element 
	delete doUsuniecia; // usunięcie elementu 
	ilosc--; // zmniejszenie licznika 
	return true;
}
bool HeadSinglyLinkedList::usunZKonca()
{
	return usun(ilosc - 1);
}

int HeadSinglyLinkedList::dajIlosc() const
{
	return ilosc; // zwrócenie ilości elementów 
}

int HeadSinglyLinkedList::dajEmenet(int index) const
{
	if (index < 0) // sprawdzenie warunku poprawności 
	{
		return false;
	}

	if (head == nullptr) // sprawdzenie czy lista jest pusta 
	{
		return false;
	}

	if (index == 0) // zwrócenie pierwszego elementu 
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

// wypisanie zawartości listy 
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

// znalezienie elementu poprzedzającego element 
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

// skopiowanie xzawartości listy 
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

// usunięcie elementów listy 
void HeadSinglyLinkedList::skasuj()
{
	while (head != nullptr)
	{
		Element* doUsuniecia = head;
		head = head->nast;
		delete doUsuniecia;
	}
}

