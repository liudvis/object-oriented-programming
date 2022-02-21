#include <iostream>
#include <vector>
#include <iomanip>
#include "validator/InputValidator.h"
#include "calculator/Calculator.h"
#include "printer/Output.h"

using namespace std;

int *addElementToArray(int homeWorkGrades[], int element, int index) {
    int size = (sizeof(homeWorkGrades) / sizeof(homeWorkGrades[0]));
    if (index == size) {
        int *newArr = new int[size * 2];
        std::copy(homeWorkGrades, homeWorkGrades + std::min(size, size * 2), newArr);
        delete[] homeWorkGrades;
        homeWorkGrades = newArr;
    }
    homeWorkGrades[index] = element;
    return homeWorkGrades;
}

int *unknownNumberOfHomeWorksArray() {
    bool shouldRun = true;
    int index = 0;
    int *homeWorkGrades = new int[2]; //initial size of array
    while (shouldRun) {
        int homeWorkGrade;
        cout << ("Iveskite namu darbu pazymi nr. " + to_string(index + 1) +
                 " (jeigu norite sustabdyti ivedima, iveskite -1): ");
        homeWorkGrade = validateGradeInput(homeWorkGrade);
        if (homeWorkGrade == 0) {
            int *finalArray = new int[index];
            for (int a = 0; a < index; a++) {
                cout << homeWorkGrades[a] << endl;
                finalArray[a] = homeWorkGrades[a];
            }
            return finalArray;
        }
        homeWorkGrades = addElementToArray(homeWorkGrades, homeWorkGrade, index);
        index++;
    }
}

vector<int> knownNumberOfHomeWorksVector() {
    vector<vector<string>> results;
    int numberOfHomeWorks;
    cout << "Iveskite namu darbu pazymiu skaiciu: ";
    numberOfHomeWorks = validateNaturalNumberInput(numberOfHomeWorks);

    vector<int> gradesOfHomeWorks;
    for (int i = 1; i <= numberOfHomeWorks; i++) {
        int homeWorkGrade;
        cout << ("Iveskite namu darbu pazymi nr. " + to_string(i) +
                 " (jeigu norite sustabdyti ivedima, iveskite -1): ");
        homeWorkGrade = validateGradeInput(homeWorkGrade);
        if (homeWorkGrade == 0) {
            break;
        }
        gradesOfHomeWorks.push_back(homeWorkGrade);
    }
    return gradesOfHomeWorks;
}

vector<int> generateRandomGrades() {
    vector<int> gradesOfHomeWorks;
    for (int i = 0; i < 10; i++) {
        gradesOfHomeWorks.push_back((rand() % 10) + 1);
    }
    return gradesOfHomeWorks;
}

vector<string> processCalculations(vector<int> gradesOfHomeWorks, string firstName, string lastName) {
    double gradeAverage = Calculator::calculateAverage(gradesOfHomeWorks);
    int median = Calculator::calculateMedian(gradesOfHomeWorks);

    int examGrade;
    cout << endl << "Iveskite egzamino pazymi: ", cin >> examGrade;
    gradeAverage = gradeAverage * 0.4 + examGrade * 0.6;

    vector<string> vt2;
    vt2.push_back(lastName);
    vt2.push_back(firstName);
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << gradeAverage;
    std::string s = stream.str();
    vt2.push_back(s);
    vt2.push_back(to_string(median));
    return vt2;
}

int main() {
    vector<vector<string>> results;
    int numberOfStudents;
    cout << "Iveskite studentu kieki: ";
    numberOfStudents = validateNaturalNumberInput(numberOfStudents);
    if (numberOfStudents == 0) return 0;

    for (int y = 0; y < numberOfStudents; y++) {
        string firstName, lastName, isRandom, shouldUseVectors;
        cout << "Iveskite studento varda: ";
        firstName = validateName(firstName);
        cout << "Iveskite studento pavarde: ";
        lastName = validateName(lastName);

        cout << "Ar pazymiai turetu buti atsitiktiniai? (iveskite yes) ", cin >> isRandom;
        if (isRandom.compare("yes") == 0) {
            vector<int> gradesOfHomeWorks = generateRandomGrades();
            results.push_back(processCalculations(gradesOfHomeWorks, firstName, lastName));
        } else {
            cout << "Ar duomenu strukturai turetu buti naudojamas vektorius? (iveskite yes) ", cin >> shouldUseVectors;
            if (shouldUseVectors.compare("yes") == 0) {
                vector<int> gradesOfHomeWorks = knownNumberOfHomeWorksVector();
                results.push_back(processCalculations(gradesOfHomeWorks, firstName, lastName));
            } else {
                cout << endl << "Duomenu strukturai naudojamas masyvas " << endl;
                int *numberOfHomeworksArray = unknownNumberOfHomeWorksArray();
                for (unsigned int a = 0;
                     a < sizeof(numberOfHomeworksArray) / sizeof(numberOfHomeworksArray[0]); a = a + 1) {
                }
                vector<int> gradesOfHomeWorks(numberOfHomeworksArray, numberOfHomeworksArray +
                                                                      sizeof numberOfHomeworksArray /
                                                                      sizeof numberOfHomeworksArray[0]);
                results.push_back(processCalculations(gradesOfHomeWorks, firstName, lastName));
            }
        }
    }
    Output::printResult(results);
    return 0;
}
