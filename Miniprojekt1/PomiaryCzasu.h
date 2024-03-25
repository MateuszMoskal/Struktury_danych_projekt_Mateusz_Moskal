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
    int iloscOperacji;
    HeadSinglyLinkedList headSinglyLinkedList;
    HeadTailSinglyLinkedList headTailSinglyLinkedList;
    DoublyLinkedList doublyLinkedList;

public:
    PomiaryCzasu(int iloscOperacji);
    void wykonajTesty();

private:
    void wykonajTesty(Kontener* kontener, string nazwa);

    double czasDodawaniaNaPoczatek(Kontener* kontener);
    double czasDodawaniaNaSrodek(Kontener* kontener);
    double czasDodawaniaNaKoniec(Kontener* kontener);
    double czasUsuwaniaZPoczatku(Kontener* kontener);
    double czasUsuwaniaZeSrodka(Kontener* kontener);
    double czasUsuwaniaZKonca(Kontener* kontener);
};
