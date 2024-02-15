/**
 * 17. Write a program to solve quadratic equations. A quadratic equation is of the 
 * form axsquared +bx + c=0 If you don't know the quadratic formula for solving such an 
 * expression, do some research. Re-member, researching how to solve a problem is often 
 * necessary before a programmer can teach the computer how to solve it. Use doubles 
 * for the user inputs for a, b, and c. Since there are two solutions to a quadratic 
 * equation, output both x1 and x2.
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <cmath>
#include <limits>


using namespace std;
double minv = 0.0, maxv = 12;
double randd();
void quad(double a, double b, double c);
int main(){
    double a, b, c;
    cout << "Enter a, b and c: ";
    a = randd();
    c = randd();
    minv = sqrt(4 * a * c);
    maxv = minv + 10;
    b = randd();
    quad(a, b, c);
}

double randd()
{
    static mt19937 mt(random_device{}());
    uniform_real_distribution<double> dist(minv, maxv);
    return dist(mt);
}

void quad(double a, double b, double c){
    cout << "(-" << b << " +/- sqrt(" << b << "^2 - 4 * " << a << " * " << c << "))" 
                            << "/(2 * " << a << ") = ";
    double disc = b * b - 4 * a * c;

    if(disc < 0){ //if value is negative it means no real roots
        cout << "No real roots" << endl;
        return;
    }

    double sq = sqrt(b * b - 4 * a * c);
    double sqp = -b + sq;
    double sqn = -b + sq;
    double ansp = sqp / (2 * a);
    double ansn = sqn / (2 * a);
    cout << "x = {" << ansn << ", " << ansp << "}" << endl;

    // Check if the solutions are correct
    if (abs(a * ansp * ansp + b * ansp + c) < 1e-9 && abs(a * ansn * ansn + b * ansn + c) < 1e-9) {
        cout << "The solutions are correct." << endl;
    } else {
        cout << "The solutions are incorrect." << endl;
    }
}
