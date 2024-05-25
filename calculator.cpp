#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath> // for sqrt and pow functions

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }

    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }

    double squareRoot(double a) {
        if (a < 0) {
            throw std::invalid_argument("Square root of a negative number is not allowed.");
        }
        return std::sqrt(a);
    }
};

void showMenu() {
	std::cout << "\n";
    std::cout << "Select operation:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Exponential\n";
    std::cout << "6. Square Root\n";
    std::cout << "7. Exit\n";
}

int main() {
    Calculator* calc = new Calculator();
    int choice;
    double num1, num2;
    std::string input;

    while (true) {
        showMenu();
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);
        std::stringstream(input) >> choice;

        if (choice == 7) {
            std::cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        try {
            double result;
            switch (choice) {
                case 1:
                    std::cout << "Enter first number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num1;
                    std::cout << "Enter second number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num2;
                    result = calc->add(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 2:
                    std::cout << "Enter first number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num1;
                    std::cout << "Enter second number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num2;
                    result = calc->subtract(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 3:
                    std::cout << "Enter first number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num1;
                    std::cout << "Enter second number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num2;
                    result = calc->multiply(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 4:
                    std::cout << "Enter first number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num1;
                    std::cout << "Enter second number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num2;
                    result = calc->divide(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 5:
                    std::cout << "Enter the base number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num1;
                    std::cout << "Enter the exponent: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num2;
                    result = calc->power(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 6:
                    std::cout << "Enter the number: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> num1;
                    result = calc->squareRoot(num1);
                    std::cout << "Result: " << result << "\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please select a valid option.\n";
                    break;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        } catch (const std::exception& e) {
            std::cout << "An unexpected error occurred: " << e.what() << "\n";
        }
    }

    delete calc;
    return 0;
}
