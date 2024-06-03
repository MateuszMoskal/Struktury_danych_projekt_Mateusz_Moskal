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
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& tree);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& tree);
    void AddOrUpdate(int key, int value);
    TreeItem* findItem(int key);
    bool remove(int key);

private:
    int AddOrUpdate(TreeItem* root, TreeItem* item, int layer);
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

    void deleteItem(TreeItem* item);
    void copyTree(BinarySearchTree* tree, TreeItem* target);
};