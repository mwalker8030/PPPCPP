/**
 *     11. Write a program that writes out the first so many values of the Fibonacci series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two previous ones. Find the largest Fibonacci number that fits in an int.
*/

#include <iostream>
#include <cstdlib>
#include <numeric>

using namespace std;
vector<int> fib = {1, 1};
int main() {
    int i = 1;
    cout  << fib[0] << " " << fib[1] << " ";
    while(fib[i] < numeric_limits<int>::max()-1 && fib[i] <= 1836311903 && fib[i] > 0) {
        fib.push_back(fib[i] +fib[i-1]);
        i++;
        cout << fib[i] << " ";
    }
}
