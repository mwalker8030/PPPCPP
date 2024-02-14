/**
 * Write a program that plays the game "Rock, Paper, Scissors". The game consists of a 
 * series of rounds, in each round the user selects one of three options, then the 
 * computer selects one of three options, and the winner is determined.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;
const vector<string> ops = {"Rock", "Paper", "Scissors"};
int rps();

int main(){
    cout << "Rock, Paper, Scissors, Shoot!\n";
    int p1 = rps();
    int p2 = rps();
    cout << "Player 1: " << ops[p1] << " Player 2: " << ops[p2] << endl;
    if(p1 == p2){
        cout << "It's a tie!\n";
    }else if((p1 == 0 && p2 == 2) || (p1 == 1 && p2 == 0) || (p1 == 2 && p2 == 1)){
        cout << "Player 1 wins!\n";
    }else{
        cout << "Player 2 wins!\n";
    }
}

/*randomly picks rock paper or sissors*/
int rps()
{
    static mt19937 mt{random_device{}()};
    uniform_int_distribution<int> dist(0, ops.size() - 1);   
    return dist(mt);
}
