/**
 * Write a program that finds the min, max, and mode of a sequence of integers.
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;
const int minv = 0, maxv = 20;

int randi();

int main(){
    vector<int>count(maxv + 1);
    vector<int>v(100);
    cout << "Enter in 100 numbers between 0 and 9. Do this 100 times: \n";
    int mini = v[0];
    int maxi = v[0];
    for(int i = 0; i < v.size(); i++){
        v[i] = randi();
        count[v[i]]++;
        if(v[i] < mini){
            mini = v[i];
        }
        if(v[i] > maxi){
            maxi = v[i];
        }
    }
    int mode = 0;
    for(int i = 0; i < count.size(); i++){
        cout << i << " : " << count[i] << endl;
        if(count[i] > count[mode]){
            mode = i;
        }
    }
    cout << "The min is: " << mini << ", the max is: " << maxi << ", and the mode is: " << mode << endl;
}

int randi()
{
    static mt19937 mt(random_device{}());
    uniform_int_distribution<int> dit(minv, maxv);
    return dit(mt);
}
