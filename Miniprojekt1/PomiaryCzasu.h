#pragma once
#include <iostream>

#include "Kontener.h"
#include "ArrayList.h"
#include "HeadSinglyLinkedList.h"
#include "HeadTailSinglyLinkedList.h"


#include "DoublyLinkedList.h"

using namespace std;


class PomiaryCzasu
{
private:
    int iloscOperacji; // liczba operacji 
    HeadSinglyLinkedList headSinglyLinkedList; // Lista jednokierunkowa z jednym wskaźnikiem 
    HeadTailSinglyLinkedList headTailSinglyLinkedList; // Lista jednokierunkowa z dwoma wskaźnikami 
    DoublyLinkedList doublyLinkedList; // lista dwukierunkowa 

public:
    PomiaryCzasu(int iloscOperacji);
    void wykonajTesty(); // metoda wykonująca zestaw testów 

private:
    void wykonajTesty(Kontener* kontener, string nazwa);

    double czasDodawaniaNaPoczatek(Kontener* kontener); // Metoda mierząca czas dodawania na początek kontenera
    double czasDodawaniaNaSrodek(Kontener* kontener); // Metoda mierząca czas dodawania w dowolnym miejscu kontenera
    double czasDodawaniaNaKoniec(Kontener* kontener); // Metoda mierząca czas dodawania na końcu kontenera
    double czasUsuwaniaZPoczatku(Kontener* kontener); // Metoda mierząca czas usuwania na początek kontenera
    double czasUsuwaniaZeSrodka(Kontener* kontener); // Metoda mierząca czas usuwania w dowolnym miejscu kontenera
    double czasUsuwaniaZKonca(Kontener* kontener); // // Metoda mierząca czas usuwania na końcu kontenera
};
