#include <iostream>
#include <string>
usingg namespace std;

class node
{
public:
    string key;
    string value;
    node* next;

    node(string k, string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class hashh
{
private:
    int size;
    node** table;

    int hashfunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
            sum += key[i];
        return sum % size;
    }

public:
    hashh(int s = 10)
    {
        size = s;
        table = new node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    void insert(string key, string value)
    {
        int index = hashfunction(key);

        node* cur = table[index];

        while (cur)
        {
            if (cur->key == key)
            {
                cur->value = value;
                cout << "key '" << key << "' updated with value '" << value << "'" << endl;
                return;
            }
            cur = cur->next;
        }

        node* n = new node(key, value);
        n->next = table[index];
        table[index] = n;

        cout << "key '" << key << "' inserted with value '" << value << "'" << endl;
    }

    void remove(string key)
    {
        int index = hashfunction(key);

        node* cur = table[index];
        node* prev = NULL;

        while (cur)
        {
            if (cur->key == key)
            {
                if (prev)
                    prev->next = cur->next;
                else
                    table[index] = cur->next;

                delete cur;
                cout << "key '" << key << "' deleted successfully!" << endl;
                return;
            }
            prev = cur;
            cur = cur->next;
        }

        cout << "key '" << key << "' not found for deletion!" << endl;
    }

    string search(string key)
    {
        int index = hashfunction(key);

        node* cur = table[index];
        while (cur)
        {
            if (cur->key == key)
                return cur->value;
            cur = cur->next;
        }

        return "Not found";
    }

    void display()
    {
        cout << "hash table contents:" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "bucket " << i << ": ";
            node* cur = table[i];

            if (!cur)
            {
                cout << "empty";
            }
            else
            {
                while (cur)
                {
                    cout << "[" << cur->key << ":" << cur->value << "]";
                    if (cur->next)
                        cout << " -> ";
                    cur = cur->next;
                }
            }

            cout << endl;
        }

        cout << endl;
    }

    ~hashh()
    {
        for (int i = 0; i < size; i++)
        {
            node* cur = table[i];
            while (cur)
            {
                node* n = cur->next;
                delete cur;
                cur = n;
            }
        }
        delete[] table;
    }
};

int main()
{
    hashh hashtable;

    hashtable.insert("A", "Apple");
    hashtable.insert("B", "Banana");
    hashtable.insert("C", "Strawberry");
    hashtable.insert("A", "Pomegranate");

    cout << "\nsearch operations:" << endl;
    cout << "search A: " << hashtable.search("A") << endl;
    cout << "search B: " << hashtable.search("B") << endl;
    cout << "search X: " << hashtable.search("X") << endl;

    cout << "\nhash table:" << endl;
    hashtable.display();

    cout << "delete operations:" << endl;
    hashtable.remove("B");
    hashtable.remove("X");

    cout << "\nafter deleting:" << endl;
    hashtable.display();

    hashtable.insert("D", "Melon");
    hashtable.insert("E", "Mango");

    cout << "final:" << endl;
    hashtable.display();

    return 0;
}
