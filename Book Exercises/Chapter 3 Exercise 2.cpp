/**
 * Write a program in C++ that converts from 
 * miles to kilometers. Your program should 
 * have a reasonable prompt for the user to 
 * enter a number of miles. Hint: There are 1.
 * 609 kilometers to the mile.
*/

#include <iostream>

using namespace std;

int main(){
    cout << "Enter a number of miles to travel: ";
    double miles;
    cin >> miles;
    cout << "You will travel " << 
    (miles * 1.609) << " kilometers." << endl;
}