/**
 * Read a sequence of double values into a vector. Think of each value as the distance 
 * between two cities along a given route. Compute and print the total distance (the sum 
 * of all distances). Find and print the smallest and greatest distance between two 
 * neighboring cities. Find and print the mean distance between two neighboring cities.
 * For this execise, I'm not sure what would count as a neighboring city. Is it two
 * cities next to one another because of their index? It cant be because of their 
 * distance because there is no way to know which city is next to which city. I'm going 
 * to assume that the cities are next to each other because of their index.
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

/**
 * convert a double into the desired unit.
*/
double convert(double v, string u1, string desired_unit);

const double min_num = 0.0, max_num = 100.0;
const int unit_count_max = 5;
const vector<string> units = {"cm", "in", "ft", "m", "ierror"};
const vector<double> unit_cm_conversions = {1, 2.54, 12*2.54, 100, 0};

int main(){
    srand(time(0));
    int median = 0;
    vector<double> nums;
    vector<double> recods;
    vector<string> unit;
    double temp, sum = 0.0, sum_not_converted = 0.0;
    string temp_unit;
    int results = 0;
    cout << "Enter how many results you would like to see: ";
    cin >> results;
    median = results / 2;
    while (0 < results){

        temp_unit = units[rand() % unit_count_max];
        temp  = min_num + (double)rand()/ RAND_MAX * (max_num - min_num);
        if(temp_unit == "ierror" )
            continue;
        if(temp == '|')
            break;
        unit.push_back(temp_unit);
        nums.push_back(temp);
        recods.push_back(convert(temp, temp_unit, "m"));
        results--;
    }

#if 1
    cout << "\n";
    double s = nums[0], l = nums[0];
    string su = unit[0], lu = unit[0];
    double prev = nums[0];
    for(double dist: nums){
        if(dist < s){
            s = dist;
        }
        if(dist > l){
            l = dist;
        }
        sum += dist;
        cout << "distance: " << dist << "\n";
    }

    cout << "the smallest distance is: " << s << " miles\n";
    cout << "the largest distance is: " << l << " miles\n";
    cout << "the average distance is: " << sum / nums.size() << " miles\n";
#else
#endif
    #if 0
    for(int i = 0; i < nums.size(); i++){
        sum += convert(nums[i], unit[i] , "m");     //convert to meters and add to total
        sum_not_converted += nums[i];
        if ( convert(nums[i], unit[i]) < convert(s, su)) {
            s = nums[i];
            su = unit[i];
            cout << "the smallest so far is " << s << su << "\n";
        }
        if ( convert(nums[i], unit[i]) > convert(l, lu)) {
            l = nums[i];
            lu = unit[i];
            cout << "the largest so far is " << l << lu << "\n";
        }
    }

    sort(nums.begin(), nums.end());
    sort(recods.begin(), recods.end());
    for(int i = 0; i < nums.size(); i++){
        cout << i << ")\t" << nums[i] << unit[i] << "\n";
    }

    cout << "\n";
    cout << "\nThe smallest value is: " << s  << su << "\n";
    cout << "The largest value is: " << l << lu << "\n";
    cout << "The sum of the values is: " << sum << " meters\n";
    cout << "The number of values entered is: " << nums.size() << "\n";
    cout << "The sum of values not converted is: " << sum_not_converted << "\n";
    cout << "The median value is: " << nums[median] << " " << unit[median] << "\n";
    if(l - s < 1.0/100.0){
        cout << "The numbers are almost equal";
    }
    

    cout << "the records of all the measurements are: \n";
    for(int i = 0; i < recods.size(); i++){
        cout << i << ")\t" << recods[i] << " meters\n";
    }
    return 0;
    #endif
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

double convert(double v, string u1, string desired_unit)
{
    double val = convert(v, u1);
    for(int i = 0; i < units.size(); i++){
        if(units[i] == desired_unit){
            return val / unit_cm_conversions[i];
        }
    }
    return 0.0;
}
