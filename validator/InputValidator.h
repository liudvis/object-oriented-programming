//
// Created by liudv on 2/21/2022.
//

#ifndef STUDENT_GRADES_VALIDATOR_H
#define STUDENT_GRADES_VALIDATOR_H

#include <iostream>
#include <limits>

#endif //STUDENT_GRADES_VALIDATOR_H
using namespace std;

int validateGradeInput(int grade) {
    while (true) {
        if (cin >> grade && grade > 1 && grade <= 10) {
            break;
        } else if (grade == -1) {
            return 0;
        } else {
            cout << "Neteisingas pazymis. Prasome ivesti skaiciu nuo 1 iki 10: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return grade;
}

int validateNaturalNumberInput(int number) {
    while (true) {
        if (cin >> number && number > 0) {
            break;
        } else if (number == -1) {
            return 0;
        } else {
            cout << "Neteisingai ivestas skaicius. Iveskite naturaluji skaiciu: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return number;
}

bool isNumber(string string) {
    return string.find_first_not_of("0123456789") == string::npos;
}

string validateName(string name) {
    while (true) {
        if (cin >> name && !isNumber(name)) {
            break;
        } else {
            cout << "Vardas negali buti skaicius. Prasome ivesti dar karta:";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return name;
}