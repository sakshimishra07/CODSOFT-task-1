#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        throw "Error: Division by zero is not allowed!";
    }
    return a / b;
}

int main() {
    int num1, num2, result;
    char op;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            try {
                result = divide(num1, num2);
            } catch (const char* msg) {
                cerr << msg << endl;
                return 1;
            }
            break;
            default:
            cerr<<"error : Invalid operation!"<<endl;
            return 1;
    }
    cout<<"Result:"<<result<<endl;
    return 0;
}
