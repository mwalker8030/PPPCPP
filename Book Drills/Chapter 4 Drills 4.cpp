/**
 * Change the program so that it uses doubles instead of ints
*/

#include <iostream>

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
    vector<double> nums;
    double temp;
    while (cin>>temp){
        if(temp == '|')
            break;
        nums.push_back(temp);
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
        if((i + 1) % 2 == 0){
            if(nums[i-1] == nums[i]){
                cout << " the numbers are equal";
            }
            cout << "\n";
        }
    }
    sort(nums.begin(), nums.end());
    cout << "\nThe smallest value is: " << getSmall(nums) << "\n";
    cout << "The largest value is: " << getLarge(nums) << "\n";

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