/**
 * A token must be able to represent operators, such as + and -, and numeric values such as 42 and 3.14. The implementation is something that can represent what “kind” a token is and hold the numeric value for tokens that have one:

Token:
Kind:	plus
Value:

Token:
Kind: number
Value: 3.14

There are many ways that this idea could be represented in C++ code. Here is the simplest that we found useful:

Class Token {		// a simple user-defined type
Public:
	char kind;
	double value;
};
*/

#include <iostream>
#include <cstdlib>

using namespace std;
#define NUMBER '#'
#define AUTO false
#define FIN true

class Token{
    public:
        char kind;
        double value;
        Token(char k, double v): kind(k), value(v){}
        Token(char k): kind(k){
            if(k >= '0' && k <= '9'){
                value = k - '0';
                kind = NUMBER;
            } else {
                kind = k;
            }
        }
        void print() const{
            if(kind == NUMBER) cout << value;
            else cout << kind;
        }
};


int main() try {
    vector<Token> t;
#if !AUTO
#if FIN
    char c;
    while(cin >> noskipws >> c){
        if(c == '\n') break;
        if(isspace(c)) continue;
        t.push_back(Token(c));
    }
#else 
#endif
#endif
    for(const auto& token : t) { 
        token.print();
    }

    } catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
} catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}