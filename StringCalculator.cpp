#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "StringCalculator.h"

bool isEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

int computeSum(const std::string& input) {
    std::stringstream ss(input);
    int sum = 0;
    std::string number;

    while (std::getline(ss, number, ',')) {
        int num = std::stoi(number);
        if (num < 0) {
            throw std::runtime_error("Negative numbers not allowed: " + number);
        }
        sum += num;
    }

    return sum;
}

int StringCalculator::add(const std::string& input) {
    if (isEmptyOrZero(input)) {
        return 0;
    }
    return computeSum(input);
}
