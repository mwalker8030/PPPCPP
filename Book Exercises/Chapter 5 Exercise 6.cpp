/**
 *     6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius f=9/5*c+32. Use estimation to see if your results are plausible
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

  double ftoc(double f){           // converts Fahrenheit to Celsius
        if(f < -459.67){
            throw invalid_argument("Temperature must be above -459.67 F");
        }
       int c = (f-32)*5/9;
       return c;
  };

  double ctof(double c){           // converts Celsius to Fahrenheit
        if(c < -273.15){
            throw invalid_argument("Temperature must be above -273.15 C");
        }
       int f = c*9/5+32;
       return f;
  };
  
  int main() try {
      double c;                    // declare input variable
       cin >> c;                       // retrieve temperature to input variable
       double k = ctok(c);           // convert temperature
       cout << k << " K\n" << ctof(c) << " F\n";          // print out temperature
  } catch (exception& e) {
        cout << e.what() << '\n';
        return 1;
  } catch (...) {
        cout << "Exiting\n";
        return 2;
  }