/**
 * 10. A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to a vault. There are 60 possible numbers and you need three different numbers for the combination to a vault. There are 60 possible numbers, and you need three different numbers for the combination. There are P(60, 3) permutations for the combination, where P is defined by the formula
    1. P(a,b) = (a!)/(a-b)!
￼

Where ! Is used as a suffix factorial operator. For example, 4! Is 4*3*2*1.

Combinations are similar to permutations, except that the order of the objects doesn’t matter. For example, if you were making a “banana split” sundae and wished to use three different flavors of ice cream out of five that you had, you wouldn’t care if you used a scoop or vanilla at the beginning or the end; you would still have used vanilla. The formula for combinations is
	C(alb) = (P(a,b))/(b!)
￼
Design a program that asks users for two numbers, asks them whether they want to calculate permutations or combinations, and prints out the result. This will have several parts. Do an analysis of the above requirements. Write exactly what the program will have to do. Then, go into the design phrase. Write pseudo code for the program, and break it into sub-components. This program should have error checking. Make sure that all erroneous inputs will generate good error messages

*/
#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

#define AUTO false

//declarations
void choose(vector<double>&);
int randi();
void reset(vector<double>&, vector<pair<string, bool>>&);
void ask_user(vector<pair<string, bool>>&);
void calculate(vector<double>&, vector<pair<string, bool>>&);
double permutation(vector<double>&);
double factorial(double);
//varianles
const double maxd = 100, mind = 0;
int main(){
    vector<pair<string, bool>> choices {pair("permutations", false), pair("combinations", false)};
    vector<double> v;
    choose(v);

    ask_user(choices);

    calculate(v, choices);
    reset(v, choices);
    return 0;
}

void choose(vector<double> &v){
    cout << "Enter two values: ";
#if AUTO
    for(int i = 0; i< 2; i++){
        v.push_back(randi());
    }
#elif !AUTO
    double a, b;
    cin >> a >> b;
    v.push_back(a);
    v.push_back(b);
#endif
    cout << endl;
}

int randi(){
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(mind, maxd);
    return dist(mt);
}

void reset(vector<double>&v, vector<pair<string, bool>> &choices){
    v.clear();
    choices[0].second = false;
    choices[1].second = false;
}

void ask_user(vector<pair<string, bool>> &ch){
    cout << "Would you like to calculate permutations or combinations?" << endl;
    while(ch[0].second == false && ch[1].second == false){
        cout << "Enter 'p' for permutations or 'c' for combinations: ";
#if AUTO
        int i = randi()%2;
        ch[i].second = true;
        cout << ch[i].first << endl;
#elif !AUTO
        char c;
        cin >> c;
        if(c == 'p'){
            ch[0].second = true;
        } else if(c == 'c'){
            ch[1].second = true;
        }
#endif
        if(ch[0].second == false && ch[1].second == false){
            cout << "Invalid input. Please try again." << endl;
        }   
    }
}

void calculate(vector<double> &v, vector<pair<string, bool>> &ch){
    double lval = permutation(v);
    if(ch[1].second == true){
        lval /= factorial(v[1]);
        cout << "The combination of " << v[0] << " and " << v[1] << " is " << lval << endl;
    } else {
        cout << "The permutations of " << v[0] << " and " << v[1] << " is " << lval << endl;
    }
}

double factorial(double n){
    if(n==0){return 1;}
    return n*factorial(n-1);
}

double permutation(vector<double> &v){
    return factorial(v[0])/(factorial(v[0] - v[1]));
}