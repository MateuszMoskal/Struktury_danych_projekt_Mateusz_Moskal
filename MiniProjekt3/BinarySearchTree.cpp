#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    korzen = nullptr;
    count = 0;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
    :BinarySearchTree()
{
    copyTree(this, tree.korzen);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& tree)
{
    BinarySearchTree::~BinarySearchTree();
    copyTree(this, tree.korzen);
    return *this;
}

BinarySearchTree::~BinarySearchTree()
{
    deleteItem(korzen);
    korzen = nullptr;
    count = 0;
}

void BinarySearchTree::AddOrUpdate(int key, int value)
{

    TreeItem* item = CreateItem(nullptr, key, value);
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


TreeItem* BinarySearchTree::findItem(int key)
{
    return find(korzen, key);
}
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
    else //update
    {
        korzen->value = item->value;
        delete item;
    }
}


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
    else if (element->leftChild != nullptr && element->rightChild != nullptr) //mamy 2 dzieci
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
    int rotations = iloscObrotow(count + 1) - 1;
    TreeItem* element = korzen;
    for (int i = 0; i < (count - rotations); i++)
    {
        if (element != nullptr && element->rightChild != nullptr) {
            leftRotation(element);
            element = element->parent;
            element = element->rightChild;
        }
    }
    element = korzen;
    while (rotations > 1)
    {
        rotations = rotations / 2;
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

TreeItem* BinarySearchTree::rightRotation(TreeItem* A)
{
    TreeItem* B = A->leftChild;
    if (B == nullptr)
    {
        return A;
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
TreeItem* BinarySearchTree::leftRotation(TreeItem* A) {
    TreeItem* B = A->rightChild;
    if (B == nullptr)
    {
        return A;
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


int BinarySearchTree::getMinDeep()
{
    int layers = 0;
    int countElements = count;
    while (countElements > 0)
    {
        layers++;
        countElements = countElements / 2;
    }
    return layers;


}


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

void BinarySearchTree::deleteItem(TreeItem* item)
{
    if (item == nullptr)
    {
        return;
    }
    deleteItem(item->leftChild);
    deleteItem(item->rightChild);
    delete item;
}

void BinarySearchTree::copyTree(BinarySearchTree* tree, TreeItem* target)
{
    if (target == nullptr)
    {
        return;
    }
    tree->AddOrUpdate(target->key, target->value);
    copyTree(tree, target->leftChild);
    copyTree(tree, target->rightChild);
}