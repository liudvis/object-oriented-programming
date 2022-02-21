//
// Created by liudv on 2/21/2022.
//
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>

#ifndef STUDENT_GRADES_CALCULATOR_H
#define STUDENT_GRADES_CALCULATOR_H

#endif //STUDENT_GRADES_CALCULATOR_H
using namespace std;

namespace Calculator {
    double calculateAverage(vector<int> vector) {
        return accumulate(vector.begin(), vector.end(), 0) / (double) vector.size();
    }

    int calculateMedian(vector<int> vector) {
        size_t n = vector.size() / 2;
        for (auto i: vector)
            std::cout << i << ' ';
        nth_element(vector.begin(), vector.begin() + n, vector.end());
        return vector[n];
    }
}