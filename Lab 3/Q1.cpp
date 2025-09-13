#include <iostream>
using namespace std;

class node {
public:
    int value;
    node *next;

    node() {
        value = 0;
        next = NULL;
    }

    node(int val) {
        value = val;
        next = NULL;
    }
};

bool ispalindrome(node *head) {
    if (!head || !head->next) 
        return true;

    node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *curr = slow, *prev = NULL, *nxt = NULL;
    while (curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    node *p = head, *q = prev;
    while (p && q) {
        if (p->value != q->value) 
            return false;
        p = p->next;
        q = q->next;
    }

    return true;
}
