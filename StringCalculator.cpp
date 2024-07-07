#include <iostream>
#include <string>
#include <sstream>
#include "StringCalculator.h"

bool isEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

int computeSum(const std::string& input) {
    std::stringstream ss(input);
    int sum = 0;
    std::string number;

    std::getline(ss, number, ',');
    int num1 = std::stoi(number);
    if (num1 < 0) {
        throw std::runtime_error("");
    }
    sum += num1;

    std::getline(ss, number, ',');
    int num2 = std::stoi(number);
    if (num2 < 0) {
        throw std::runtime_error("");
    }
    sum += num2;

    return sum;
}

int StringCalculator::add(const std::string& input) {
    return ::isEmptyOrZero(input) * ::computeSum(input);
}
