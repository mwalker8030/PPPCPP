/**
 * Do exercise 6, but with three string values. So if the 
 * user enters the values Steinbeck, Hemingway, Fitzgerald, 
 * the output should be Fitzgerald, Hemingway, Steinbeck.
*/

#include <iostream>

using namespace std;

int main(){
    string a = "", b = "", c = "";
    cout << "Enter three strings or names: ";
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