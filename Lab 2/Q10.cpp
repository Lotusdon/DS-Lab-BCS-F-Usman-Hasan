#include <iostream>
using namespace std;

int main() {
    int categories;
    cout << "Enter number of categories: ";
    cin >> categories;

    int* booksInCategory = new int[categories];
    int** library = new int*[categories];

    for (int i = 0; i < categories; i++) {
        cout << "Enter number of books in category " << i + 1 << ": ";
        cin >> booksInCategory[i];

        library[i] = new int[booksInCategory[i]];

        cout << "Enter book IDs for category " << i + 1 << ":" << endl;
        for (int j = 0; j < booksInCategory[i]; j++) {
            cin >> library[i][j];
        }
    }

    int searchID;
    cout << endl << "Enter book ID to search: ";
    cin >> searchID;

    bool found = false;
    int categoryFound = -1;

    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < booksInCategory[i]; j++) {
            if (library[i][j] == searchID) {
                found = true;
                categoryFound = i;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "Book ID " << searchID 
             << " is available in category " << categoryFound + 1 << "." << endl;
    } else {
        cout << "Book ID " << searchID << " is not available in the library." << endl;
    }

    for (int i = 0; i < categories; i++) {
        delete[] library[i];
    }
    delete[] library;
    delete[] booksInCategory;

    return 0;
}
