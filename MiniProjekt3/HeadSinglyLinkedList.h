#pragma once
struct ItemList
{
	int key;
	int value;
	ItemList* nast;
};

class HeadSinglyLinkedList
{
private:
	ItemList* head;
	int count;
public:
	HeadSinglyLinkedList();
	HeadSinglyLinkedList(const HeadSinglyLinkedList& list);
	~HeadSinglyLinkedList();
	HeadSinglyLinkedList& operator=(const HeadSinglyLinkedList& list);

	void wyczysc();

	void addOrUpdate(int key, int value);
	bool remove(int key);
	int dajIlosc() const;
	void wypisz() const;
	ItemList* findItem(int key) const;
private:
	bool removeFromBegin();
	ItemList* findItemBefore(int key) const;

	void copy(const HeadSinglyLinkedList& list);
};