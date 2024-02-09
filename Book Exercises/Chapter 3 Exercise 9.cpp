/**
 * Write a program that converts spelled-out numbers such as "zero" and "two" into 
 * digits, such as 0 and 2. When the user inputs a number the program should print 
 * out the corresponding digit. Do it for the values 0, 1, 2, 3, and 4 and write 
 * out not a number I know if the user enters something that does not correspond 
 * to a digit.
*/

#include <iostream>

using namespace std;

int main(){
    string num;
    cout << "Enter a number: ";
    cin >> num;
    if(num == "zero"){
        cout << 0;
    } else if(num == "one"){
        cout << 1;
    } else if(num == "two"){
        cout << 2;
    } else if(num == "three"){
        cout << 3;
    } else if(num == "four"){
        cout << 4;
    } else {
        cout << "Not a number I know";
    }
}