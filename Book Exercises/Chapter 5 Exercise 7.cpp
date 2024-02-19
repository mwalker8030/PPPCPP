/**
 *     7. Quadratic equations are of the form ax^2 + bx + c = 0. There is a problem, though: if b^2-4ac is less than zero, then it will fail. Write a program that can calculate x for a quadratic equation. Create a function that prints out the roots of a quadratic equation, given a, b, c. When the program detects an equation with no real roots, have it print out a message. How do you know that your results are plausible? Can you check that they are correct?
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>

using namespace std;

double randd();
void roots(double a, double b, double c, vector<double> &x);
void check(double a, double b, double c, vector<double> &x);
void print_values(double a, double b, double c, vector<double> &x);
int main() try {
    vector<double> x(2);
    double a, b, c;
    a = randd();
    b = randd();
    c = randd();
    roots(a, b, c, x);
    check(a, b, c, x);
    print_values(a, b, c, x);    
} catch (exception &e) {
    cout << e.what() << '\n';
    return 1;
} catch (...) {
    cout << "Exiting\n";
    return 2;
}

double randd(){
    mt19937 mt(random_device{}());
    static uniform_real_distribution<double> dist(0.0, 100.0);
    return dist(mt);
}

void roots(double a, double b, double c, vector<double> &x)
{
    if (a == 0) {
        throw invalid_argument("a cannot be zero");
    }

    double determinant = b * b - 4 * a * c;
    if(determinant < 0){
        throw invalid_argument("No real roots, determinant < 0");
    }

    x[0] = (-b + sqrt(determinant)) / (2 * a);
    x[1] = (-b - sqrt(determinant)) / (2 * a);
}

void check(double a, double b, double c, vector<double> &x){
    if(a*pow(x[0], 2) + b*x[0] + c <= 1e-9 && a*pow(x[1], 2) + b*x[1] + c <= 1e-9){
        cout << "Roots are correct" << endl;
    } else {
        cout << "Roots are incorrect" << endl;
    }
}

void print_values(double a, double b, double c, vector<double> &x){
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "x1 = " << x[0] << endl;
    cout << "x2 = " << x[1] << endl;

    cout << "ax^2 + bx + c = " << a*pow(x[0], 2) + b*x[0] + c << endl;
    cout << "ax^2 + bx + c = " << a*pow(x[1], 2) + b*x[1] + c << endl;
}
