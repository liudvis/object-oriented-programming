//
// Created by liudv on 2/21/2022.
//

#ifndef STUDENT_GRADES_VALIDATOR_H
#define STUDENT_GRADES_VALIDATOR_H

#include <iostream>

#endif //STUDENT_GRADES_VALIDATOR_H
using namespace std;

int validateGradeInput(int grade) {
    while (true) {
        if (cin >> grade && grade > 1 && grade <= 10) {
            break;
        } else if (grade==0) {
            return 0;
        } else {
            cout << "Neteisingas pazymis. Prasome ivesti dar karta: ";
            cin.clear();
        }
    }
    return grade;
}

//string validateName(string name) {
//    while (true) {
//        if (cin >> name && name > 1 && name <= 10) {
//            break;
//        } else {
//            cout << "Neteisingas pazymis. Prasome ivesti dar karta:";
//            cin.clear();
//        }
//    }
//    return name;
//}