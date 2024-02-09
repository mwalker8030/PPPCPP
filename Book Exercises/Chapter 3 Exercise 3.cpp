/**
 * Write a program that doesn't do anything, 
 * but declares a number of variables with
 * legal and illegal names ( such as int
 * double = 0), so that you can see how the 
 * compiler reacts.
*/

#include <iostream>

using namespace std;

int main(){
    int double = 0.0;
    char int = 'c';
    cout << double << endl;
    cout << int << endl;
}