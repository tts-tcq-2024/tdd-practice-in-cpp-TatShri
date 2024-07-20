#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <vector>

bool checkIfInput0OrEmpty(const std::string& input) {
    return input.empty() || input == "0";
}

void checkIfInputNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("Negatives not allowed");
    }
}

bool checkIfNumberLessThanOrEqualTo1000(int num) {
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
    checkIfInputNegative(num);
    if (checkIfNumberLessThanOrEqualTo1000(num)) {
        sum += num;
    }
}

int processInput(const std::string& numbers, const std::vector<std::string>& delimiters) {
    int sum = 0;
    std::string current_delimiter = delimiters[0];
    std::string secondary_delimiter = delimiters.size() > 1 ? delimiters[1] : "\n";

    std::stringstream ss(numbers);
    std::string number;

    while (std::getline(ss, number, current_delimiter[0])) {
        std::stringstream sub_ss(number);
        std::string sub_number;

        while (std::getline(sub_ss, sub_number, secondary_delimiter[0])) {
            verifyUpdateInput(sum, sub_number);
        }
    }

    return sum;
}

int operateDelimiters(const std::string& input) {
    const std::vector<std::string> defaultDelimiters = { ",", "\n" };

    for (const std::string& delimiter : defaultDelimiters) {
        if (input.find(delimiter) != std::string::npos) {
            return processInput(input, defaultDelimiters);
        }
    }

    return std::stoi(input);
}

int StringCalculator::add(const std::string& input) {
    if (checkIfInput0OrEmpty(input)) {
        return 0;
    }

    std::string customDelimiter = extractCustomDelimiter(input);
    if (!customDelimiter.empty()) {
        std::string numbersString = input.substr(input.find("\n") + 1);
        return processInput(numbersString, { customDelimiter, "\n" });
    } else {
        return operateDelimiters(input);
    }
}
