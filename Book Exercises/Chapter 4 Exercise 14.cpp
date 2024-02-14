/**
 * Write a program that takes an input value n and then finds the first n primes.
 */

#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n, vector<int> &primes);
void set_non_primes(int n, vector<int> &primes);
int main(){
    cout << "Find this number of prime numbers: ";
    int quantity = 1;
    cin >> quantity;


    vector<int> primes;
    int count = 0, found = -2;
    while(found < quantity){
        if(is_prime(count, primes)){
            //set_non_primes(count, primes);
            found++;
        }
        count++;
    }

    cout << "there are " << found << " prime numbers\n";
}

bool is_prime(int n, vector<int> &primes){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            //cout << n << " is not a prime number because " << n << " % " << i << " = " << n%i << endl;
            return false;
        }
    }
    cout << n << " is a prime number\n";
    primes.push_back(n);
    return true;
}

void set_non_primes(int n, vector<int> &primes) {
    for(int i = 2; i < primes.size(); i++){
        if(i*n < primes.size() && primes[i*n]){
            primes[i*n] = false;
        }
    }
}
