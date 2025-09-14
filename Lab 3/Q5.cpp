#include <iostream>
using namespace std;

class node {
    public:   
        int data;
        node* next;

        node (int d) {
            data = d;
            next = 0;
        }
};

class dnode {
    public:
        int data;
        dnode* next;
        dnode* prev;

        dnode (int d, dnode* n = 0, dnode* p = 0) {
            data = d;
            next = n;
            prev = p;
        }
};

dnode* to_doubly (node* head) {
    if (!head) {
        return 0;
    }

    dnode* head2 = new dnode (head->data, 0, 0);
    dnode* tail = head2;
    node* curr = head->next;

    while (curr != 0) {
        dnode* nd = new dnode (curr->data, 0, tail);
        tail->next = nd;
        tail = nd;
        curr = curr->next;
    }
    return head2;
}

node* to_circular (node* head) {
    node* curr = head;

    while (curr->next != 0) {
        curr = curr->next;
    }

    curr->next = head;
    return head;
}

void print_circular (node* head, int times) {
    node* curr = head;
    int cnt = 0;

    while (cnt < times) {
        cout << "val = " << curr->data << " ";
        curr = curr->next;
        cnt++;
    }
    cout << endl;
}
