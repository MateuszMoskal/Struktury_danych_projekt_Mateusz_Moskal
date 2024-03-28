#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "ArrayList.h"
#include "HeadSinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "PomiaryCzasu.h"
#include "Menu.h"
#include "Pobieranie.h"
using namespace std;


void wypiszMenu()
{
	cout << "Menu" << endl;
	cout << "1 - array list" << endl;
	cout << "2 - head singly linked list" << endl;
	cout << "3 - head-tail singly linked list" << endl;
	cout << "4 - doubly linked list" << endl;
	cout << "5 - testy wydajnosci" << endl;
	cout << "6 - wyjscie" << endl;
	cout << endl;
}

int main()
{
	srand(time(0));

	ArrayList arrayList;
	HeadSinglyLinkedList headSinglyLinkedList;
	HeadTailSinglyLinkedList headTailSinglyLinkedList;
	DoublyLinkedList doublyLinkedList;

	PomiaryCzasu pomiar(100000); // miejsce w ktorym definiuje ilosc operacji do testu 
	Menu menuArrayList(&arrayList, "array list"); // Inicjalizacja pszczególnych menu 
	Menu menuHeadSinglyLinkedList(&headSinglyLinkedList, "head singly linked list");
	Menu menuHeadTailSinglyLinkedList(&headTailSinglyLinkedList, "head-tail singly linked list");
	Menu menuDoublyLinkedList(&doublyLinkedList, "doubley linked list");


	int wybor = 0;
	while (wybor != 6)
	{
		wypiszMenu();
		wybor = Pobieranie::pobierzInt("wybor", 1, 6);

		switch (wybor)
		{
		case 1:
			menuArrayList.uruchom(); // Uruchomienie menu dla tablicy dynamicznej 
			break;
		case 2:
			menuHeadSinglyLinkedList.uruchom(); // Uruchomienie menu dla listy jednokierunkowej z jedynym wskaźnikiem 
			break;
		case 3:
			menuHeadTailSinglyLinkedList.uruchom(); // Uruchomienie menu dla listy jednokierunkowej z dwoma wskaźnikami
			break;
		case 4:
			menuDoublyLinkedList.uruchom(); // Uruchomienie menu dla listy dwukierunkowej 
			break;
		case 5:
			pomiar.wykonajTesty(); // testy
			break;
		}
	}
	cout << endl;

}

