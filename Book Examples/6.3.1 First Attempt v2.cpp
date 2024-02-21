/**
 * This is not bat, but when we try 1+2*3 and see that the result is 9 and not the 7 our arithmetic teachers told us was the right answer. Similarly, 1-2*3 gives -3 rather than the -5 we expected. We are doing the operations in the wrong order: 1+2*3 is calculated as (1+2)*3 rather than a s the conventional 1+(2*3). Similarly, 1-2*3 is calculated as (1-2)*3 rather than as the conventional 1-(2*3). Bummer! we might consider the convention that "multiplication binds tighter than addition" as a silly old convention, but hundreds of yeas of convention will not disappear just to simplify our programming.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() try {
    cout << "Please enter expression (we can handle +, -, *, and /): ";
    cout << "add an x to end expression (e.g. 1.2*3x): ";
    int lval = 0;
    int rval;
    char op, temp;
    cin >> lval;
    if(!cin) throw invalid_argument("no first operand");
    for(char op; cin>>op;) { //read operator and right-hand operand repeatedly
        if(op != 'x') cin >> rval;
        if(!cin) throw invalid_argument("no second operand");
        switch(op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result: " << lval << endl;
                cin >> temp;
                return 0;
        }
    }

} catch(exception& e) {
    cout << e.what() << endl;
    return 1;
}catch(...){
    cout << "Unknown error" << endl;
    return 2;
}