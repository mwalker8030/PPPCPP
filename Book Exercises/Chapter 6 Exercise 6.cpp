/**
 * 9. Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and 3. The program should output 123 is 1 hundred and 2 ten and 3 ones. The number should be output as an int value. Handle numbers with one, two, three, or four digits. Hint: To get the integer value 5 from the character ‘5’ subtract ‘0’, that is, ’5’-‘0’ == 5.
*/

#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int randi();
const int MAX = 9, MIN = 0;
vector<char> numc;
const vector<string> place = {"ones", "ten", "hundred", "thousand", "million", "billion", "trillion"};
void describe_number(vector<char> &numc);
int main(){
    int n;
    cout << "How many numbers do you want this value to have? ";
    cin >> n;
    for(int i = 0; i < n; i++){
        numc.push_back(randi() + '0');
    }

    describe_number(numc);
    return 0;
}

int randi(){
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(MIN, MAX);
    return dist(mt);
}

void describe_number(vector<char> &numc){
    cout << "Then number ";
    for(char c : numc){ cout << c;}
    cout << " is ";
    for(int i = 0; i < numc.size(); i++){
        cout << numc[i] << " " << place[numc.size() - 1 - i] << " and ";
    }
}
