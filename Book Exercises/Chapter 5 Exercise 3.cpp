/**
 *     3. Absolute zero is the lowest temperature that can be reached; it is - 273.15, or 
 * 0K. The above program, even when corrected will produce erroneous results when given a te
 * rmerature below this. Place a check in the main program that will produce an error if a 
 * temperature is given below -273.15 C
*/
#include <iostream>

using namespace std;
 double ctok(double c){           // converts Celsius to Kelvin
        if(c < -273.15){
            throw invalid_argument("Temperature must be above -273.15 C");
        }
       int k = c + 273.15;
       return k;
  };
  int main() try {
      double c;                    // declare input variable
       cin >> c;                       // retrieve temperature to input variable
       double k = ctok(c);           // convert temperature
       cout << k << '\n';          // print out temperature
  } catch (exception& e) {
        cout << e.what() << '\n';
        return 1;
  } catch (...) {
        cout << "Exiting\n";
        return 2;
  }