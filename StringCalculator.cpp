#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <vector>

bool checkifInput0orEmpty(const std::string& input) {
    return input.empty() || input == "0";
}

void checkifInputNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("Negatives not allowed");
    }
}

bool checkifNumberLessThanOrEqualTo1000(int num) {
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

void verifyUpdateInput(int& sum, const std::string& number) {
    int num = std::stoi(number);
    checkifInputNegative(num);
    if (checkifNumberLessThanOrEqualTo1000(num)) {
        sum += num;
    }
}

int proccessInput(const std::string& numbers, const std::vector<std::string>& delimiters) {
    int sum = 0;
    std::stringstream ss(numbers);
    std::string number;

    while (std::getline(ss, number, delimiters[0][0])) {
        std::stringstream sub_ss(number);
        std::string sub_number;
        while (std::getline(sub_ss, sub_number, delimiters[1][0])) {
            verifyUpdateInput(sum, sub_number);
        }
    }

    return sum;
}

int operateDelimiters(const std::string& input) {
    const std::vector<std::string> defaultDelimiters = { ",", "\n" };

    for (const std::string& delimiter : defaultDelimiters) {
        if (input.find(delimiter) != std::string::npos) {
            return proccessInput(input, defaultDelimiters);
        }
    }

    return std::stoi(input);
}

int StringCalculator::add(const std::string& input) {
    if (input.empty()) {
        return 0;
    }

    std::string customDelimiter = extractCustomDelimiter(input);
    if (!customDelimiter.empty()) {
        std::string numbersString = input.substr(input.find("\n") + 1);
        return proccessInput(numbersString, { customDelimiter, "\n" });
    } else {
        return operateDelimiters(input);
    }
}
