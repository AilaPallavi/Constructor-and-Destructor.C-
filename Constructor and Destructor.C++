#include <iostream>
#include <limits> // for clearing input buffer

class Calculator {
private:
    double num1, num2;

public:
    // Constructor
    Calculator(double n1, double n2) : num1(n1), num2(n2) {}

    // Destructor
    ~Calculator() {
        std::cout << "Destructor called" << std::endl;
    }

    // Addition
    double add() {
        return num1 + num2;
    }

    // Subtraction
    double subtract() {
        return num1 - num2;
    }

    // Multiplication
    double multiply() {
        return num1 * num2;
    }

    // Division
    double divide() {
        if (num2 == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return 0;
        }
        return num1 / num2;
    }

    // Modulus
    double modulus() {
        if (num2 == 0) {
            std::cerr << "Error: Modulus by zero!" << std::endl;
            return 0;
        }
        return static_cast<int>(num1) % static_cast<int>(num2);
    }
};

int main() {
    char operation;
    double num1, num2;
    std::string choice;

    do {
        // Clear screen
        std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen

        std::cout << "Enter operation (+, -, *, /, %): ";
        std::cin >> operation;

        std::cout << "Enter two numbers: ";
        std::cin >> num1 >> num2;

        Calculator calc(num1, num2);
        double result;

        switch(operation) {
            case '+':
                result = calc.add();
                std::cout << "Sum of " << num1 << " and " << num2 << " is " << result << std::endl;
                break;
            case '-':
                result = calc.subtract();
                std::cout << "Difference of " << num1 << " and " << num2 << " is " << result << std::endl;
                break;
            case '*':
                result = calc.multiply();
                std::cout << "Product of " << num1 << " and " << num2 << " is " << result << std::endl;
                break;
            case '/':
                result = calc.divide();
                std::cout << "Division of " << num1 << " by " << num2 << " is " << result << std::endl;
                break;
            case '%':
                result = calc.modulus();
                std::cout << "Modulus of " << num1 << " by " << num2 << " is " << result << std::endl;
                break;
            default:
                std::cerr << "Invalid operation!" << std::endl;
        }

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Do you want to perform another operation? (yes/no): ";
        std::cin >> choice;

    } while (choice == "yes");

    return 0;
}
