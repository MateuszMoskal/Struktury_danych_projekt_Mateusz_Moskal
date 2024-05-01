#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap()
{
	maxSize = 10;
	size = 0;
	arr = new Item[maxSize]; // alokacja pamieci dla tablicy elementow kopca
}

// konstruktor kopiujacy
Heap::Heap(const Heap& heap) {
	maxSize = heap.maxSize;
	size = heap.size;
	arr = new Item[maxSize];
	for (int i = 0; i < size; i++) // skopiowanie zawartosci kopca
	{
		arr[i] = heap.arr[i];
	}
}

// destruktor dla kopca
Heap::~Heap()
{
	delete[] arr;
}
// operator przypisania 
Heap& Heap::operator=(const Heap& arrayList) {
	if (this != &arrayList) {
		size = arrayList.size;
		if (maxSize != arrayList.maxSize)
		{
			delete[] arr;
			arr = new Item[arrayList.maxSize];
			maxSize = arrayList.maxSize;
		}
		for (int i = 0; i < size; i++)
		{
			arr[i] = arrayList.arr[i];
		}
	}
	return *this;
}

void Heap::insert(int value, int priorytary)
{
	if (maxSize == size)
	{
		increaseArray(); // powiekszenie tablicy 
	}
	arr[size].value = value; // ustawienie nowej wartosci elementu 
	arr[size].priorytary = priorytary; // ustawienie nowej wartosci priorytetu elementu 
	size++; // zwiekszenie liczby elementow 
	moveLeft(size - 1);
}
// usuwanie i zwrocenie elementu o najwyzszym priorytecie
int Heap::extractMax()
{
	if (size == 0) // sprawdzam czy kopiec jest pusty 
	{
		return -1;
	}
	int value = peek();
	if (size == 1)
	{
		size--; // zmniejszenie liczby elementow 
		return value; // zwracam wartosc elementu ktory jednoczesnie jest o najwyzszym priorytecie
	}
	size--;
	arr[0] = arr[size]; // przeniesienie ostatniego elementu na pozycje rodzica 
	moveRight(0);
	return value;
}
int Heap::peek()
{
	return arr[0].value; // zwracam wartosc pierwszego elementu 
}
// modyfikacja priorytetu elementu 
void Heap::modyfyKey(int item, int priorytary)
{
	int index = findIndex(item);
	if (index == -1)
	{
		return;
	}
	if (arr[index].priorytary == priorytary)
	{
		return;
	}
	if (arr[index].priorytary > priorytary) //zmniejszamy priorytet - to jak usuwanie
	{
		arr[index].priorytary = priorytary;
		moveRight(index);
	}
	else //zwiekszamy prioryret - tak jak wstawianie do kopca
	{
		arr[index].priorytary = priorytary;
		moveLeft(index);
	}
}

int Heap::findIndex(int item)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].value == item) // zwracam indeks jezeli element zostal znaleziony 
		{
			return i;
		}
	}
	return -1;
}

void Heap::clean()
{
	this->~Heap();
	maxSize = 10; // powrot do poczatkowego maksymalnego rozmiaru 
	size = 0;
	arr = new Item[maxSize]; // nowa tablica 
}

// rozmiar kopca
int Heap::getSize()
{
	return size;
}


void Heap::moveLeft(int index)
{
	Item item = arr[index];
	int itemIndex = index++;
	int parentIndex = (itemIndex - 1) / 2;

	while (itemIndex > 0 && arr[parentIndex].priorytary < item.priorytary)
	{
		arr[itemIndex] = arr[parentIndex];
		itemIndex = parentIndex;
		parentIndex = (itemIndex - 1) / 2;
	}
	arr[itemIndex] = item;
}
 
void  Heap::moveRight(int index)
{
	Item item = arr[index];
	int itemIndex = index;
	int childIndex = 2 * itemIndex + 1;
	while (childIndex < size)
	{
		if (childIndex + 1 < size && arr[childIndex + 1].priorytary > arr[childIndex].priorytary) childIndex++;
		if (item.priorytary >= arr[childIndex].priorytary) break;
		arr[itemIndex] = arr[childIndex];
		itemIndex = childIndex;
		childIndex = 2 * childIndex + 1;
	}
	arr[itemIndex] = item;
}


void Heap::decreaseArray()
{

}


// Zwiekszenie rozmiaru tablicy
void Heap::increaseArray()
{
	maxSize = maxSize * 2;
	Item* nowa = new Item[maxSize];
	for (int i = 0; i < size; i++)
	{
		nowa[i] = arr[i];
	}
	delete[] arr;
	arr = nowa;
}

// wyswietlenie kopca 
void Heap::print()
{
	// pierwszy element 
	if (size > 0)
	{
		cout << "	      " << arr[0].priorytary << endl;
		cout << "	      " << arr[0].value << endl;
	}
	// drugi poziom 
	if (size > 1)
	{
		cout << "      ";
		for (int i = 0; i < 2; i++)
		{
			if (i + 1 < size)
			{
				cout << arr[i + 1].priorytary << "              ";
			}
		}
		cout << endl;
		cout << "      ";
		for (int i = 0; i < 2; i++)
		{
			if (i + 1 < size)
			{
				cout << arr[i + 1].value << "              ";
			}
		}
		cout << endl;
	}
	// trzeci poziom 
	if (size > 3)
	{
		cout << "  ";
		for (int i = 0; i < 4; i++)
		{
			if (i + 3 < size)
			{
				cout << arr[i + 3].priorytary << "      ";
			}
		}
		cout << endl;
		cout << "  ";
		for (int i = 0; i < 4; i++)
		{
			if (i + 3 < size)
			{
				cout << arr[i + 3].value << "      ";
			}
		}
		cout << endl;

	}
	// czwarty poziom 
	if (size > 7)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i + 7 < size)
			{
				cout << arr[i + 7].priorytary << "  ";
			}
		}
		cout << endl;
		for (int i = 0; i < 8; i++)
		{
			if (i + 7 < size)
			{
				cout << arr[i + 7].value << "  ";
			}
		}
		cout << endl;
	}

	cout << "-----------------------------------------------------" << endl;

}
