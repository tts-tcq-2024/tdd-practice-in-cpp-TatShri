// StringCalculator.cpp

#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <vector>

bool isInputEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

void checkForNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("negatives not allowed");
    }
}

bool isNumberLessThanOrEqualTo1000(int num) {
    return num <= 1000;
}

std::string extractCustomDelimiter(const std::string& input) {
    std::string delimiter;
    if (input.find("//") == 0) {
        size_t delimiter_start = 2;
        size_t delimiter_end = input.find("\n", delimiter_start);
        if (delimiter_end != std::string::npos) {
            delimiter = input.substr(delimiter_start, delimiter_end - delimiter_start);
        }
    }
    return delimiter;
}

void processNumberAndUpdateSum(int& sum, const std::string& number) {
    int num = std::stoi(number);
    checkForNegative(num);
    if (isNumberLessThanOrEqualTo1000(num)) {
        sum += num;
    }
}

int sumNumbers(const std::string& numbers, const std::string& delimiter) {
    int sum = 0;
    std::stringstream ss(numbers);
    std::string number;

    while (std::getline(ss, number, delimiter[0])) {
        processNumberAndUpdateSum(sum, number);
    }

    return sum;
}

int handleDefaultDelimiters(const std::string& input) {
    const std::vector<std::string> defaultDelimiters = { ",", "\n" };

    for (const std::string& delimiter : defaultDelimiters) {
        if (input.find(delimiter) != std::string::npos) {
            // Use sumNumbers with the found delimiter
            return sumNumbers(input, delimiter);
        }
    }

    // If no default delimiter is found, treat the input as a single number
    return std::stoi(input);
}

int StringCalculator::add(const std::string& input) {
    // Main logic of the add function
    if (isInputEmptyOrZero(input)) {
        return 0;
    }

    std::string customDelimiter = extractCustomDelimiter(input);
    if (!customDelimiter.empty()) {
        std::string numbersString = input.substr(input.find("\n") + 1);
        return sumNumbers(numbersString, customDelimiter);
    } else {
        return handleDefaultDelimiters(input);
    }
}
