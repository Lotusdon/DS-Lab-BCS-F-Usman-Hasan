#include <iostream>
using namespace std;

struct avlnode
{
    int value;
    avlnode *leftchild;
    avlnode *rightchild;
    int h;

    avlnode(int v)
    {
        value = v;
        leftchild = nullptr;
        rightchild = nullptr;
        h = 1;
    }
};

int getheight(avlnode *n)
{
    if(n == nullptr) return 0;
    return n->h;
}

void refresh(avlnode *n)
{
    int lh = getheight(n->leftchild);
    int rh = getheight(n->rightchild);

    if(lh > rh)
        n->h = lh + 1;
    else
        n->h = rh + 1;
}

int getbf(avlnode *n)
{
    return getheight(n->leftchild) - getheight(n->rightchild);
}

avlnode* rotateright(avlnode *y)
{
    avlnode *x = y->leftchild;
    avlnode *t = x->rightchild;

    x->rightchild = y;
    y->leftchild = t;

    refresh(y);
    refresh(x);

    return x;
}

avlnode* rotateleft(avlnode *x)
{
    avlnode *y = x->rightchild;
    avlnode *t = y->leftchild;

    y->leftchild = x;
    x->rightchild = t;

    refresh(x);
    refresh(y);

    return y;
}

avlnode* insertnode(avlnode *root, int v)
{
    if(root == nullptr)
        return new avlnode(v);

    if(v < root->value)
        root->leftchild = insertnode(root->leftchild, v);

    else if(v > root->value)
        root->rightchild = insertnode(root->rightchild, v);

    else
        return root;

    refresh(root);

    int bf = getbf(root);

    if(bf > 1 && v < root->leftchild->value)
        return rotateright(root);

    if(bf < -1 && v > root->rightchild->value)
        return rotateleft(root);

    if(bf > 1 && v > root->leftchild->value)
    {
        root->leftchild = rotateleft(root->leftchild);
        return rotateright(root);
    }

    if(bf < -1 && v < root->rightchild->value)
    {
        root->rightchild = rotateright(root->rightchild);
        return rotateleft(root);
    }

    return root;
}

void findksmall(avlnode *root, int &k, int &ans)
{
    if(root == nullptr) return;

    findksmall(root->leftchild, k, ans);

    if(--k == 0)
    {
        ans = root->value;
        return;
    }

    findksmall(root->rightchild, k, ans);
}

void findklarge(avlnode *root, int &k, int &ans)
{
    if(root == nullptr) return;

    findklarge(root->rightchild, k, ans);

    if(--k == 0)
    {
        ans = root->value;
        return;
    }

    findklarge(root->leftchild, k, ans);
}

int main()
{
    avlnode *root = nullptr;

    int data[] = {30, 15, 45, 10, 20, 40, 50, 18};
    int size = 8;

    for(int i = 0; i < size; i++)
        root = insertnode(root, data[i]);

    int ksmall = 3, klarge = 2;
    int smallest = -1, largest = -1;

    findksmall(root, ksmall, smallest);
    findklarge(root, klarge, largest);

    cout << "3rd smallest = " << smallest << endl;
    cout << "2nd largest = " << largest << endl;

    cout << "height left = " << getheight(root->leftchild) << endl;
    cout << "height right = " << getheight(root->rightchild) << endl;

    return 0;
}
