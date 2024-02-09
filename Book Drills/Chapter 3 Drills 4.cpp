/**
 * Declare a char variable called friend_sex and initialize its value to 0. Prompt the
 * user to enter an m if the friend is male and an f if the friend is a female. Assign the
 * value entered to the variable friend_sex. Then use two if-statements to write the following: If the friend is male, write "If you see friend_name please ask him to call
 * call me." If the friend is female, write "If you see friend_name please ask her to call
 * me."
 * */
#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    string first_name;
    char fs = 0;
    cout << "Hello, please enter your first name: ";
    cin >> first_name;
    cout << "Dear " << first_name << ",\n\t" 
    << "How are you? I am fine, I miss you. I was hoping that we can catch up \n at the old place that we use to visit whenever we would study a lot.";
    cout << "\n\n Hello User, please enter your firend's name: ";
    string friend_name;
    cin >> friend_name;
    cout << "User, is your friend a male (m) or female (f) or other (o)? ";
    cin >> fs;
    cout << "Have you seen " << friend_name << " lately? if you see " << friend_name <<
    " please ask ";
    if (fs == 'm'){
        cout << "him ";
    } else if (fs == 'f'){
        cout << "her ";
    } else {
        cout << "them ";
    }
    cout << "to call me. ";
}