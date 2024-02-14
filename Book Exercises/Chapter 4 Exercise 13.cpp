/**
 * 13. Create a program to find all the prime numbers between 1 and 100. There is a 
 * classic method for doing this, called the "Sieve of Eratosthenes." If you don't know 
 * that method, get on the web and look it up. Write your program using this method.
 */

#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n, vector<bool> &primes);
void set_non_primes(int n, vector<bool> &primes);
int main(){
    cout << "Find all the prime numbers from 1 to what: ";
    int maxv = 2;
    cin >> maxv;
    if(maxv < 2){
        cout << "there are no prime numbers less than 2" << endl;
        return 0;
    }

    vector<bool> primes(maxv, true);
    primes[0] = false;
    primes[1] = false;
    int count = 0;
    for (int i = 2; i <= maxv; i++) {
        if(primes[i] && is_prime(i, primes)){
            set_non_primes(i, primes);
            count++;
        }
    }

    cout << "there are " << count << " prime numbers between 1 and " << maxv <<"\n";
}

bool is_prime(int n, vector<bool> &primes){
    for(int i = 2; i < n; i++){
        if(primes[i] && n % i == 0){
            cout << n << " is not a prime number because " << n << " % " << i << " = " << n%i << endl;
            return false;
        }
    }
    cout << n << " is a prime number\n";
    return true;
}

void set_non_primes(int n, vector<bool> &primes) {
    for(int i = 2; i < primes.size(); i++){
        if(i*n < primes.size() && primes[i*n]){
            primes[i*n] = false;
        }
    }
}
