/**
 * Add this to your letter:
 * If your friend is under 12, write "Next year you will be age+1."
 * If you friend is 17, write "Next year you will be able to vote."
 * If your friend is over 70, write "I hope you are enjoying retirement."
 * Check your program to make sure it responds appropriately to each kind of value.
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
    string sfs = "";
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
        sfs = "him ";
    } else if (fs == 'f'){
        sfs = "her ";
    } else {
        sfs = "them ";
    }
    cout << sfs << "to call me. I hear they are turning " << age << " this year.\n";

    if(age < 12){
        cout << "Next year they will be " << age+1 << ".\n"; 
    } else if(age == 17){
        cout << "Next year they will be able to vote.\n";
    }else if(age >= 70){
        cout << "I hope they are enjoying retirement.\n";
    }
}