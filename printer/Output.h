//
// Created by liudv on 2/21/2022.
//

#ifndef STUDENT_GRADES_OUTPUT_H
#define STUDENT_GRADES_OUTPUT_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
namespace Output {
    void printResult(vector<vector<string>> results) {
        cout << endl;
        cout << left << setw(16) << "Pavarde";
        cout << left << setw(16) << "Vardas";
        cout << left << setw(25) << "Galutinis (vid.)";
        cout << left << setw(25) << "Galutinis (med.)";
        cout << endl << "----------------------------------------------------------------------------------" << endl;
        cout << fixed << showpoint;
        setprecision(4);
        for (auto x: results) {
            cout << left << setw(16) << x.at(0);
            cout << left << setw(16) << x.at(1);
            cout << left << setw(25) << x.at(2);
            cout << left << setw(25) << x.at(3) << endl;
        }
    }
}


#endif //STUDENT_GRADES_OUTPUT_H
