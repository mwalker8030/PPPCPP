#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    cout << "Please enter your first name (followed by 'enter'):\n";
    string first;
    string second;
    cin >> first >> second;
    cout << "Hello, " << first << " " << second << '\n';
}