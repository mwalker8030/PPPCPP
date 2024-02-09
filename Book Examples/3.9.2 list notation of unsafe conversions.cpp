#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    double x {2.7};     // same as double x = 2.7;
    int y {x};         // error: double -> int conversion is unsafe
    int a {1000};       // same as int a = 1000;
    char b {a};        // error: int -> char conversion is unsafe
}