/**
 *       9. Modify the program from exercise 8 to write out an error if the result cannot be represented as an int.
*/
#include <iostream>
#include <random>

using namespace std;

int randi();

int main() try {
    cout << "Please enter the number of values you want to sum: ";
    int n;
    string num;
    cin >> n;
    cout << "\nPlease enter some integers( press \'|\' to stop):";
    vector<int> v;

    #if 1
    while(cin >> num){
        if(num == "|") break;
        v.push_back(stoi(num));
    }
    #endif
    #if 0
    for (int i = 0; i <= n; i++) {
        v.push_back(randi());
    }
    #endif
    if(v.size() < n){
        throw out_of_range("Asking for the sum of more numbers than there are input into interface.");
    }
    cout << "\nThe sum of the first " << n << " numbers (";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << ") is " << accumulate(v.begin(), v.begin() + n, 0) << "." << endl;

    return 0;
} catch (exception& e) {
    cout << e.what() << endl;
    return 1;
} catch(...) {
    cout << "Unknown error" << endl;
    return 2;
}

int randi() {
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(0, 100);
    return dist(mt);
}