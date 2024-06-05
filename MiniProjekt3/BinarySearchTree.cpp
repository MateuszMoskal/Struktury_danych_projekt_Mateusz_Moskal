#include "BinarySearchTree.h"

// Tutaj tworze puste drzewo 
BinarySearchTree::BinarySearchTree()
{
    korzen = nullptr; // korzen narazie jest nullem bo go fizycznie nie ma 
    count = 0; // ustawiam liczbe elementow na zero 
}

// konstruktor tworzy nowe drzewo jako kopiê istniejacego drzewa 
BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
    :BinarySearchTree() // puste drzewo 
{
    copyTree(this, tree.korzen); // kopiuje elementy 
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& tree)
{
    BinarySearchTree::~BinarySearchTree(); // usuwam bie¿ace drzewo 
    copyTree(this, tree.korzen); // kopiuje elementy 
    return *this;
}

BinarySearchTree::~BinarySearchTree()
{
    deleteItem(korzen); // usuwa wszystkie elementy 
    korzen = nullptr;
    count = 0; // resetuje liczbe elementow 
}

void BinarySearchTree::AddOrUpdate(int key, int value)
{

    TreeItem* item = CreateItem(nullptr, key, value); // tworzenie nowego elementu 
    count++;
    if (korzen == nullptr)
    {
        korzen = item;
    }
    else
    {
        if (AddOrUpdate(korzen, item, 1) != getMinDeep())
        {
            //wywazanie drzewa
            rozplaczDrzewo();
            zaplaczDrzewo();
        }
    }
}

// Znajduje element o okreslonym kluczu 
TreeItem* BinarySearchTree::findItem(int key)
{
    return find(korzen, key);
}
// usuwam element o okreslonym kluczu 
bool BinarySearchTree::remove(int key)
{
    TreeItem* element = findItem(key);

    if (element == nullptr)
    {
        return false;
    }
    return remove(element);
}

int BinarySearchTree::AddOrUpdate(TreeItem* korzen, TreeItem* item, int layer)
{

    if (item->key < korzen->key)
    // idê do lewego poddrzewa 
    {
        if (korzen->leftChild == nullptr)
        {
            korzen->leftChild = item;
            item->parent = korzen;
            return layer;
        }
        else
        {
            return AddOrUpdate(korzen->leftChild, item, layer + 1);
        }
    }
    else if (item->key > korzen->key)
    // idê do prawego poddrzewa
    {
        if (korzen->rightChild == nullptr)
        {
            korzen->rightChild = item;
            item->parent = korzen;
            return layer;
        }
        else
        {
            return AddOrUpdate(korzen->rightChild, item, layer + 1);
        }
    }
    else // aktualizuje istniejacy element 
    {
        korzen->value = item->value;
        delete item;
    }
}

// wyszukiwanie elementu o okreslonym kluczu 
TreeItem* BinarySearchTree::find(TreeItem* root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->key == key)
    {
        return root;
    }
    else if (key < root->key)
    {
        return find(root->leftChild, key);
    }
    else
    {
        return find(root->rightChild, key);
    }
}

// usuwam element z drzewa 
bool BinarySearchTree::remove(TreeItem* element)
{
    if (element->leftChild == nullptr && element->rightChild == nullptr) //nie ma dzieci
    {
        TreeItem* rodzic = element->parent;
        if (rodzic != nullptr)
        {
            if (element->key < rodzic->key) //to znaczy ze element jest lewym dzieckiem
            {
                rodzic->leftChild = nullptr;
            }
            else // element jest prawym dzieckiem
            {
                rodzic->rightChild = nullptr;
            }
        }
        else
        {
            korzen = nullptr;
        }
        delete element;
    }
    else if (element->leftChild != nullptr && element->rightChild != nullptr) //mamy dwojke dzieci
    {
        //szukamu successora czyli najbli¿szy wiekszy element (nie koniecznie prawe dziecko)
        TreeItem* successor = findMinItem(element->rightChild);
        element->key = successor->key;
        element->value = successor->value;
        remove(successor);
    }
    else  //mamy tylko jedno dziecko
    {
        TreeItem* rodzic = element->parent;
        TreeItem* dziecko = element->leftChild;
        if (dziecko == nullptr)
        {
            dziecko = element->rightChild;
        }

        if (rodzic != nullptr)
        {
            if (element->key < rodzic->key) //to znaczy ze element jest lewym dzieckiem
            {
                rodzic->leftChild = dziecko;
            }
            else // element jest prawym dzieckiem
            {
                rodzic->rightChild = dziecko;
            }
            dziecko->parent = rodzic;
        }
        else
        {
            korzen = dziecko;
            korzen->parent = nullptr;
        }

    }

    return true;
}

