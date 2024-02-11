/**
 * Change the program to write out the smaller value is: followed by the smaller of the 
 * numbers and the larger value is: follewed by the larger value.
*/

#include <iostream>

using namespace std;
/**
 * @brief gets the largest value from a vector of integers.
 * @param v: A vector of integers
 * @return: returns the largest number in the vector
*/
int getLarge(vector<int> v);
/**
 * @brief gets the smallest value from a vector of integers.
 * @param v: A vector of integers
 * @return: returns the smallest number in the vector
*/
int getSmall(vector<int> v);

int main(){
    vector<int> nums;
    double temp;
    while (cin>>temp){
        if(temp == '|')
            break;
        nums.push_back(temp);
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
        if((i + 1) % 2 == 0)
            cout << "\n";
    }
    sort(nums.begin(), nums.end());
    cout << "\nThe smallest value is: " << getSmall(nums) << "\n";
    cout << "The largest value is: " << getLarge(nums) << "\n";

}

/**
 * @brief gets the largest value from a vector of integers.
 * @param v: A vector of integers
 * @return: returns the largest number in the vector
 */
int getLarge(vector<int> v){
    int largest = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] > largest){
            largest = v[i];
        }
    }
    return largest;
}

/**
 * @brief gets the smallest value from a vector of integers.
 * @param v: A vector of integers
 * @return: returns the smallest number in the vector
*/
int getSmall(vector<int> v){
    int smallest = v[0];
    for(int i = 0; i < v.size(); i++){
        if(v[i] < smallest){
            smallest = v[i];
        }
    }
    return smallest;
}