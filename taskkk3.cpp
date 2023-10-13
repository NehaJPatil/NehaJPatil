#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> studentNames;
    vector<double> studentGrades;
    double grade, total = 0.0, highest = 0.0, lowest = 100.0;

    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    
    for (int i = 0; i < numStudents; ++i) {
        string name;
        cout << "Enter student name: ";
        cin.ignore();  
        getline(cin, name);
        studentNames.push_back(name);

        cout << "Enter grade for " << name << ": ";
        cin >> grade;
        studentGrades.push_back(grade);

        total += grade;

        if (grade > highest) {
            highest = grade;
        }

        if (grade < lowest) {
            lowest = grade;
        }
    }


    double average = total / numStudents;
    cout << "Average Grade: " << average << endl;


    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;

    return 0;
}
 
