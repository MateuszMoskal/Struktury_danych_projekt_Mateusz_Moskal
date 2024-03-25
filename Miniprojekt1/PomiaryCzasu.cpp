#include "PomiaryCzasu.h"
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <iomanip>   
PomiaryCzasu::PomiaryCzasu(int iloscOperacji)
{
    this->iloscOperacji = iloscOperacji;
}
void PomiaryCzasu::wykonajTesty()
{
    Kontener* kontener;
    cout << "testy dla " << iloscOperacji << " operacji" << endl;
    cout << "+--------------------------+-----------+-------------+-------------+-------------+" << endl;
    cout << "| kontener                 | akcja     | na poczatek | losowo      | na koniec   |" << endl;
    cout << "+--------------------------+-----------+-------------+-------------+-------------+" << endl;

    kontener = new ArrayList();
    wykonajTesty(kontener, "ArrayList");

    kontener = new HeadSinglyLinkedList();
    wykonajTesty(kontener, "HeadSinglyLinkedList");

    kontener = new HeadTailSinglyLinkedList();
    wykonajTesty(kontener, "HeadTailSinglyLinkedList");

    kontener = new DoublyLinkedList();
    wykonajTesty(kontener, "DoublyLinkedList");
}


void PomiaryCzasu::wykonajTesty(Kontener* kontener, string nazwa)
{
    double czas;
    cout << "| " << setw(24) << left << nazwa << " | dodawanie | ";

    czas = czasDodawaniaNaPoczatek(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();

    czas = czasDodawaniaNaSrodek(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();

    czas = czasDodawaniaNaKoniec(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " |" << endl;
    kontener->wyczysc();

    cout << "|                          | usuwanie  | ";

    czas = czasUsuwaniaZPoczatku(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();

    czas = czasUsuwaniaZeSrodka(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();

    czas = czasUsuwaniaZKonca(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " |" << endl;
    delete kontener;

    cout << "+--------------------------+-----------+-------------+-------------+-------------+" << endl;





    // czasDodawaniaNaKoniec(&arrayList);
     //– pocz¹tek tablicy(listy),
         //– koniec tablicy(listy),
         //– losowe miejsce tablicy(listy)


}

double PomiaryCzasu::czasDodawaniaNaPoczatek(Kontener* kontener)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iloscOperacji; i++)
    {
        kontener->dodajNaPoczatek(rand());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double PomiaryCzasu::czasDodawaniaNaSrodek(Kontener* kontener)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iloscOperacji; i++)
    {
        kontener->dodaj(rand() % (kontener->dajIlosc() + 1), rand());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double PomiaryCzasu::czasDodawaniaNaKoniec(Kontener* kontener)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iloscOperacji; i++)
    {
        kontener->dodajNaKoniec(rand());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double PomiaryCzasu::czasUsuwaniaZPoczatku(Kontener* kontener)
{
    czasDodawaniaNaPoczatek(kontener);
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iloscOperacji; i++)
    {
        kontener->usunZPoczateku();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double PomiaryCzasu::czasUsuwaniaZeSrodka(Kontener* kontener)
{
    czasDodawaniaNaPoczatek(kontener);
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iloscOperacji; i++)
    {
        kontener->usun(rand() % kontener->dajIlosc());
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double PomiaryCzasu::czasUsuwaniaZKonca(Kontener* kontener)
{
    czasDodawaniaNaPoczatek(kontener);
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iloscOperacji; i++)
    {
        kontener->usunZKonca();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}



