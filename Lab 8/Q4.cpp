#include <iostream>
using namespace std;

class treenode
{
public:
    int data;
    treenode* left;
    treenode* right;

    treenode(int d) : data(d), left(NULL), right(NULL) {}
};


class binarysearchtree
{
    treenode* root;


    treenode* findmin(treenode* t)
    {
        while(t && t->left)
            t = t->left;

        return t;
    }


    treenode* insertnode(treenode* t, int v)
    {
        if(!t)
            return new treenode(v);

        if(v < t->data)
            t->left = insertnode(t->left, v);

        else if(v > t->data)
            t->right = insertnode(t->right, v);

        return t;
    }


    treenode* searchnode(treenode* t, int key)
    {
        if(!t)
            return NULL;

        if(t->data == key)
            return t;

        if(key < t->data)
            return searchnode(t->left, key);

        return searchnode(t->right, key);
    }


    treenode* deletenode(treenode* t, int key)
    {
        if(!t)
            return NULL;

        if(key < t->data)
            t->left = deletenode(t->left, key);

        else if(key > t->data)
            t->right = deletenode(t->right, key);

        else
        {
            if(!t->left)
            {
                treenode* temp = t->right;
                delete t;
                return temp;
            }

            if(!t->right)
            {
                treenode* temp = t->left;
                delete t;
                return temp;
            }

            treenode* m = findmin(t->right);
            t->data = m->data;
            t->right = deletenode(t->right, m->data);
        }

        return t;
    }


    void inorder(treenode* t)
    {
        if(!t)
            return;

        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }


    void preorder(treenode* t)
    {
        if(!t)
            return;

        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }


    void postorder(treenode* t)
    {
        if(!t)
            return;

        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }


public:

    binarysearchtree() : root(NULL) {}


    void constructbst(int a[], int n)
    {
        root = NULL;

        for(int i = 0; i < n; i++)
            root = insertnode(root, a[i]);
    }


    void insert(int v)
    {
        root = insertnode(root, v);
    }


    treenode* search(int v)
    {
        return searchnode(root, v);
    }


    void remove(int v)
    {
        root = deletenode(root, v);
    }


    void inorderprint()
    {
        inorder(root);
    }

    void preorderprint()
    {
        preorder(root);
    }

    void postorderprint()
    {
        postorder(root);
    }

    treenode* getroot()
    {
        return root;
    }
};


int main()
{
    int arr[50];
    int n;

    cout << "enter number of elements: ";
    cin >> n;

    cout << "enter numbers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    binarysearchtree bst;
    bst.constructbst(arr, n);

    cout << endl << "preorder: ";
    bst.preorderprint();

    cout << endl << "postorder: ";
    bst.postorderprint();

    cout << endl << "inorder: ";
    bst.inorderprint();


    int value;
    cout << endl << "enter value to search: ";
    cin >> value;

    treenode* f = bst.search(value);

    if(f)
    {
        cout << "value found";
    }
    else
    {
        cout << "value not found... inserting value\n";
        bst.insert(value);

        cout << "new inorder: ";
        bst.inorderprint();
    }

    return 0;
}
