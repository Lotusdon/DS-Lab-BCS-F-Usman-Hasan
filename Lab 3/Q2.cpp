#include <iostream>
using namespace std;

class node {
public:
    int val;
    node *next;

    node() {
        val = 0;
        next = NULL;
    }

    node(int x) {
        val = x;
        next = NULL;
    }
};

node* mergesortedlists(node *list1, node *list2) {
    if (!list1) 
        return list2; 
    if (!list2) 
        return list1;
    
    node *merged = NULL, *tail = NULL;

    if (list1->val < list2->val) {
        merged = tail = list1;
        list1 = list1->next;
    } 
    else {
        merged = tail = list2;
        list2 = list2->next;
    }

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        } 
        else {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }        
    }

    if (list1) 
        tail->next = list1;
    if (list2) 
        tail->next = list2;

    return merged;
}
