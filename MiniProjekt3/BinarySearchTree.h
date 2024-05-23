#pragma once
struct TreeItem
{
    TreeItem* parent;
    TreeItem* leftChild;
    TreeItem* rightChild;
    int key;
    int value;
};

class BinarySearchTree
{
private:
    TreeItem* korzen;
    int count;
    BinarySearchTree();
public:
    void Add(int key, int value);
    TreeItem* find(int key);
    bool remove(int key);

private:
    int Add(TreeItem* root, TreeItem* item, int layer);
    TreeItem* CreateItem(TreeItem* parent, int key, int value);
    TreeItem* find(TreeItem* korzen, int key);
    bool remove(TreeItem* element);
    TreeItem* findMinItem(TreeItem* root);
    int getMinDeep();


    void rozplaczDrzewo();
    void zaplaczDrzewo();

    TreeItem* rightRotation(TreeItem* A);
    TreeItem* leftRotation(TreeItem* A);
    int iloscObrotow(int n);
};
