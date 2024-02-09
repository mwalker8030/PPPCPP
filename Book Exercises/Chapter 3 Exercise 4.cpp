/**
 * Write a program that prompts the user to enter two integer values. Store these 
 * values in int variables named val1 and val2. Write your program to determine 
 * the smaller, larger, sum, difference, product, and ratio of thees and report 
 * them to the user.
*/

#include <iostream>

using namespace std;

int main(){
    int val1 = 0, val2 = 0;
    cout << "Enter two integers: ";
    cin >> val1 >> val2;

    if(val1 > val2){
        cout << "smaller: " << val2 << "\nlarger: " << val1 << endl;
    } else {
        cout << "smaller: " << val1 << "\nlarger: " << val2 << endl;
    }
    cout << "sum: " << val1 + val2 <<
    "\ndifference: " << val1 - val2 <<
    "\nproduct: " << val1 * val2 <<
    "\nratio: " << val1 / val2 << endl;
}