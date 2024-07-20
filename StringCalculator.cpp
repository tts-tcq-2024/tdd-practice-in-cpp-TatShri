#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <vector>

// Helper function to split a string by a single delimiter
std::vector<std::string> splitByDelimiter(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }
    result.push_back(str.substr(start));

    return result;
}

// Helper function to split a string by both primary and secondary delimiters
std::vector<std::string> splitInputByDelimiters(const std::string& numbers, const std::string& primaryDelimiter, const std::string& secondaryDelimiter) {
    std::vector<std::string> splitNumbers;

    // Split by the primary delimiter
    std::vector<std::string> primarySplit = splitByDelimiter(numbers, primaryDelimiter);

    // Split each segment by the secondary delimiter
    for (const auto& segment : primarySplit) {
        std::vector<std::string> secondarySplit = splitByDelimiter(segment, secondaryDelimiter);
        splitNumbers.insert(splitNumbers.end(), secondarySplit.begin(), secondarySplit.end());
    }

    return splitNumbers;
}


// Checks if input is empty or contains only "0"
bool isInputEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

// Throws an exception if a negative number is encountered
void checkForNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("Negatives not allowed");
    }
}

// Validates if the number is less than or equal to 1000
bool isNumberValid(int num) {
    return num <= 1000;
}

// Extracts the custom delimiter if specified in the input
std::string extractCustomDelimiter(const std::string& input) {
    if (input.size() >= 2 && input.substr(0, 2) == "//") {
        size_t delimiter_end = input.find('\n', 2);
        if (delimiter_end != std::string::npos) {
            return input.substr(2, delimiter_end - 2);
        }
    }
    return "";
}

// Splits the input string by primary and secondary delimiters
std::vector<std::string> splitInput(const std::string& numbers, const std::string& primaryDelimiter, const std::string& secondaryDelimiter) {
    return splitInputByDelimiters(numbers, primaryDelimiter, secondaryDelimiter);
}

// Calculates the sum of the numbers after splitting and validation
int calculateSum(const std::vector<std::string>& numbers) {
    int sum = 0;
    for (const auto& number : numbers) {
        int num = std::stoi(number);
        checkForNegative(num);
        if (isNumberValid(num)) {
            sum += num;
        }
    }
    return sum;
}

// Main method to add numbers based on input
int StringCalculator::add(const std::string& input) {
    if (isInputEmptyOrZero(input)) {
        return 0;
    }

    std::string customDelimiter = extractCustomDelimiter(input);
    std::string numbersString;
    std::string primaryDelimiter = ",";
    std::string secondaryDelimiter = "\n";

    if (!customDelimiter.empty()) {
        numbersString = input.substr(input.find('\n') + 1);
        primaryDelimiter = customDelimiter;
    } else {
        numbersString = input;
    }

    std::vector<std::string> splitNumbers = splitInput(numbersString, primaryDelimiter, secondaryDelimiter);
    return calculateSum(splitNumbers);
}
