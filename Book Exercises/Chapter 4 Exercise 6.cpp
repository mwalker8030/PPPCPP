/**
 * Make a vector holding the ten string values "zero", "one",..., "nine".Use that in a 
 * program that converts a digit to its corresponding spelled-out value; e.g., the 
 * input 7 gives the output "seven." Have the same program, using the same input loop, 
 * convert spelled-out numbers into their digit form; e.g., the input seven gives the 
 * output 7.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

const int min_v = 1, max_v = 20, min_op = 1, max_op = 4;
const vector<string> values = {"zero", "one", "two", "three", "four", "five",   
    "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
double randd(double min, double max);
int rando(int min, int max);
int main(){
    srand(static_cast<unsigned int>(time(0)));
    cout << "Enter a value between " << min_v << " and " << 10 << ": ";
    int i = rando(min_v, max_v);
    cout << values[i] << endl;
    

    if(i < 10){
        cout << "The number is " << values[i + 9] << endl;
        return 0;
    }else{
        cout << "The number is " << values[i - 9] << endl;
        return 0;
    }
}

/**
 * Returns a random double between min and max.
*/
double randd(double min, double max)
{
    static mt19937 mt{random_device{}()};
    uniform_real_distribution<double> dist(min, max);
    return dist(mt);
}

int rando(int min, int max){
    static mt19937 mt{random_device{}()};
    uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}