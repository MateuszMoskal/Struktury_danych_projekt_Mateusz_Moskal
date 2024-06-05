#pragma once
#include <string>

using namespace std;

class ConsoleReader
{
public:
	static int readInt(string nazwa, int min, int max); // metoda ta pobiera liczbe calkowita z zakresu od min do max
	static string readString(string nazwa, int min, int max); // metoda ta pobiera ciag znakow o dlugosci od min do max
};
