/**
 *     10. Modify the program from exercise 8 to use double instead of int. Also, make vector of doubles containing the N-1 differences between adjacent values and write out that vector of differences.
*/
#include <iostream>
#include <random>

using namespace std;

int randi();
double randd();

int main() try {
    cout << "Please enter the number of values you want to sum: ";
    int n;
    string num;
    cin >> n;
    cout << "\nPlease enter some integers( press \'|\' to stop):";

    vector<double> dv;

    #if 0
    while(cin >> num){
        if(num == "|") break;
        dv.push_back(stoi(num));
    }
    #endif

    #if 1
    for (int i = 0; i <= n; i++) {
        dv.push_back(randd());
    }
    if(dv.size() < n){
        throw out_of_range("Asking for the sum of more numbers than there are input into interface.");
    }
    #endif
    cout << "\nThe sum of the first " << n << " numbers (";
    for (int i = 0; i < n; i++) {
        cout << dv[i] << " ";
    }
    cout << ") is " << accumulate(dv.begin(), dv.begin() + n, 0) << "." << endl;

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

double randd() {
    static mt19937 mt(random_device{}());
    static uniform_real_distribution<double> dist(0.0, 100.0);
    return dist(mt);
}