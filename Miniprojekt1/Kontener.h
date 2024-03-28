#pragma once
class Kontener
{
public:
	virtual void wyczysc() = 0; // wykorzystuje metody wirtualne aby dynamicznie wiązać funkcje 

	virtual void dodajNaPoczatek(int dane) = 0;
	virtual void dodajNaKoniec(int dane) = 0;
	virtual bool dodaj(int index, int dane) = 0;

	virtual bool usunZPoczateku() = 0;
	virtual bool usunZKonca() = 0;
	virtual bool usun(int index) = 0;

	virtual int dajIlosc() const = 0;
	virtual int dajEmenet(int index) const = 0;
	virtual void wypisz() const = 0;


};
