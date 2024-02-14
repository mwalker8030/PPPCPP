/**
 * Modify the program described in the previous exercise to take an input value max and then find all the prime numbers from 1 to max.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;
bool is_prime(int n);
int main(){
    cout << "Find all the prime numbers from 1 to what: ";
    int maxv = 2;
    cin >> maxv;
    for (int i = 2; i <= maxv; i++) {
        if(is_prime(i)){
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << "\n";
    }

    cout << "there are " << primes.size() << " prime numbers between 1 and " << maxv <<"\n";
}

bool is_prime(int n)
{
    for (int i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}
