/**
 * Add a unit to each double entered; that is, enter values such as 10cm, 2.5in, or 3.
 * 33m. Accept the four units: cm, m, in, ft. Assume conversion factors 1m == 100cm, 1in 
 * == 2.54cm, 1ft == 12in. Read the unit indicator into a string. You may consider 12 m
 * (with a space between the number and the unit) equivalent to 12m (without a space).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/**
 * @brief gets the largest value from a vector of doubles.
*/
double getLarge(vector<double> v);
/**
 * @brief gets the smallest value from a vector of doubles.
*/
double getSmall(vector<double> v);


int main(){
    const double min = 0.0, max = 100.0;
    const int unit_count_min = 1 , unit_count_max = 4;
    const vector<string> units = {"cm", "in", "ft", "m"};
    srand(time(0));
    vector<double> nums;
    vector<string> unit;
    double temp;
    int results = 0;
    cout << "Enter how many results you would like to see: ";
    cin >> results;
    while (0 < results--){
        if(temp == '|')
            break;
        temp  = min + (double)rand()/ RAND_MAX * (max - min);
        nums.push_back(temp);
        unit.push_back(units[rand() % unit_count_max]);
    }
    double s = nums[0], l = nums[0];
    string su = unit[0], lu = unit[0];
    for(int i = 0; i < nums.size(); i++){
        cout << i << ")\t" << nums[i] << unit[i] << " ";
        if ( nums[i] < s) {
            s = nums[i];
            cout << "the smallest so far is " << s << su;
        }
        if ( nums[i] > l) {
            l = nums[i];
            cout << "the largest so far is " << l << lu;
        }

        cout << "\n";
    }

    cout << "\nThe smallest value is: " << s  << su << "\n";
    cout << "The largest value is: " << l << lu << "\n";

    if(l - s < 1.0/100.0){
        cout << "The numbers are almost equal";
    }
}

/**
 * @brief gets the largest value from a vector of doubles.
 * @param v: A vector of doubles
 * @return: returns the largest number in the vector
 */
double getLarge(vector<double> v){
    double largest = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] > largest){
            largest = v[i];
        }
    }
    return largest;
}

/**
 * @brief gets the smallest value from a vector of doubles.
 * @param v: A vector of doubles
 * @return: returns the smallest number in the vector
*/
double getSmall(vector<double> v){
    double smallest = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] < smallest){
            smallest = v[i];
        }
    }
    return smallest;
}