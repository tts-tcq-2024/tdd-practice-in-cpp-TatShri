#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "StringCalculator.h"

bool isEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

void checkForNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("Negative numbers not allowed");
    }
}

int computeSum(const std::string& input) {
    int sum = 0;
    std::string number;

    // Replace newlines with commas
    std::string modifiedInput = input;
    std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', ',');

    // Create a stringstream from the modified input
    std::stringstream ss(modifiedInput);

    while (std::getline(ss, number, ',')) {
        if (!number.empty()) {
            int num = std::stoi(number);
            checkForNegative(num);
            sum += num;
        }
    }

    return sum;
}

int StringCalculator::add(const std::string& input) {
    if (isEmptyOrZero(input)) {
        return 0;
    }
    return computeSum(input);
}
