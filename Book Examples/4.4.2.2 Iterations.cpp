/**
 * Rewrite the character value example from the previous Try this to use a 
 * for-statement. Then modify your program to also write out a table of the integer 
 * values for uppercase letters and digits.
*/

#include <iostream>

using namespace std;

int main(){
    char ch = 'A';
    for(int i = 0; ch + i <= 'z'; i++){
        // something tells me this would cause a narrowing conversion error later
        cout << char(ch + i) << " " << int(ch + i) << endl;
    }
}