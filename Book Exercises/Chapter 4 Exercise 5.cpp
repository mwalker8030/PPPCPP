/**
 * Write a program that performs as a very simple calculator. Your calculator should be 
 * able to handle the four basic math operations -- add, subtract, multiply, and divide 
 * -- on two input values. Your program should prompt the user for three arguments: two 
 * double values and a character to represent the operation. If they entery arguments 
 * are 35.6, 24.1, and '+', the program output should be The sum of 35.6 and 24.1 is 59.
 * 7. In Chapter 6 we look at a much more sophisticated simple calculator.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

const double min_v = 1, max_v = 100, min_op = 1, max_op = 4;
const vector<char> ops = {'+', '-', '*', '/'};
double randd(double min, double max);

int main(){
    srand(static_cast<unsigned int>(time(0)));
    double a, b;
    char op;
    cout << "Enter two double values: ";
    a = randd(min_v, max_v);
    b = randd(min_v, max_v);
    cout << a << " " << b << "\n";
    cout << "Enter an operation: ";
    op = ops[rand() % ops.size()];
    cout << op << "\n";
    cout << a << " " << op << " " << b << " = ";
    switch(op){
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
    }
}

/**
 * Returns a random double between min and max.
*/
double randd(double min, double max)
{
    static std::mt19937 mt{std::random_device{}()};
    std::uniform_real_distribution<double> dist(min, max);
    return dist(mt);
}