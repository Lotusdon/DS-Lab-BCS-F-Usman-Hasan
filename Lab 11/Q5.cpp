#include <iostream>
#include <string>
using namespace std;

class studenthashtable
{
private:
    static const int table_size = 15;

    struct student
    {
        int rollnumber;
        string name;
        bool occupied;

        student() : rollnumber(-1), occupied(false) {}
    };

    student table[table_size];

    int hashfunc(int roll)
    {
        return roll % table_size;
    }

public:
    studenthashtable()
    {
        for(int i = 0; i < table_size; i++)
            table[i] = student();
    }

    void insertrecord(int roll, string name)
    {
        int idx = hashfunc(roll);
        int attempt = 0;

        while(attempt < table_size)
        {
            int cur = (idx + attempt * attempt) % table_size;

            if(!table[cur].occupied)
            {
                table[cur].rollnumber = roll;
                table[cur].name = name;
                table[cur].occupied = true;

                cout << "record inserted at index " << cur << endl;
                return;
            }

            attempt++;
        }

        cout << "hash table full" << endl;
    }

    void searchrecord(int roll)
    {
        int idx = hashfunc(roll);
        int attempt = 0;

        while(attempt < table_size)
        {
            int cur = (idx + attempt * attempt) % table_size;

            if(table[cur].occupied && table[cur].rollnumber == roll)
            {
                cout << "record found: " << table[cur].name << endl;
                return;
            }

            if(!table[cur].occupied)
                break;

            attempt++;
        }

        cout << "record not found" << endl;
    }

    void displaytable()
    {
        cout << "hash table contents:" << endl;

        for(int i = 0; i < table_size; i++)
        {
            cout << "index " << i << ": ";

            if(table[i].occupied)
                cout << "roll: " << table[i].rollnumber << ", name: " << table[i].name;
            else
                cout << "empty";

            cout << endl;
        }
    }
};

int main()
{
    studenthashtable t;

    t.insertrecord(101, "Murtaza");
    t.insertrecord(102, "Adnan");
    t.insertrecord(116, "Turab");
    t.insertrecord(131, "Rayyan");
    t.insertrecord(103, "Zain");

    cout << endl << "search operations:" << endl;
    t.searchrecord(101);
    t.searchrecord(116);
    t.searchrecord(999);

    cout << endl << "hash table:" << endl;
    t.displaytable();

    cout << endl << "collision with quadratic probing:" << endl;
    t.insertrecord(101 + 15, "Arham");
    t.insertrecord(101 + 30, "Usman");

    cout << endl << "final:" << endl;
    t.displaytable();

    return 0;
}
