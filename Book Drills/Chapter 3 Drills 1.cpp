/**
 * This drill is to write a program that produces a simple form letter based on user input. Begin by typing the code from prompting a user to enter his or her first name and writing "Hello, first_name" where first_name is the name entered by the user. Then modify your code as follows: put to "Dear first_name,". Don't forget the comma.
 * */
#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    string first_name;
    cout << "Hello, please enter your first name: ";
    cin >> first_name;
    cout << "Dear " << first_name << ",";
}