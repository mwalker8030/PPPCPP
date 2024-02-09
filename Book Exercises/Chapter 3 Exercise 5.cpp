/**
 * Modify the program to askthe user to enter floating-point value and store them in 
 * double variables. Compare the outputs of the two programs for some inputs of your 
 * choice. Are the results the same? Should they be? What's the difference?
*/

#include <iostream>

using namespace std;

int main(){
    float val1 = 0, val2 = 0;
    cout << "Enter two floating-point values: ";
    cin >> val1 >> val2;

    if(val1 > val2){
        cout << "smaller: " << val2 << "\nlarger: " << val1 << endl;
    } else {
        cout << "smaller: " << val1 << "\nlarger: " << val2 << endl;
    }
    cout << "sum: " << val1 + val2 <<
    "\ndifference: " << val1 - val2 <<
    "\nproduct: " << val1 * val2 <<
    "\nratio: " << val1 / val2 << endl;

    /* All except the ratio is the same. which makes sense because the ratio of two 
     * floating-point values is different from the ratio of two integers. 
    */
}