/**
 * In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The number that appears the most times in a sequence is called the mode. Create a program that finds the mode of a set of positive integers.
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;
const int minv = 0, maxv = 9;

int randi();

int main(){
    vector<int>count(10);
    vector<int>v(100);
    cout << "Enter in 100 numbers between 0 and 9. Do this 100 times: \n";
    for(int i = 0; i < v.size(); i++){
        v[i] = randi();
        count[v[i]]++;
    }
    int mode = 0;

    for(int i = 0; i < count.size(); i++){
        cout << i << " : " << count[i] << endl;
        if(count[i] > count[mode]){
            mode = i;
        }
    }

    cout << mode << " reapears the most at: " << count[mode] << " times." << endl;
}

int randi()
{
    static mt19937 mt(random_device{}());
    uniform_int_distribution<int> dit(minv, maxv);
    return dit(mt);
}
