#include "Tests.h"
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <iomanip> 
#include "HashTableOpenAddresing.h"
#include "HashTableSeparateChasingWithBST.h"
#include "HashTableSeparateChasingWithList.h"


Tests::Tests(int coutnOperation, int dictionarySize)
{
    this->coutnOperation = coutnOperation;
    this->dictionarySize = dictionarySize;
}

void Tests::makeTests()
{
    Dictionary* dictionary;
    cout << "testy dla " << coutnOperation << " operacji" << endl;
    cout << "+---------------------------------------------------+------------+------------+-------------------+-----------------+" << endl;
    cout << "| slownik                                           | insert     | remove     | wielkosc slownika | ilosc elementow |" << endl;
    cout << "+---------------------------------------------------+------------+------------+-------------------+-----------------+" << endl;

    int* keysToCreate = new int[coutnOperation];
    int* kaysToDelete = new int[coutnOperation];
    keysToCreate[0] = 1;
    kaysToDelete[0] = 1;
    for (int i = 1; i < coutnOperation; i++)
    {
        keysToCreate[i] = keysToCreate[i - 1] + rand() % 5;
        kaysToDelete[i] = keysToCreate[i];
    }
    for (int i = 0; i < coutnOperation; i++)
    {
        int index1 = rand() % coutnOperation;
        int index2 = rand() % coutnOperation;

        int pom = kaysToDelete[index1];
        kaysToDelete[index1] = kaysToDelete[index2];
        kaysToDelete[index2] = pom;
    }

    dictionary = new HashTableOpenAddresing(dictionarySize);
    makeTests(dictionary, "Hash table with open addresing", keysToCreate, kaysToDelete);

    dictionary = new HashTableSeparateChasingWithList(dictionarySize);
    makeTests(dictionary, "Hash table with separate chasing with linked list", keysToCreate, kaysToDelete);
    dictionary = new HashTableSeparateChasingWithBST(dictionarySize);
    makeTests(dictionary, "Hash table with separate chasing with BST", keysToCreate, kaysToDelete);
}

void Tests::makeTests(Dictionary* dictionary, string nazwa, int* keysToCreate, int* kaysToDelete)
{
    double czas;
    cout << "| " << setw(49) << left << nazwa << " | ";

    czas = insert(dictionary, keysToCreate);
    cout << setprecision(5) << fixed << setw(10) << czas << " | ";

    czas = remove(dictionary, kaysToDelete);
    cout << setprecision(5) << fixed << setw(10) << czas << " | ";

    cout << fixed << setw(17) << dictionarySize << " | ";
    cout << fixed << setw(15) << coutnOperation << " | " << endl;

    delete dictionary;

    cout << "+---------------------------------------------------+------------+------------+-------------------+-----------------+" << endl;

}

double Tests::insert(Dictionary* dictionary, int* keys)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < coutnOperation; i++)
    {
        dictionary->insert(keys[i], rand() % 1000);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}
double Tests::remove(Dictionary* dictionary, int* keys)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < coutnOperation; i++)
    {
        dictionary->remove(keys[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}