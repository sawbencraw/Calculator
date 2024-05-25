#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cmath> // for sqrt and pow functions

// Use the standard namespace to avoid prefixing with std::
using namespace std;

// Calculator class to perform basic arithmetic operations
class Calculator {
public:
    // Function to add two numbers
    double add(double a, double b) {
        return a + b;
    }

    // Function to subtract the second number from the first
    double subtract(double a, double b) {
        return a - b;
    }

    // Function to multiply two numbers
    double multiply(double a, double b) {
        return a * b;
    }

    // Function to divide the first number by the second
    // Throws an exception if division by zero is attempted
    double divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }

    // Function to calculate the power of a base number raised to an exponent
    double power(double base, double exponent) {
        return pow(base, exponent);
    }

    // Function to calculate the square root of a number
    // Throws an exception if the number is negative
    double squareRoot(double a) {
        if (a < 0) {
            throw invalid_argument("Square root of a negative number is not allowed.");
        }
        return sqrt(a);
    }
};

// Function to display the calculator menu to the user
void showMenu() {
    cout << "Simple Calculator\n";
    cout << "Select operation:\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Exponential\n";
    cout << "6. Square Root\n";
    cout << "7. Exit\n";
}

int main() {
    // Dynamically allocate memory for a Calculator object
    Calculator* calc = new Calculator();
    int choice;
    double num1, num2;
    string input;

    // Main loop to process user input and perform calculations
    while (true) {
        showMenu(); // Display the menu
        cout << "Enter your choice: ";
        getline(cin, input); // Read the user's choice
        stringstream(input) >> choice; // Convert the input to an integer

        if (choice == 7) { // Exit condition
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        try {
            double result;
            switch (choice) {
                case 1: // Addition
                    cout << "Enter first number: ";
                    getline(cin, input);
                    stringstream(input) >> num1; // Read and convert the first number
                    cout << "Enter second number: ";
                    getline(cin, input);
                    stringstream(input) >> num2; // Read and convert the second number
                    result = calc->add(num1, num2); // Perform addition
                    cout << "Result: " << result << "\n";
                    break;
                case 2: // Subtraction
                    cout << "Enter first number: ";
                    getline(cin, input);
                    stringstream(input) >> num1; // Read and convert the first number
                    cout << "Enter second number: ";
                    getline(cin, input);
                    stringstream(input) >> num2; // Read and convert the second number
                    result = calc->subtract(num1, num2); // Perform subtraction
                    cout << "Result: " << result << "\n";
                    break;
                case 3: // Multiplication
                    cout << "Enter first number: ";
                    getline(cin, input);
                    stringstream(input) >> num1; // Read and convert the first number
                    cout << "Enter second number: ";
                    getline(cin, input);
                    stringstream(input) >> num2; // Read and convert the second number
                    result = calc->multiply(num1, num2); // Perform multiplication
                    cout << "Result: " << result << "\n";
                    break;
                case 4: // Division
                    cout << "Enter first number: ";
                    getline(cin, input);
                    stringstream(input) >> num1; // Read and convert the first number
                    cout << "Enter second number: ";
                    getline(cin, input);
                    stringstream(input) >> num2; // Read and convert the second number
                    result = calc->divide(num1, num2); // Perform division
                    cout << "Result: " << result << "\n";
                    break;
                case 5: // Exponential
                    cout << "Enter the base number: ";
                    getline(cin, input);
                    stringstream(input) >> num1; // Read and convert the base number
                    cout << "Enter the exponent: ";
                    getline(cin, input);
                    stringstream(input) >> num2; // Read and convert the exponent
                    result = calc->power(num1, num2); // Calculate the power
                    cout << "Result: " << result << "\n";
                    break;
                case 6: // Square Root
                    cout << "Enter the number: ";
                    getline(cin, input);
                    stringstream(input) >> num1; // Read and convert the number
                    result = calc->squareRoot(num1); // Calculate the square root
                    cout << "Result: " << result << "\n";
                    break;
                default: // Invalid choice handling
                    cout << "Invalid choice. Please select a valid option.\n";
                    break;
            }
        } catch (const invalid_argument& e) { // Handle invalid arguments
            cout << "Error: " << e.what() << "\n";
        } catch (const exception& e) { // Handle other exceptions
            cout << "An unexpected error occurred: " << e.what() << "\n";
        }
    }

    // Deallocate the memory for the Calculator object
    delete calc;
    return 0;
}
