#pragma once
#include <iostream>
#include "Dictionary.h"

using namespace std;

class Tests
{
private:
    int coutnOperation; // liczba operacji 
    int dictionarySize; // rozmiar slownika 
public:
    Tests(int coutnOperation, int dictionarySize);
    void makeTests(); // uruchomienie testu na roznych impleentacjach 

private:
    void makeTests(Dictionary* dictionary, string nazwa, int* keysToCreate, int* kaysToDelete); // przeprowadzenie testu na slowniku 
    double insert(Dictionary* dictionary, int* keys); // mierzy czas wstawienia elementu do slownika 
    double remove(Dictionary* dictionary, int* keys); // mierzy czas usuniecia elementu ze slownika 
};


