#include <iostream>

using namespace std;

double add(double x, double y) {
    return x + y;
}


double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y == 0) {
        cout << "Number can`t be divided" << endl;
        return 0.0;
    }
    return x / y;
}

int main() {
    char operation;
    double num1, num2;

    cout << "Options:" << endl;
    cout << "Enter '+' for addition" << endl;
    cout << "Enter '-' for subtraction" << endl;
    cout << "Enter '*' for multiplication" << endl;
    cout << "Enter '/' for division" << endl;
    cout << "Enter 'e' to end" << endl;

    while (true) {
        cout << "Enter an operation: ";
        cin >> operation;

        if (operation == 'e') {
        	cout << "Thank you for using the Calculator." << endl;
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            default:
                cout << "Invalid input. Please enter a valid operation." << endl;
        }
    }

    return 0;
}

