#include "StringCalculator.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <vector>


int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    std::istringstream ss(numbers);
    int sum = 0;
    std::string number;
    while (std::getline(ss, number, ',')) {
        sum += std::stoi(number);
    }
    return sum;
}

