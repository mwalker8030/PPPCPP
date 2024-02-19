/**
 *     5. Add to the program so that it can  also convert from Kelvin to Celsius.
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

  double ktoc(double k){           // converts Kelvin to Celsius
        if(k < 0){
            throw invalid_argument("Temperature must be above 0 K");
        }
       int c = k - 273.15;
       return c;
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