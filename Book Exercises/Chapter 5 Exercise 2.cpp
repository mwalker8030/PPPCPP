/**
 * The following code has many errors in it finde them all and fix them.
 * 
 * double ctok(double c){           // converts Celsius to Kelvin
 *      int k = c + 273.15;
 *      return int
 * }
 * int main(){
 *     double c;                    // declare input variable
 *      cin >> d;                       // retrieve temperature to input variable
 *      double k = ctok("c");           // convert temperature
 *      Cout << k << '/n';          // print out temperature
 * }
*/
#include <iostream>

using namespace std;
 double ctok(double c){           // converts Celsius to Kelvin
       int k = c + 273.15;
       return k;
  };
  int main(){
      double c;                    // declare input variable
       cin >> c;                       // retrieve temperature to input variable
       double k = ctok(c);           // convert temperature
       cout << k << '\n';          // print out temperature
  }