#include <iostream>
using namespace std;

int main() {
    int days, times;

    cout << "Enter total days: ";
    cin >> days;

    cout << "Enter number of readings per day: ";
    cin >> times;

    int** temps = new int*[days];
    for (int i = 0; i < days; i++) {
        temps[i] = new int[times];
    }

    int* avg = new int[days];

    for (int d = 0; d < days; d++) {
        cout << "Day " << d + 1 << " readings:" << endl;
        for (int t = 0; t < times; t++) {
            cout << "  Reading " << t + 1 << ": ";
            cin >> temps[d][t];
        }
    }

    for (int d = 0; d < days; d++) {
        int sum = 0;
        for (int t = 0; t < times; t++) {
            sum += temps[d][t];
        }
        avg[d] = sum / times;
    }

    int hottest = 0, coldest = 0;
    for (int d = 1; d < days; d++) {
        if (avg[d] > avg[hottest]) hottest = d;
        if (avg[d] < avg[coldest]) coldest = d;
    }

    cout << endl << "Daily average temperatures:" << endl;
    for (int d = 0; d < days; d++) {
        cout << "Day " << d + 1 << ": " << avg[d] << endl;
    }

    cout << endl << "Hottest day: Day " << hottest + 1 << " (Avg: " << avg[hottest] << ")" << endl;
    cout << "Coldest day: Day " << coldest + 1 << " (Avg: " << avg[coldest] << ")" << endl;

    for (int i = 0; i < days; i++) {
        delete[] temps[i];
    }
    delete[] temps;
    delete[] avg;

    return 0;
}
