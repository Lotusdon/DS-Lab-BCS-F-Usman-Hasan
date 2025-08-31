#include <iostream>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    int* empCount = new int[departments];
    int** salaries = new int*[departments];

    for (int i = 0; i < departments; i++) {
        cout << "Enter number of employees in Department " << i + 1 << ": ";
        cin >> empCount[i];
        salaries[i] = new int[empCount[i]];

        cout << "Enter salaries for Department " << i + 1 << ":" << endl;
        for (int j = 0; j < empCount[i]; j++) {
            cout << "Employee " << j + 1 << ": ";
            cin >> salaries[i][j];
        }
    }

    cout << endl << "Highest salary in each department " << endl;
    for (int i = 0; i < departments; i++) {
        int maxSalary = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > maxSalary) {
                maxSalary = salaries[i][j];
            }
        }
        cout << "Department " << i + 1 << ": " << maxSalary << endl;
    }

    int bestDept = 0;
    double maxAvg = 0;

    for (int i = 0; i < departments; i++) {
        int sum = 0;
        for (int j = 0; j < empCount[i]; j++) {
            sum += salaries[i][j];
        }
        double avg = static_cast<double>(sum) / empCount[i];
        if (avg > maxAvg) {
            maxAvg = avg;
            bestDept = i;
        }
    }

    cout << endl << "Department with maximum average salary: Department "
         << bestDept + 1 << " (Average = " << maxAvg << ")" << endl;

    for (int i = 0; i < departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;

    return 0;
}
