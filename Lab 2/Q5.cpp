#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    double** A = new double*[rows];
    double** B = new double*[rows];
    double** Add = new double*[rows];
    double** Sub = new double*[rows];

    for (int i = 0; i < rows; i++) {
        A[i] = new double[cols];
        B[i] = new double[cols];
        Add[i] = new double[cols];
        Sub[i] = new double[cols];
    }

    cout << endl << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << endl << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Add[i][j] = A[i][j] + B[i][j];
            Sub[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << endl << "Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << A[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << B[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Addition (A + B):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << Add[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Subtraction (A - B):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << Sub[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] Add[i];
        delete[] Sub[i];
    }

    delete[] A;
    delete[] B;
    delete[] Add;
    delete[] Sub;

    return 0;
}
