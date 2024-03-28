#include "PomiaryCzasu.h"
#include <chrono>
#include <stdlib.h>     /* srand, rand */
#include <iomanip>   
PomiaryCzasu::PomiaryCzasu(int iloscOperacji)
{
    this->iloscOperacji = iloscOperacji; // ustawiam iloœæ operacji 
}
// Metoda wykonuj¹ca zestaw testów 
void PomiaryCzasu::wykonajTesty()
{
    Kontener* kontener;
	
	// wyœwietlanie informacji po odpaleniu programu 
    cout << "testy dla " << iloscOperacji << " operacji" << endl;
    cout << "+--------------------------+-----------+-------------+-------------+-------------+" << endl;
    cout << "| kontener                 | akcja     | na poczatek | losowo      | na koniec   |" << endl;
    cout << "+--------------------------+-----------+-------------+-------------+-------------+" << endl;

	// testy dla tablicy dynamicznej
    kontener = new ArrayList();
    wykonajTesty(kontener, "ArrayList");

	// testy dla listy jednokierunkowej z jednym wskaŸnikiem
    kontener = new HeadSinglyLinkedList();
    wykonajTesty(kontener, "HeadSinglyLinkedList");

	// testy dla listy jednokierunkowej z dwoma wskaŸnikami 
    kontener = new HeadTailSinglyLinkedList();
    wykonajTesty(kontener, "HeadTailSinglyLinkedList");

	// testy dla listy dwukierunkowej 
    kontener = new DoublyLinkedList();
    wykonajTesty(kontener, "DoublyLinkedList");
}

// zestaw testu dla danego kontenera 
void PomiaryCzasu::wykonajTesty(Kontener* kontener, string nazwa)
{
    double czas; // zmienna przechowuj¹ca czas
    cout << "| " << setw(24) << left << nazwa << " | dodawanie | "; // wyœwietlenie nazwy

	// pomiar czasu dla dodawania na pocz¹tek 
    czas = czasDodawaniaNaPoczatek(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc(); // wyczyszczenie kontenera 

	// pomiar czasu dla dodawania w dowolne miejsce 
    czas = czasDodawaniaNaSrodek(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();

	// pomiar czasu dla dodawania na koniec 
    czas = czasDodawaniaNaKoniec(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " |" << endl;
    kontener->wyczysc();

    cout << "|                          | usuwanie  | "; // wyœwietlenie nazwy

	// pomiar czasu dla usuwania na pocz¹tek
    czas = czasUsuwaniaZPoczatku(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();
	
	// pomiar czasu dla usuwania w dowolnym miejscu 
    czas = czasUsuwaniaZeSrodka(kontener);
    cout << setprecision(5) << fixed << setw(11) << czas << " | ";
    kontener->wyczysc();
	
	// pomiar czasu dla dodawania na koniec 
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
    auto start = std::chrono::high_resolution_clock::now(); // pocz¹tek pomiaru czasu 

    for (int i = 0; i < iloscOperacji; i++) // dodawanie iloœci operacji losowych elementów
    {
        kontener->dodajNaPoczatek(rand());
    }

    auto end = std::chrono::high_resolution_clock::now(); // koniec pomiaru czasu
    std::chrono::duration<double> duration = end - start; // róŸnica czasu

    return duration.count(); // zwracanie czasu w sekundach 
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



