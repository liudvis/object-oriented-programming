#include <iostream>
#include <vector>
#include <iomanip>
#include "InputValidator.h"
#include "Calculator.h"
#include "Output.h"

using namespace std;

int main() {
    vector<vector<string>> results;
    int numberOfStudents;
    cout << "Iveskite studentu kieki: ";
    numberOfStudents = validateNumberOfStudentsInput(numberOfStudents);
    if (numberOfStudents == 0) return 0;

    for (int y = 0; y < numberOfStudents; y++) {
        string firstName, lastName;
        cout << "Iveskite studento varda: ";
        firstName = validateName(firstName);
        cout << "Iveskite studento pavarde: ";
        lastName = validateName(lastName);

        int numberOfHomeWorks;
        cout << "Iveskite namu darbu pazymiu skaiciu: ";
        numberOfHomeWorks = validateNumberOfGradeInput(numberOfHomeWorks);

        vector<int> gradesOfHomeWorks;
        for (int i = 1; i <= numberOfHomeWorks; i++) {
            int homeWorkGrade;
            cout << ("Iveskite namu darbu pazymi nr. " + to_string(i) +
                     " (jeigu norite sustabdyti ivedima, iveskite 0): ");
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
        vt2.push_back(lastName);
        vt2.push_back(firstName);
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << gradeAverage;
        std::string s = stream.str();
        vt2.push_back(s);
        vt2.push_back(to_string(median));
        results.push_back(vt2);
    }
    Output::printResult(results);
    return 0;
}