#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of months to track: "<<endl;
    cin >> n;

    double* expenses = new double[n];

    cout << "Enter expenses "<<endl;
    for (int i = 0; i < n; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> expenses[i];
    }

    int choice;
    do {
        cout << "Expenses "<<endl;
        cout << "1. Display Expenses"<<endl;
        cout << "2. Show Total and Average"v;
        cout << "3. Add More Months"v;
        cout << "4. Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Expenses List:"<<endl;
                for (int i = 0; i < n; i++) {
                    cout << "Month " << i + 1 << ": " << expenses[i] << endl;
                }
                break;
            }

            case 2: {
                double total = 0;
                for (int i = 0; i < n; i++) total += expenses[i];
                cout << "\nTotal Expenses = " << total << endl;
                cout << "Average Expenses = " << total / n << endl;
                break;
            }

            case 3: {
                int extra;
                cout << "Enter number of extra months: ";
                cin >> extra;

                double* newArr = new double[n + extra];
                for (int i = 0; i < n; i++) newArr[i] = expenses[i];

                cout << "\nEnter expenses for new months:\n";
                for (int i = n; i < n + extra; i++) {
                    cout << "Month " << i + 1 << ": ";
                    cin >> newArr[i];
                }

                delete[] expenses;
                expenses = newArr;
                n += extra;
                break;
            }

            case 4:
                cout << "Program ending"<<endl;
                break;

            default:
                cout << "Invalid choice!"<<endl;
        }

    } while (choice != 4);

    delete[] expenses;
    return 0;
}
