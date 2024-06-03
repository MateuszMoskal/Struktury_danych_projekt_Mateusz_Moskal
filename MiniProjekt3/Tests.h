#pragma once
#include <iostream>
#include "Dictionary.h"

using namespace std;

class Tests
{
private:
    int coutnOperation;
    int dictionarySize;
public:
    Tests(int coutnOperation, int dictionarySize);
    void makeTests();

private:
    void makeTests(Dictionary* dictionary, string nazwa, int* keysToCreate, int* kaysToDelete);
    double insert(Dictionary* dictionary, int* keys);
    double remove(Dictionary* dictionary, int* keys);
};


