#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    int choice;

    do {
    	cout << "TASK 2 - SIMPLE CALCULATOR" << endl;
        cout << "\nSimple Calculator" << endl;
        cout << "Select operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch(choice) {
            case 1:
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Error: Invalid choice. Please select a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
