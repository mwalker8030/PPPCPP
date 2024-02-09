#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    int count;              // Declare a variable to hold an integer
    cin >> count;               // Read an integer from the keyboard
    string name;                // Declare a variable to hold a string
    cin >> name;                // Read a string from the keyboard

    int c2 = count + 2;         // Add 2 to the integer
    string s2 = name + " Jr.";      // + appends characters

    int c3 = count -2;          // Subtract 2 from the integer
    string s3 = name - " Jr.";  // error: - isn't defined for strings
}