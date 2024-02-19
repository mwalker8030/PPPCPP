/**
 *     8. Write a program that reads and stores a series of integers and then computes the sum of the first N integers. First ask for N, then read that values into a vector, then calculate the sum of the first N values. For example: “Please enter the number of values you want to sum: “ 3 “Please enter some integers( press ‘|’ to stop):” 12 23 24 15 |  “The sum of the first 3 numbers (12 23 13) is 48.” Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than there are in the vector.
*/
#include <iostream>
#include <random>

using namespace std;

int randi();

int main() try {
    cout << "Please enter the number of values you want to sum: ";
    int n, num;
    cin >> n;
    cout << "\nPlease enter some integers( press \'|\' to stop):";
    vector<int> v;

    #if 0
    while(cin >> num){
        v.push_back(num);
    }
    #endif
    #if 1
    for (int i = 0; i <= n; i++) {
        v.push_back(randi());
    }
    #endif
    if(v.size() < n){
        throw invalid_argument("Asking for the sum of more numbers than there are input into interface.");
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