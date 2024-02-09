/**
 * Write a program to test an integer value to 
 * determine if it is odd or even. As always, make 
 * sure your output is clear and complete. In 
 * otherwords, don't just output yes or no. Your 
 * output should stand alone, like the value 4 is an 
 * even number.
*/

#include <iostream>

using namespace std;

int main(){
    int val = 0;
    cout << "Enter an integer: ";
    cin >> val;
    if(val % 2 == 0){
        cout << val << " is an even number." << endl;
    } else {
        cout << val << " is an odd number." << endl;
    }
}