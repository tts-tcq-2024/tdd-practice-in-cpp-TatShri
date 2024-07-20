class StringCalculator {
public:
    // Method to calculate the sum of numbers from the input string
    int add(const std::string& input);

private:
    // Function to check if a number is negative and throw an exception if it is
    static void checkForNegative(int number);

    // Function to check if a number is greater than 1000 and exclude it
    static int checkforGreaterthan1000(int number);

    // Function to extract numbers with 1 to 4 digits from a string while preserving the order
    static std::vector<int> extractNumbers(const std::string& input);

    // Function to calculate the sum of numbers in a vector
    static int calculateSum(const std::vector<int>& numbers);
};
