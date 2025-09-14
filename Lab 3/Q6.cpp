#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
        node* down;

        node (int val) {
            data = val;
            next = 0;
            down = 0;
        }
};

node* flatten (node* head) {
    node* curr = head;

    while (curr != 0) {
        if (curr->down != 0) {
            node* child = flatten (curr->down);
            node* nxt = curr->next;

            curr->next = curr->down;
            curr->down = 0;

            while (curr->next != 0) {
                curr = curr->next;
            }

            node* tail = curr;
            tail->next = nxt;
        }
        curr = curr->next;
    }
    return head;
}
