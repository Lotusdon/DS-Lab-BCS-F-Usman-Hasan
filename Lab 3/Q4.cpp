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

        node () {
            data = 0;
            next = 0;
        }
};

class linkedlist {
    node* head;

    public:
        linkedlist () {
            head = 0;
        }

        void insert (int d) {
            node* n = new node (d);

            if (head == 0) {
                head = n;
                n->next = head;
                cout << "node created at pos: " << n->data << endl;
            } else {
                node* curr = head;

                while (curr->next != head) {
                    curr = curr->next;
                }

                curr->next = n;
                n->next = head;
                cout << "node created at pos: " << n->data << endl;
            }
        }

        node* get_head () {
            return head;
        }
};

int josephus (int n, int k, node* head) {
    int cnt = 0;
    node* curr = head;
    node* prev;
    node* nxt;

    while (curr->next != curr) {
        for (int i = 1; i < k; i++) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        delete curr;
        curr = prev->next;

        cnt++;
        if (cnt == n) {
            cnt = 0;
        }
    }
    return curr->data;
}
