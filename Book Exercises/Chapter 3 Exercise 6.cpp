/**
 * Write a program that prompts the user to enter 
 * three integer values, and then output the values i
 * n numerical sequence separated by commas. So, if 
 * the user enters the values 10 4 6, the output 
 * should be 4, 6, 10. If two values are the same, 
 * they should be ordered together. So the input 4 5 
 * 4 should give 4 4 5
*/

#include <iostream>

using namespace std;

int main(){
    int a = 0, b = 0, c = 0;
    cout << "Enter three integer values: ";
    cin >> a >> b >> c;
    if (a <= b && a <= c) {
        cout << a << ", ";
        if(b <= c) {
            cout << b << ", " << c;
        } else {
            cout << c << ", " << b;
        }
    } else if (b <= a && b <= c) {
        cout << b << ", ";
        if(a <= c) {
            cout << a << ", " << c;
        } else {
            cout << c << ", " << a;
        }
    } else {
        cout << c << ", ";
        if(a <= b) {
            cout << a << ", " << b;
        } else {
            cout << b << ", " << a;
        }
    }
}