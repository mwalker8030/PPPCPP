/**
 * Reject values without units or with "illegal" representations of units, such as y, 
 * yard, meter, km, and gallons.
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

/**
 * convert a double into the smallest unit for comparison.
*/
double convert(double v, string u);
    const double min_num = 0.0, max_num = 100.0;
    const int unit_count_max = 5;
    const vector<string> units = {"cm", "in", "ft", "m", "ierror"};
    const vector<double> unit_cm_conversions = {1, 2.54, 12*2.54, 100, 0};
int main(){
    srand(time(0));
    vector<double> nums;
    vector<string> unit;
    double temp;
    string temp_unit;
    int results = 0;
    cout << "Enter how many results you would like to see: ";
    cin >> results;
    while (0 < results--){

        temp_unit = units[rand() % unit_count_max];
        temp  = min_num + (double)rand()/ RAND_MAX * (max_num - min_num);
        if(temp_unit == "ierror" )
            continue;
        if(temp == '|')
            break;
        unit.push_back(temp_unit);
        nums.push_back(temp);
    }
    double s = nums[0], l = nums[0];
    string su = unit[0], lu = unit[0];
    for(int i = 0; i < nums.size(); i++){
        cout << i << ")\t" << nums[i] << unit[i] << " ";
        if ( convert(nums[i], unit[i]) < convert(s, su)) {
            s = nums[i];
            su = unit[i];
            cout << "the smallest so far is " << s << su;
        }
        if ( convert(nums[i], unit[i]) > convert(l, lu)) {
            l = nums[i];
            lu = unit[i];
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

double convert(double v, string u)
{
    for(int i = 0; i < units.size(); i++){
        if(units[i] == u){
            return unit_cm_conversions[i] * v;
        }
    }
    return 0.0;
}
