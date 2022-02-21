#include <iostream>
#include <vector>
#include <iomanip>
#include "Validator.h"
#include "Calculator.h"

using namespace std;

void printResult(vector<vector<string>> results) {
    cout << endl;
    cout << setw(11) << "Vardas";
    cout << setw(11) << "Pavarde";
    cout << setw(10) << "Vidurkis";
    cout << setw(10) << "Mediana";
    cout << endl;
    cout << fixed << showpoint;
    setprecision(4);
    for (auto x: results) {
        cout << setw(11) << x.at(0);
        cout << setw(11) << x.at(1);
        cout << setw(10) << x.at(2);
        cout << setw(10) << x.at(3) << std::endl;
        cout << endl;
    }
}

int main() {
    vector<vector<string>> results;
    int numberOfStudents;
    cout << "Iveskite studentu kieki: ", cin >> numberOfStudents;
    for (int y = 0; y < numberOfStudents; y++) {
        string firstName;
        cout << "Iveskite studento varda: ", cin >> firstName;
        string lastName;
        cout << "Iveskite studento pavarde: ", cin >> lastName;
        int numberOfHomeWorks;
        cout << "Iveskite namu darbu pazymiu skaiciu: ", cin >> numberOfHomeWorks;

        vector<int> gradesOfHomeWorks;
        for (int i = 1; i <= numberOfHomeWorks; i++) {
            int homeWorkGrade;
            cout << ("Iveskite nr. " + to_string(i) + " namu darbu pazymi (jeigu norite sustabdyti ivedima, iveskite 0): ");
            homeWorkGrade = validateGradeInput(homeWorkGrade);
            if (homeWorkGrade == 0) {
                break;
            }
            gradesOfHomeWorks.push_back(homeWorkGrade);
        }

        int examGrade;
        cout << "Iveskite egzamino pazymi: ", cin >> examGrade;

        double gradeAverage = Calculator::calculateAverage(gradesOfHomeWorks);
        int median = Calculator::calculateMedian(gradesOfHomeWorks);
        gradeAverage = gradeAverage * 0.4 + examGrade * 0.6;

        vector<string> vt2;
        vt2.push_back(firstName);
        vt2.push_back(lastName);
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << gradeAverage;
        std::string s = stream.str();
        vt2.push_back(s);
        vt2.push_back(to_string(median));
        results.push_back(vt2);
    }
    printResult(results);
    return 0;
}