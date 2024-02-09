/**
 * Write a program that takes an operation followed by two operands and outputs 
 * the result. for example: + 100 3.14 or * 4 5. Read the operation into a string 
 * called operation and use an if-statement to figure out which operation the user 
 * wants, for example, if (operation=="+"). Read the operand into variables of 
 * type double. Implement this for operations called +, -, *, /, plus, minus, mul, 
 * and div with their obvious meanings.
*/

#include <iostream>

using namespace std;

int main(){
    string operation;
    double operand1, operand2;

    cout << "Enter operation: ";
    cin >> operation >> operand1 >> operand2;

    if(operation == "+" || operation == "plus"){
        cout << operand1 + operand2 << endl;
    } else if (operation == "-" || operation == "minus"){
        cout << operand1 - operand2 << endl;
    } else if (operation == "*" || operation == "mul"){
        cout << operand1 * operand2 << endl;
    } else if (operation == "/" || operation == "div"){
        cout << operand1 / operand2 << endl;
    } else {
        cout << "Invalid operation" << endl;
    }
}