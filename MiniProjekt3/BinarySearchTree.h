#pragma once
struct TreeItem
{
    TreeItem* parent; // wskaünik na rodzica elementu 
    TreeItem* leftChild; // wskaznik na lewe dzeicko elementu
    TreeItem* rightChild; // wskaznik na prawe dziecko elementu 
    int key; // klucz danego elementu 
    int value; // wartosc danego elementu 
};

class BinarySearchTree
{
private:
    TreeItem* korzen; // wskaxnik na korzen drzewa
    int count; // licznik elementow 
public:
    BinarySearchTree(); // konstruktor domyslny 
    BinarySearchTree(const BinarySearchTree& tree); // konstruktor kopiujacy 
    ~BinarySearchTree(); // destruktor 
    BinarySearchTree& operator=(const BinarySearchTree& tree); // operator przypisania 
    void AddOrUpdate(int key, int value); // dodanie nowego elementu lub zaktualizowanie jego wartosci 
    TreeItem* findItem(int key); // znalezienie elementu o podanym kluczu 
    bool remove(int key); // usuniecie elementu o podanym kluczu

private:
    int AddOrUpdate(TreeItem* root, TreeItem* item, int layer);
    TreeItem* CreateItem(TreeItem* parent, int key, int value); // tworzenie nowego elementu 
    TreeItem* find(TreeItem* korzen, int key); // znajdowanie elementu o podanym kluczu
    bool remove(TreeItem* element);
    TreeItem* findMinItem(TreeItem* root); // znajdowanie elementu z minimalnym kluczem
    int getMinDeep(); // zwraca minimalna glebokosc drzewa 


    void rozplaczDrzewo();
    void zaplaczDrzewo();

    TreeItem* rightRotation(TreeItem* A); // rotacja drzewa w prawo
    TreeItem* leftRotation(TreeItem* A); // rotacja drzewa w lewo 
    int iloscObrotow(int n); // liczba obrotow 

    void deleteItem(TreeItem* item); // usuniecie elementu 
    void copyTree(BinarySearchTree* tree, TreeItem* target); // skopiowanie drzewa
};