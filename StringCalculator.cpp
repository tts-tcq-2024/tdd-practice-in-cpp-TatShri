#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm> 
#include "StringCalculator.h"

bool checkifEmptyOrZero(const std::string& input) {
    return input.empty() || input == "0";
}

void checkForNegative(int num) {
    if (num < 0) {
        throw std::runtime_error("negatives not allowed");
    }
}

bool checkifLessThanOrEqualTo1000(int num) {
    return num <= 1000;
}

// Function to extract the custom delimiter from input string
std::string extractcustomDelimiter(const std::string& input) {
    std::string del = ",";
    size_t del_pos = input.find("//");
    if (del_pos == 0) { // Only consider custom del if "//" is at the start
        del_pos += 2; // Move past "//"
        size_t newline_pos = input.find("\n", delimiter_pos);
        if (newline_pos != std::string::npos) {
            del = input.substr(del_pos, newline_pos - del_pos);
        }
    }
    return del;
}

// Function to replace newlines with commas when custom delimiter is not specified
std::string replaceNewlinesWithCommas(const std::string& input) {
    std::string modifiedInput = input;
    if (input.find("//") != 0) { // If "//" is not at the start, replace "\n" with ","
        std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', ','); // Replace newline with comma
    }
    return modifiedInput;
}

// Function to replace newlines with specified delimiter
std::string replaceNewlinesWithDelimiter(const std::string& input, const std::string& delimiter) {
    std::string modifiedInput = input;
    if (input.find("//") == 0) { // If "//" is at the start, replace "\n" with specified delimiter
        std::replace(modifiedInput.begin(), modifiedInput.end(), '\n', delimiter[0]); // Replace newline with delimiter

        // Find start of numbers after delimiter specification
        size_t pos = modifiedInput.find(delimiter);
        if (pos != std::string::npos) {
            modifiedInput.erase(0, pos + delimiter.length());
        }
    }
    return modifiedInput;
}

int computeSum(const std::string& input) {
    int sum = 0;
    std::string number;

    // Extract delimiter
    std::string delimiter = extractcustomDelimiter(input);

    // Replace newlines with the chosen delimiter
    std::string modifiedInput = replaceNewlinesWithCommas(input); // Handle default case

    // Replace newlines with specified delimiter if "//" is at the start
    modifiedInput = replaceNewlinesWithDelimiter(modifiedInput, delimiter);

    // Create a stringstream from the modified input
    std::stringstream ss(modifiedInput);

    // Parse numbers based on delimiter
    while (std::getline(ss, number, delimiter[0])) {
        if (!number.empty()) {
            int num = std::stoi(number);
            checkForNegative(num);
            sum += checkifLessThanOrEqualTo1000(num) * num;
        }
    }

    return sum;
}

int StringCalculator::add(const std::string& input) {
    if (checkifEmptyOrZero(input)) {
        return 0;
    }
    return computeSum(input);
}
