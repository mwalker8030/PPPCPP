/**
 * 11) Write a program that prompts the user to enter some number of pennies
 * (1-cent coins), nickels (5-cent coins), dimes (10-cent coins), quarters 
 * (25-cent coins), half dollars (50-cent coins), and one-dollar coins (100-cent 
 * coins). Query the user separately for the number of each size coin, e.g., “How 
 * many pennies do you have?” Then your program should print out something like 
 * this:
 *    You have 23 pennies.
 *    You have 17 nickels.
 *    You have 14 dimes.
 *    You have 7 quarters.
 *    You have 3 half dollars.
 *    The value of all of your coins is 573 cents.
 * 
 * Make some improvements: if only one of a coin is reported, make the output 
 * grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes). Also, report 
 * the sum in dollars and cents, i.e., $5.73 instead of 573 cents.
*/

#include <iostream>

using namespace std;

int main(){
    int pennies = 0, nickels = 0, dimes = 0, quarters = 0, half_dollars = 0, one_dollars = 0;
    cout << "How many pennies do you have? ";
    cin >> pennies;
    cout << "How many nickels do you have? ";
    cin >> nickels;
    cout << "How many dimes do you have? ";
    cin >> dimes;
    cout << "How many quarters do you have? ";
    cin >> quarters;
    cout << "How many half dollars do you have? ";
    cin >> half_dollars;
    cout << "How many one dollars do you have? ";
    cin >> one_dollars;

    if(pennies == 1){
        cout << "You have " << pennies << " penny.\n";
    } else {
        cout << "You have " << pennies << " pennies.\n";
    }

    if(nickels == 1){
        cout << "You have " << nickels << " nickel.\n";
    } else {
        cout << "You have " << nickels << " nickels.\n";
    }

    if(dimes == 1){
        cout << "You have " << dimes << " dime.\n";
    } else {
        cout << "You have " << dimes << " dimes.\n";
    }

    if(quarters == 1){
        cout << "You have " << quarters << " quarter.\n";
    } else {
        cout << "You have " << quarters << " quarters.\n";
    }

    if(half_dollars == 1){
        cout << "You have " << half_dollars << " half dollar.\n";
    } else {
        cout << "You have " << half_dollars << " half dollars.\n";
    }

    if(one_dollars == 1){
        cout << "You have " << one_dollars << " one dollar.\n";
    } else {
        cout << "You have " << one_dollars << " one dollars.\n";
    }

    int total_cents = (pennies * 1) + (nickels * 5) + (dimes * 10) + (quarters * 25) + (half_dollars * 50) + (one_dollars * 100);
    cout << "The value of all of your coins is " << total_cents << " cents.\n";
}