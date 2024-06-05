#include <iostream>
#include "Tests.h"
#include "Menu.h"
#include "ConsoleReader.h"
#include "Dictionary.h"
#include "HashTableOpenAddresing.h"
#include "HashTableSeparateChasingWithBST.h"
#include "HashTableSeparateChasingWithList.h"

using namespace std;

// Funkcja wyœwietlaj¹ca g³owne menu programu
void wypiszMenu()
{
	cout << "Menu" << endl;
	cout << "1 - slownik - implementacja jako Hash table with open addresing" << endl;
	cout << "2 - slownik - implementacja jako Hash table with separate chasing with linked list" << endl;
	cout << "3 - slownik - implementacja jako Hash table with separate chasing with BST" << endl;
	cout << "4 - testy wydajnosci" << endl;
	cout << "5 - wyjscie" << endl;
	cout << endl;
}


int main()
{
	srand(time(0)); // generator losowy
	HashTableOpenAddresing openAddresing(100);
	HashTableSeparateChasingWithList separateChasingWithList(100);
	HashTableSeparateChasingWithBST separateChasingWithBST(100);
	int coutnOperation = 100000; // Liczba operacji do wykonania w testach
	int dictionarySize = 500000; // Rozmiar s³ownika do testów
	Tests pomiar(coutnOperation, dictionarySize); // obiekt do testów
	//Tests pomiar(100, 200);

	// Tworzenie menu dla ró¿nych implementacji s³owników
	Menu menuOpenAddresing(&openAddresing, "Hash table with open addresing");
	Menu menuSeparateChasingWithList(&separateChasingWithList, "Hash table with separate chasing with linked list");
	Menu menuSeparateChasingWithBST(&separateChasingWithBST, "Hash table with separate chasing with BST");

	int wybor = 0;
	while (wybor != 5)
	{
		wypiszMenu();
		wybor = ConsoleReader::readInt("wybor", 1, 5);

		switch (wybor)
		{
		case 1:
			menuOpenAddresing.run(); // Uruchomienie menu dla HashTableOpenAddresing
			break;
		case 2:
			menuSeparateChasingWithList.run(); // Uruchomienie menu dla HashTableSeparateChasingWithList
			break;
		case 3:
			menuSeparateChasingWithBST.run(); // Uruchomienie menu dla HashTableSeparateChasingWithBST
			break;
		case 4:
			pomiar.makeTests(); // Wykonanie testów wydajnoœci
			break;
		}
	}
	cout << endl;

}
