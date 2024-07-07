#include <iostream>
#include <string>
#include "StringCalculator.h"

int StringCalculator::add(const std::string& input) {
    if (input.empty() || input == "0") {
        return 0;
    }
    else {
        return -1;
    }
}
