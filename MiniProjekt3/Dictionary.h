#pragma once
class Dictionary
{
public:
	virtual bool insert(int key, int value) = 0; // dodanie elementu o podanym kluczu i wartosci 
	virtual void remove(int key) = 0; // usuniecie elementu o podanym kluczu
	virtual bool contains(int key) = 0; // sprawdzenie czy wartosc o podanym kluczu istnieje 
	virtual int get(int key) = 0; // zwraca wartosc elementu o podanym kluczu
	virtual void clean() = 0; // usuniecie elementow drzewa
	virtual void cleanAndResize(int size) = 0; // usuniecie elementow i zmiana rozmiaru 
};
