/**
 * Prompt the user to enter the age of the recipient and assign it to an int variable age.
 * Have your program write "I hear you just had a birthday and you are age years old." If
 * age is 0 or less or 110 or more, call simple_error("you're kidding!") using
 * simple_error().
 * */
#include <stdio.h>
#include <iostream>


using namespace std;

/**
 * outputs an error message to the user if the age entered is less than 0 or greater than
 * 110
*/
void simple_error(string message){
    cout << message << endl;
}

int main(){
    string first_name;
    char fs = 0;
    int age = 0;
    cout << "Hello, please enter your first name: ";
    cin >> first_name;
    cout << "Dear " << first_name << ",\n\t" 
    << "How are you? I am fine, I miss you. I was hoping that we can catch up \n at the old place that we use to visit whenever we would study a lot.";
    cout << "\n\n Hello User, please enter your firend's name: ";
    string friend_name;
    cin >> friend_name;
    cout << "User, is your friend a male (m) or female (f) or other (o)? ";
    cin >> fs;
    cout << "User, what age is your friend? ";
    cin >> age;
    if(age <= 0 || age >= 110){
        simple_error("you're kidding!");
    }

    cout << "Have you seen " << friend_name << " lately? if you see " << friend_name <<
    " please ask ";
    if (fs == 'm'){
        cout << "him ";
    } else if (fs == 'f'){
        cout << "her ";
    } else {
        cout << "them ";
    }
    cout << "to call me. I hear shes turning " << age << " this year.";
}