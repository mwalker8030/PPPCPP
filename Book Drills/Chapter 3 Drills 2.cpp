/**
 * Add an introductory line or two, like "How are you? I am fine. I miss you." Be sure to indent the first line. add a few more lines of your choosing - it's your letter.
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
}