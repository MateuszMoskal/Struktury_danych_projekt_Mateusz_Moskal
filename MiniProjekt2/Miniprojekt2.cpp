#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


#include "HeadSinglyLinkedList.h"
#include "Heap.h"

#include "Tests.h"
#include "Menu.h"
#include "Pobieranie.h"
#include "PriorytaryQueue.h"

using namespace std;

// funkcja wyswietlajaca menu glowne 
void wypiszMenu()
{
	cout << "Menu" << endl;
	cout << "1 - kolejka - implementacja jako head singly linked list" << endl;
	cout << "2 - kolejka - implementacja jako Heap " << endl;
	cout << "3 - testy wydajnosci" << endl;
	cout << "4 - wyjscie" << endl;
	cout << endl;
}


int main()
{
	srand(time(0)); // inilicjalizacja generatora liczb 
	HeadSinglyLinkedList linkedList;
	Heap heap;

	Tests pomiar(1000000); // Obiekt do przeprowadzenia testow wydajnosci 
	Menu menuLinkedList(&linkedList, "head singly linked list");
	Menu menuHeap(&heap, "heap");

	int wybor = 0; // zmienna przechowuje (numer) wybor uzytkownika
	while (wybor != 6)
	{
		wypiszMenu();
		wybor = Pobieranie::pobierzInt("wybor", 1, 6);

		switch (wybor)
		{
		case 1:
			menuLinkedList.uruchom(); // uruchomienie menu dla listy wiazanej z jednym wskaznikiem 
			break;
		case 2:
			menuHeap.uruchom(); // uruchomienie menu dla kopca 
			break;
		case 3:
			pomiar.makeTests(); //testy wydajnosci
			break;
		}
	}
	cout << endl;

}

