#include <iostream>

class StringCalculator {
public:
    int add(const std::string& input) {
        if (input.empty()) {
            return 0;
        }
        else return -1;
    }
}
                
