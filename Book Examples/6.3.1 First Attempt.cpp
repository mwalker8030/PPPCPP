#include <iostream>

using namespace std;

int main(){
    cout << "Please enter expression (we can handle + and -): ";
    int lval = 0;
    int rval;
    char op;
    int res;
    string temp;
    cin >> lval >> op >> rval; //read something like 1 + 3

    if(op == '+'){
        res = lval + rval; // addition
    } else if(op == '-'){
        res = lval - rval; // subtraction
    }
    cout << res << endl;
    cin>>temp;
    return 0;
}