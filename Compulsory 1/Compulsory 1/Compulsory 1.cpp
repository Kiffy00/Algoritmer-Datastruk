#include <iostream>

// noticeable hang on personal computer around n = 40+
uint32_t fibonacci(int n) {
    if (n < 0) {
        std::cout << "Invalid input for Fibonacci: Negative numbers are not supported." << std::endl;
        return false;
    }
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// seems to overflow around n = 21
uintmax_t factorial(int n) {
    if (n < 0) {
        std::cout << "Invalid input for factorial: Negative numbers are not supported." << std::endl;
        return false;
    }
    if (n == 0) 
        return 1;
    return n * factorial(n - 1);
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;

    while (true) {
        // fibonacci
        while (true) {
            std::cout << "Enter the position of the Fibonacci number you want to find: ";
            std::cin >> n;

            if (std::cin) {
                uint32_t result = fibonacci(n);
                if (result || n == 0) {
                    std::cout << "The Fibonacci number at position " << n << " is: " << result << std::endl;
                    break;
                }
            }
            else {
                std::cout << "Invalid input. Please enter a positive integer." << std::endl;
                clearInput();
            }
        }

        // factorial
        while (true) {
            std::cout << "Enter the number for which you want to find the factorial: ";
            std::cin >> n;

            if (std::cin) {
                uintmax_t result = factorial(n);
                if (result || n == 0) {
                    std::cout << "The factorial of " << n << " is: " << result << std::endl;
                    break;
                }
            }
            else {
                std::cout << "Invalid input. Please enter a positive integer." << std::endl;
                clearInput();
            }
        }
    }

    return 0;
}