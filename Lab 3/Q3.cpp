#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;

        node (int val) {
            data = val;
            next = 0;
        }
};

node* reverse (node* head) {
    node* curr = head;
    node* prev = 0;
    node* nxt = 0;

    while (curr != 0) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

node* get_kth (node* head, int k) {
    int cnt = k - 1;

    while (head != 0 && cnt > 0) {
        head = head->next;
        cnt--;
    }
    return head;
}

node* reverse_groups (node* head, int k) {
    node* curr = head;
    node* kth = curr;
    node* last = 0;

    while (curr != 0) {
        kth = get_kth (curr, k);

        if (kth == 0) {
            if (last) {
                last->next = curr;
            }
            break;
        }

        node* nxt = kth->next;
        kth->next = 0;

        node* newhead = reverse (curr);

        if (curr == head) {
            head = newhead;
        } else {
            last->next = newhead;
        }

        last = curr;
        curr = nxt;
    }
    return head;
}
