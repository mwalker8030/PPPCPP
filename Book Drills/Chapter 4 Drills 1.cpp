/**
 * Write a program that consists of a while-loop that reads in two 
 * ints and then priints them. Exit the program when a 
 * termination | is entered.
*/

#include <iostream>

using namespace std;

int main(){
    vector<int> nums;
    double temp;
    while (cin>>temp){
        if(temp == '|')
            break;
        nums.push_back(temp);
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
        if((i + 1) % 2 == 0)
            cout << "\n";
    }
}