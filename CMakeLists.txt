cmake_minimum_required(VERSION 3.21)
project(student_grades)

set(CMAKE_CXX_STANDARD 14)

add_executable(student_grades main.cpp validator/InputValidator.h calculator/Calculator.h printer/Output.h)
