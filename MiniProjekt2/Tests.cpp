#include "Tests.h"
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <iomanip> 
#include "Heap.h"
#include "HeadSinglyLinkedList.h"

Tests::Tests(int coutnOperation)
{
    this->coutnOperation = coutnOperation;
}
void Tests::makeTests()
{
    PriorytaryQueue* queue;
    cout << "testy dla " << coutnOperation << " operacji" << endl;
    cout << "+--------------------------+------------+------------+------------+------------+------------+" << endl;
    cout << "| kolejka                  | insert     | extractMax | modyfyKey  | peek       | size       |" << endl;
    cout << "+--------------------------+------------+------------+------------+------------+------------+" << endl;

    queue = new Heap(); // testy dla kopca 
    makeTests(queue, "Heap");

    queue = new HeadSinglyLinkedList(); // testy dla listy wiazanej jednokierunkowej z jednym wskaznikiem 
    makeTests(queue, "HeadSinglyLinkedList");
}


void Tests::makeTests(PriorytaryQueue* queue, string nazwa)
{
    double czas; // zmienna przechowujaca czas operacji 
    cout << "| " << setw(24) << left << nazwa << " | ";

    //test operacji insert
    czas = insert(queue);
    cout << setprecision(5) << fixed << setw(10) << czas << " | ";
    queue->clean();

    //test operacji extactMax
    czas = extractMax(queue);
    cout << setprecision(5) << fixed << setw(10) << czas << " | ";
    queue->clean();

    // test operacji modyfyKey
    czas = modyfyKey(queue);
    cout << setprecision(5) << fixed << setw(10) << czas << " | ";

    // test operacji peek
    czas = peek(queue);
    cout << setprecision(5) << fixed << setw(10) << czas << " | ";

    // test operacji zwrocenia rozmiaru kolejki 
    czas = size(queue);
    cout << setprecision(5) << fixed << setw(10) << czas << " |" << endl;

    delete queue; // zwolnienie pamieci dla kolejki 


    cout << "+--------------------------+------------+------------+------------+------------+------------+" << endl;

}

double Tests::insert(PriorytaryQueue* queue)
{
    auto start = std::chrono::high_resolution_clock::now(); // poczatek pomiaru czasu 

    for (int i = 0; i < coutnOperation; i++)
    {
        queue->insert(rand() % 1000, rand() % 1000); // wstawianie losowych elementow do kolejki 
    }

    auto end = std::chrono::high_resolution_clock::now(); // koniec pomiaru czasu 
    std::chrono::duration<double> duration = end - start; // obliczanie czasu operacji 

    return duration.count(); // zwrocenie czasu w sekundach (zapytac)
}

double Tests::extractMax(PriorytaryQueue* queue)
{
    insert(queue); // wstawiam element do kolejki przed testem 
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < coutnOperation; i++)
    {
        queue->extractMax(); // wyjmuje element z najwyzszym priorytetem 
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double Tests::modyfyKey(PriorytaryQueue* queue)
{
    insert(queue);
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < coutnOperation; i++)
    {
        queue->modyfyKey(rand() % 1000, rand() % 1000); // modyfikacja priorytetu elementu wskazanego w kolejce 
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double Tests::peek(PriorytaryQueue* queue)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < coutnOperation; i++)
    {
        queue->peek(); // podejrzenie elementu o najwyzszym priorytecie w kolejce 
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}
double Tests::size(PriorytaryQueue* queue)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < coutnOperation; i++)
    {
        queue->getSize(); // rozmiar kolejki 
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

