#include<iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    char choice;

    do {
        // Title
        cout << "\n==============================\n";
        cout << "      SIMPLE CALCULATOR\n";
        cout << "==============================\n";

        // User Input
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        // Perform Operation
        cout << "\nResult: ";
        switch(operation) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2;
                break;
            case '/':
                if(num2 != 0)
                    cout << num1 << " / " << num2 << " = " << num1 / num2;
                else
                    cout << "Error! Division by zero.";
                break;
            default:
                cout << "Invalid operation entered.";
        }

        // Ask to continue
        cout << "\n\nDo you want to perform another calculation? (Y/N): ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');

    cout << "\nThank you for using the calculator.\n";
    cout << "==============================\n";

    return 0;
}
