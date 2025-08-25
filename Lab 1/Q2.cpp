#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char *studentName;
    char *examDate;
    int score;

public:
   Exam(){
        studentName = NULL;
        examDate = NULL;
        score = 0;
    }

    Exam(const char *name, const char *date, int marks) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = marks;
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    void setExamDetails(const char *name, const char *date, int marks) {
        strcpy(studentName, name);
        strcpy(examDate, date);
        score = marks;
    }

    void display() {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam exam1;
    cout << "Details of Exam 1:" << endl;
    exam1.display();

    Exam exam2("Usman", "2025-08-25", 85);
    cout << "\nDetails of Exam 2:" << endl;
    exam2.display();

    Exam exam3 = exam2;
    cout << "\nDetails of Exam 3 :" << endl;
    exam3.display();

    return 0;
}
