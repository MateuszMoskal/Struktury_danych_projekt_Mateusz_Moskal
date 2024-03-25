#pragma once
#include <string>

using namespace std;

class Pobieranie
{
public:
	static int pobierzInt(string nazwa, int min, int max);
	static string pobierzString(string nazwa, int min, int max);
};



