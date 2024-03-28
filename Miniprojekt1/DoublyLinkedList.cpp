#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr; // inicjalizuję wskaźnik head
	tail = nullptr; // inicjalizuję wskaźnik tail 
	ilosc = 0; // poczatkowa liczba elementow 
}

// Konstruktor kopiujący
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list) : DoublyLinkedList()
{
	skopiuj(list);
}
// Destruktor 
DoublyLinkedList::~DoublyLinkedList()
{
	skasuj(); 
}
// Przeciążenie operatora 
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& list)
{
	skasuj(); // usunięcie listy
	skopiuj(list); // skopiowanie nowej listy 
	return *this;
}

void DoublyLinkedList::wyczysc()
{
	this->~DoublyLinkedList(); // wywołanie destruktora
	head = nullptr;
	tail = nullptr;
	ilosc = 0; // zresetowanie liczniki ilosci elementów
}

//ok
void DoublyLinkedList::dodajNaPoczatek(int dane)
{
	Element2* element = new Element2; // utworzenie nowego elementu 
	element->pop = nullptr;
	element->nast = head;
	if (head == nullptr) // sprawdzam czy lista jest pusta 
	{
		head = element; // jeżeli tak to ustawiam wskaźniki na nowy element 
		tail = element;
	}
	else
	{
		head->pop = element; // w przeciwnym razie ustawiam poprzedni element heada na nowy element
		head = element;
	}

	ilosc++; // zwiększam liczniki ilosci elementów 
}


void DoublyLinkedList::dodajNaKoniec(int dane)
{
	Element2* element = new Element2; // ten sam schemat co dodawanie na początek
	element->dane = dane;
	element->nast = nullptr;
	element->pop = nullptr;

	if (tail == nullptr) // Sprawdzam czy lista jest pusta 
	{
		head = element; // jeżeli tak, ustawiam nowy element 
		tail = element;
	}
	else
	{
		tail->nast = element; // w przeciwnym razie ustawiam nastepny element ogona jako nowy element 
		element->pop = tail;
		tail = element; 
	}
	ilosc++; // zwiększam licznik
}

// Dodanie elementu w dowolnym miejscu 
bool DoublyLinkedList::dodaj(int index, int dane)
{
	if (index < 0) // Sprawdzenie czy index jest prawidłowy 
	{
		return false;
	}
	if (index == 0) // Jeżeli jest równy 0 to dodajemy na początek listy 
	{
		dodajNaPoczatek(dane);
		return true;
	}
	if (index == ilosc) // jeżeli jest równy ilosci dodajemy na koniec 
	{
		dodajNaKoniec(dane);
		return true;
	}
	if (head == nullptr)
	{
		return false;
	}
	Element2* przed = znajdzElementPrzed(index); // znalezienie elementu poprzedzajacego wstawiany element 
	if (przed == nullptr) // Sprawdzam czy znalazłem element poprzedni 
	{
		return false;
	}
	Element2* za = przed->nast;

	Element2* nowy = new Element2;
	nowy->dane = dane; 
	nowy->nast = za; // ustawienie nowego następnego elementu 
	przed->nast = nowy;
	nowy->pop = przed;
	if (przed == tail) // Sprawdzam czy poprzedni element nie jest tailem 
	{
		tail = nowy; // jeżeli jest to ustawiam jako ogon 
		nowy->nast = nullptr;
	}
	else
	{
		nowy->nast = za; // w przeciwnym razie ustawienie nowego następnego elementu 
	}
	ilosc++;

	return true;
}

bool DoublyLinkedList::usun(int index)
{
	if (index < 0) // sprawdzam czy index jest prawidłowy 
	{
		return false;
	}

	if (head == nullptr) // sprawdzam czy lista jest pusta
	{
		return false;
	}

	if (index == 0) // jeżeli index równy 0 to usuwam element z początku 
	{
		return usunZPoczateku();
	}
	if (index == ilosc - 1) // jeżeli index równy ilosc - 1 to usuwam z końca listy 
	{
		return usunZKonca();
	}
	Element2* przed = znajdzElementPrzed(index); // Szukam elementu poprzedzającego usuwany element 
	if (przed == nullptr)
	{
		return false;
	}

	Element2* doUsuniecia = przed->nast; // zapisanie usuwanego elementu 
	if (doUsuniecia == nullptr) // Sprawdzam czy usuwany element istnieje 
	{
		return false;
	}
	Element2* za = doUsuniecia->nast; // zapisanie elementu za usuwanym elementem 
	przed->nast = za;
	if (doUsuniecia == tail) // sprawdzam czy usuwany element był tailem 
	{
		tail = przed; // jesli tak to ustawiam element poprzedni jako nowy tail
	}
	else
	{
		za->pop = przed;
	}

	delete doUsuniecia; // usuwam element do usunięcia 

	ilosc--; // redukuje liczbe elementow 
	return true;

}

bool DoublyLinkedList::usunZPoczateku()
{
	if (head == nullptr)
	{
		return false;
	}
	Element2* doUsuniecia = head; // zapisanie pierwszego elementu 
	head = head->nast; // ustawienie nastepnego elementu jako heada 
	if (head != nullptr) // jezeli head jest rozny od nullptr
	{
		head->pop = nullptr; // ustawiam poprzedni element jako nullptr
	} 
	else
	{
		tail = nullptr; // w przeciwnym wypadku tail ustawiam jako nullptr
	}

	delete doUsuniecia; // Usuwam pierwszy element 
	ilosc--; // redukuje ilosc elementów 
	return true;
}
bool DoublyLinkedList::usunZKonca()
{
	if (tail == nullptr) // Sprawdzam czy lista jest pusta
	{
		return false;
	}
	Element2* doUsuniecia = tail; // zapisuje ostatni element 
	tail = tail->pop;

	if (tail != nullptr) // Sprawdzam czy istnieje poprzedni element 
	{
		tail->nast = nullptr; // jesli tak ustawiam poprzedni element jako nullptr
	}
	else
	{
		head = nullptr; // w przeciwnym razie ustawiam head jako nullptr
	}

	delete doUsuniecia; // usuwam ostatni element 
	ilosc--; // redukuje ilosc elementow 
	return true;
}

//ok
int DoublyLinkedList::dajIlosc() const
{
	return ilosc; // zwracam ilosc elementow 
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

	if (index == 0) // zwrócenie pierwszego elementu 
	{
		return head->dane;
	}
	if (index == ilosc - 1) // zwrocenie ostatniego elementu 
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


// wypisanie zawartosci listy 
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

// znajdowanie elementu poprzedzającego element o podanym indeksie 
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

// znajdowanie elementu poprzedzającego element o podanymm indeksie zaczynając od przodu 
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

//znajdowanie elementu poprzedzającego element o podanymm indeksie zaczynając od tyłu
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
// kopiowanie zawartości listy z innej listy 
void DoublyLinkedList::skopiuj(const DoublyLinkedList& list)
{
	Element2* kursor = list.head;

	while (kursor != nullptr)
	{
		dodajNaKoniec(kursor->dane);
		kursor = kursor->nast;
	}
}

// usuwanie wszystkich elementów z listy 
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

