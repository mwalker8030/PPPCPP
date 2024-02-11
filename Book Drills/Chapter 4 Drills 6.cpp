/**
 * Now Change the body of the loop so that it reads just one double each time around. 
 * Define two variables to keep track of which is the smallest and which is the largest 
 * value you have seen so far. Each time trhough the loop write out the value entered. 
 * If it's the smallest so far, write the smallest so far after the numer. It it is the 
 * largest so far, write the largest so far after the number.
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
    srand(time(0));
    vector<double> nums;
    double temp;
    int results = 0;
    cout << "Enter how many results you would like to see: ";
    cin >> results;
    while (0 < results--){
        if(temp == '|')
            break;
        temp  = min + (double)rand()/ RAND_MAX * (max - min);
        nums.push_back(temp);
    }
    double s = nums[0], l = nums[0];

    for(int i = 0; i < nums.size(); i++){
        cout << i << ")\t" << nums[i] << " ";
        if ( nums[i] < s) {
            s = nums[i];
            cout << "the smallest so far is " << s;
        }
        if ( nums[i] > l) {
            l = nums[i];
            cout << "the largest so far is " << l;
        }

        cout << "\n";
    }

    cout << "\nThe smallest value is: " << s << "\n";
    cout << "The largest value is: " << l << "\n";

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