// tworzenie nowego elementu do drzewa 
TreeItem* BinarySearchTree::CreateItem(TreeItem* parent, int key, int value)
{
    TreeItem* item = new TreeItem;
    item->parent = parent;
    item->leftChild = nullptr;
    item->rightChild = nullptr;
    item->key = key;
    item->value = value;
    return item;
}


// Znajduje namniejszy element w poddrzewie 
TreeItem* BinarySearchTree::findMinItem(TreeItem* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->leftChild != nullptr)
    {
        return findMinItem(root->leftChild);
    }
    else
    {
        return root;
    }
}

// procedura wywazenia drzewa 
void BinarySearchTree::rozplaczDrzewo()
{
    TreeItem* element = korzen;
    while (element != nullptr)
    {
        if (element->leftChild != nullptr)
        {
            rightRotation(element);
            element = element->parent;
            if (element->parent != nullptr)
            {
                element = element->parent;
            }
        }
        else
        {
            element = element->rightChild;
        }
    }
}

void BinarySearchTree::zaplaczDrzewo()
{
    // liczenie liczby obrotow 
    int rotations = iloscObrotow(count + 1) - 1;
    TreeItem* element = korzen; // rozpoczynamy od korzenia 
    for (int i = 0; i < (count - rotations); i++) // lewe rotacje az do wywazenia drzewa
    {
        if (element != nullptr && element->rightChild != nullptr) {
            leftRotation(element); // lewa rotacja 
            element = element->parent;
            element = element->rightChild;
        }
    }
    element = korzen;
    while (rotations > 1)
    {
        rotations = rotations / 2; // dziele liczbe obrotow na pol 
        element = korzen;
        for (int i = 0; i < rotations; i++)
        {
            if (element != nullptr && element->rightChild != nullptr) {
                leftRotation(element);
                element = element->parent;
                element = element->rightChild;
            }
        }
    }

    element = korzen;
}

// Funkcja do wykonywania rotacji w prawo 
TreeItem* BinarySearchTree::rightRotation(TreeItem* A)
{
    TreeItem* B = A->leftChild;
    if (B == nullptr)
    {
        return A; // sprawdzam czy istnieje lewe dziecko 
    }
    TreeItem* p = A->parent;
    A->leftChild = B->rightChild;
    if (A->leftChild != nullptr)
    {
        A->leftChild->parent = A;
    }
    B->rightChild = A;
    B->parent = p;
    A->parent = B;
    if (p == nullptr)
    {
        korzen = B;
    }
    else
    {
        if (p->leftChild == A)
        {
            p->leftChild = B;
        }
        else
        {
            p->rightChild = B;
        }
    }

    return  B;
}

// Funkcja wykonujaca rotacje w lewo 
TreeItem* BinarySearchTree::leftRotation(TreeItem* A) {
    TreeItem* B = A->rightChild;
    if (B == nullptr)
    {
        return A; // sprawdzamy czy istnieje prawe dziecko 
    }
    TreeItem* p = A->parent;
    A->rightChild = B->leftChild;
    if (A->rightChild != nullptr)
    {
        A->rightChild->parent = A;
    }
    B->leftChild = A;
    B->parent = p;
    A->parent = B;
    if (p == nullptr)
    {
        korzen = B;
    }
    else
    {
        if (p->leftChild == A)
        {
            p->leftChild = B;
        }
        else
        {
            p->rightChild = B;
        }
    }
    return B;
}

// Obliczam minimalna glebokosc drzewa 
int BinarySearchTree::getMinDeep()
{
    int layers = 0; // licznik warstw 
    int countElements = count;
    // obliczam liczbe warstw 
    while (countElements > 0)
    {
        layers++; // zwieksz licznik warstw
        countElements = countElements / 2;
    }
    return layers; // minimalna glebokosc drzewa


}

// Funkcja oblicza liczbe obrotow do wywazenia 
int BinarySearchTree::iloscObrotow(int n)
{
    int potega = 1;
    int wynik = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            wynik = potega;
        }
        n = n / 2;
        potega = potega * 2;
    }

    return wynik;
}

// Funkcja do usuwania elementow z drzewa 
void BinarySearchTree::deleteItem(TreeItem* item)
{
    if (item == nullptr)
    {
        return;
    }
    deleteItem(item->leftChild); // usun lewe dziecko 
    deleteItem(item->rightChild); // usun prawe dziecko 
    delete item; // usun element 
}

// funkcja do kopiowania drzewa 
void BinarySearchTree::copyTree(BinarySearchTree* tree, TreeItem* target)
{
    if (target == nullptr)
    {
        return;
    }
    tree->AddOrUpdate(target->key, target->value); // dodawanie i aktualizowanie elementu 
    copyTree(tree, target->leftChild); // kopiowanie lewego dziecka 
    copyTree(tree, target->rightChild); // kopiowanie prawego dziecka 
}