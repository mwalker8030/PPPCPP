/**
 * Modify the "mini calculator" from exercise 5 to accept (just) single-digit numbers written as either digits or spelled out.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

const int min_v = 0, max_v = 19, min_op = 0, max_op = 3;

const vector<string> values = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const vector<string> vs = {"zero", "one", "two", "three", "four", "five",   
    "six", "seven", "eight", "nine"};
const vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const vector<char> ops = {'+', '-', '*', '/'};
double randd(double min, double max);
int randi(int min, int max);

int pick();
int main(){
    srand(static_cast<unsigned int>(time(0)));
    char op = ops[randi(min_op, max_op)];
    int a = pick(), b = pick();
    cout << "Enter an operator (+, -, *, /): ";
    op = ops[randi(min_op, max_op)];
    cout << op << "\n";

    cout << a << " " << op << " " << b << " = ";
    switch(op){
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            if(b == 0 && op == '/'){
                cout << "Cannot divide by zero" << endl;
                break;
            }
            cout << a / b << endl;
            break;
    }
    
}

/**
 * Returns a random double between min and max.
*/
double randd(double min, double max)
{
    static mt19937 mt{random_device{}()};
    uniform_real_distribution<double> dist(min, max);
    return dist(mt);
}

int randi(int min, int max){
    static mt19937 mt{random_device{}()};
    uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

/**
 * Allows the PC to pick a number between 0 and 9 for random input.
*/
int pick()
{
    cout << "Enter a value between " << vi[0] << " and " << vi[vi.size() - 1] << ": ";
    int index = randi(min_v, max_v);
    
    for(int i = 0; i < values.size(); i++){
        if(values[index] == values[i]){
            index = i;
            break;
        }
    }

    if(index < 10){
        cout << vs[index] << endl;
    }else{
        index -= 10;
        cout << vi[index] << endl;
    }
    return index;
}
