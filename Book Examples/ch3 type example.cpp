#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    cout << "Please enter your first name (followed by 'enter'):\n";
    string firstName;
    int age;
    cin >> firstName;
    cin >> age;
    cout << "Hello, " << firstName << " (age " << age << ")\n";
}