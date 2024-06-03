#include <iostream>
#include "Tests.h"
#include "Menu.h"
#include "ConsoleReader.h"
#include "Dictionary.h"
#include "HashTableOpenAddresing.h"
#include "HashTableSeparateChasingWithBST.h"
#include "HashTableSeparateChasingWithList.h"

using namespace std;

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
	srand(time(0));
	HashTableOpenAddresing openAddresing(100);
	HashTableSeparateChasingWithList separateChasingWithList(100);
	HashTableSeparateChasingWithBST separateChasingWithBST(100);
	int coutnOperation = 100000;
	int dictionarySize = 500000;
	Tests pomiar(coutnOperation, dictionarySize);
	//Tests pomiar(100, 200);
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
			menuOpenAddresing.run();
			break;
		case 2:
			menuSeparateChasingWithList.run();
			break;
		case 3:
			menuSeparateChasingWithBST.run();
			break;
		case 4:
			pomiar.makeTests();
			break;
		}
	}
	cout << endl;

}
