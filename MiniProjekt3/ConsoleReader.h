#pragma once
#include <string>

using namespace std;

class ConsoleReader
{
public:
	static int readInt(string nazwa, int min, int max);
	static string readString(string nazwa, int min, int max);
};
