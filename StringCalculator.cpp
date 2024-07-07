#include <iostream>
#include <string>
#include <sstream>
#include "StringCalculator.h"

class StringCalculator {
public:
    int add(const std::string& input) {
        return isEmptyOrZero(input) * computeSum(input);
    }

private:
    int isEmptyOrZero(const std::string& input) {
        return input.empty() || input == "0";
    }

    int computeSum(const std::string& input) {
        std::stringstream ss(input);
        int sum = 0;
        std::string number;

        std::getline(ss, number, ',');
        sum += std::stoi(number);

        std::getline(ss, number, ',');
        sum += std::stoi(number);

        return sum;
    }
};
