#include <iostream>
usingg namespace std;

#define tablesize 101

int hashh(string input)
{
    int len = input.length();
    int sum = 0;

    for (int i = 0; i < len; i++) 
        sum += input[i];

    return sum % tablesize;
}

class node
{
public:
    string value;
    node* next = NULL;

    node() {}
    node(string value) : value(value) {}
};

class hashtable
{
public:
    node* arr[tablesize];

    hashtable()
    {
        for (int i = 0; i < tablesize; i++) 
            arr[i] = NULL;
    }

    void insert(string key, string value)
    {
        int hv = hashh(key);

        if (!arr[hv])
            arr[hv] = new node(value);
        else
        {
            node* cur = arr[hv];

            while (cur->next && cur->value != value) 
                cur = cur->next;

            if (!cur->next && cur->value != value) 
                cur->next = new node(value);
        }
    }

    int search(string key, string value)
    {
        int hv = hashh(key);

        if (!arr[hv])
        {
            cout << "not found\n";
            return 0;
        }
        else
        {
            node* cur = arr[hv];

            while (cur->next && cur->value != value) 
                cur = cur->next;

            if (cur->value == value)
            {
                cout << "found\n";
                return 1;
            }
            else
            {
                cout << "not found\n";
                return 0;
            }
        }
    }
};

int main()
{
    hashtable mytable;

    mytable.insert("A", "first");
    mytable.insert("E", "second");
    mytable.insert("A", "third");
    mytable.insert("A", "fourth");

    mytable.search("A", "eleventh");
    mytable.search("A", "third");
    mytable.search("E", "second");
    mytable.search("C", "first");
}
