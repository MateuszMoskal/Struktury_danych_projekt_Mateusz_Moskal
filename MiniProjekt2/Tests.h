#pragma once
#include <iostream>
#include "PriorytaryQueue.h"

using namespace std;

class Tests
{
private:
    int coutnOperation; // liczba operacji do wykonania 

public:
    Tests(int coutnOperation);
    void makeTests(); // inicjacja funkcji do testow

private:
    void makeTests(PriorytaryQueue* queue, string nazwa); // funkcja przeprowadza testy na konkretnej kolejce 

    double insert(PriorytaryQueue* queue);
    double extractMax(PriorytaryQueue* queue);
    double modyfyKey(PriorytaryQueue* queue);
    double peek(PriorytaryQueue* queue);
    double size(PriorytaryQueue* queue);
};

