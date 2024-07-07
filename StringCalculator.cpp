#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm> // for std::replace
#include "StringCalculator.h"

bool isEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

void checkForNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("");
    }
}

bool isLessThanOrEqualTo1000(int num) {
    return num <= 1000;
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
            sum += isLessThanOrEqualTo1000(num) * num; // Using multiplication to conditionally add num to sum
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
