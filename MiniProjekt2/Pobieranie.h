#pragma once

#include <string>

using namespace std;

class Pobieranie
{
public:
	static int pobierzInt(string nazwa, int min, int max); // metoda ta pobiera liczbe calkowita z zakresu od min do max
	static string pobierzString(string nazwa, int min, int max); // metoda ta pobiera ciag znakow o dlugosci od min do max
};

