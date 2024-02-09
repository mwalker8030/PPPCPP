/**
 * Now prompt the user for the name of another friend, and store it in friend_name. Add a line to your letter: "Have you seen friend_name lately?"
 * */
#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    string first_name;
    cout << "Hello, please enter your first name: ";
    cin >> first_name;
    cout << "Dear " << first_name << ",\n\t" 
    << "How are you? I am fine, I miss you. I was hoping that we can catch up \n at the old place that we use to visit whenever we would study a lot.";
    cout << "\n\n Hello User, please enter your firend's name: ";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?";
}