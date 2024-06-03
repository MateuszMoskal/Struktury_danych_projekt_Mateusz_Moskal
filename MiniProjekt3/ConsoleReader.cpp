#include "ConsoleReader.h"
#include <iostream>

int ConsoleReader::readInt(string nazwa, int min, int max)
{
    int liczba;
    bool poprawne = false;
    while (!poprawne)
    {
        cout << "podaj " << nazwa << ": ";
        cin >> liczba;
        if (cin.good())
        {
            poprawne = true;
        }
        else
        {
            //czyszenie strumienia wczytujacego
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "podano nie prawidlowa licze" << endl;
        }

        if (poprawne)
        {
            if (min <= liczba && liczba <= max)
            {
                poprawne = true;
            }
            else
            {
                poprawne = false;
                cout << "podano nie prawidlowa wartosc" << endl;
                cout << "wartosc liczy powinna byc w przedziale <" << min << ", " << max << ">" << endl;
            }
        }
    }

    return liczba;
}
string ConsoleReader::readString(string nazwa, int min, int max)
{
    string text;
    bool poprawne = false;
    while (!poprawne)
    {
        cout << "podaj " << nazwa << ": ";
        cin >> text;
        if (cin.good())
        {
            poprawne = true;
        }
        else
        {
            //czyszenie strumienia wczytujacego
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "podano nie prawidlowy napis" << endl;
        }

        if (poprawne)
        {
            if (min <= text.size() && text.size() <= max)
            {
                poprawne = true;
            }
            else
            {
                poprawne = false;
                cout << "podano nie prawidlowy text" << endl;
                cout << "dlugosc tekstu powinna byc w przedziale <" << min << ", " << max << ">" << endl;
            }
        }
    }

    return text;
}