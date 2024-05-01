#include <iostream>
#include "Pobieranie.h"

using namespace std;

int Pobieranie::pobierzInt(string nazwa, int min, int max)
{
    int liczba; // zmienna przechowujaca liczbe
    bool poprawne = false;
    // petla wykonuje sie dopoki nie zostanie wprowadzona prawidlowa wartosc
    while (!poprawne)
    {
        cout << "podaj " << nazwa << ": ";
        cin >> liczba; // wczytanie liczby z konsoli 
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
        // sprawdzam czy liczba miesci sie w zakresie
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

string Pobieranie::pobierzString(string nazwa, int min, int max)
{
    string text; // zmienna przechowujaca ciag znakow 
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