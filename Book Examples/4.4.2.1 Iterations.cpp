/**
 * The character 'b' is char('a' + 1), 'c' is char('a' + 2), 
 * and so on. Use a loop to write out a table of characters 
 * with their corresponding integer values.
*/

#include <iostream>

using namespace std;

int main(){
    char ch = 'a';
    while(ch <= 'z') {
        cout << ch << " is " << int(ch) << endl;
        ch++;
    }
}