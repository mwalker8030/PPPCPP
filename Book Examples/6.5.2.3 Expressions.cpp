/**
 * Any expression starts with a Term and such a Term can be followed by a + or a -. So, we have to look for a Term, see if it is followed by a + or a -, and keep doing that until there are no more plusses or minuses. For example:

	double expression() {
		double left = term();		//read and evaluate a term
		token t = get_token();		//get the next token
		while (t.kind==‘+’ || t.kind==‘-‘) {	// look for a + or a -
			if(t.kind == ‘+’)
				left += term();		//evaluate term and add
			else
				left -= term();			//evaluate term and subtract
			t = get_token();
		}
		return left;
	}

This is a bit messier: we had to introduce a loop to keep looking for plusses and minuses. We also got a bit repetitive: we test for + and - twice and  call get_token(). Because it obscures the logic of the code, let’s just get rid of the duplication of the test for + and -:

	double expression() {
		double left = term();			//read and evaluate a term
		token t = get_token();			//get the next token
		while(true) {
			switch (t.kind) {
				case ‘+’:
					left += term();
					t = get_token();
					break;
				case ‘-‘:
					left -= term();
					t = get_token();
					break;
				default:
					return left;
			}
		}
	}

Note that - except for the loop - this is actually rather similar to our first try. What we have done is to remove the mention of expression() within expression() and replace it with a loop. In other words, we translated the expression in the grammar rules for expression into a loop looking for a term followed by a + or a -.
*/

#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;
#define NUMBER '#'              //indicates a read number
#define AUTO false              //Automatic random input
#define FIN true                //Final alteration of code
#define WS '\n'                 //white space
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
map<char,int> precedence;



double expression(vector<Token>& t);
Token get_token(vector<Token>& t);

int main() try {
    vector<Token> t;
#if !AUTO
#if FIN
    char c;
    while(cin >> noskipws >> c){
        if(c == WS) break;
        if(isspace(c)) continue;
        t.push_back(Token(c));
    }
#else 
#endif
#endif
    for(const auto& token : t) { 
        token.print();
    }
    cout << " = " << expression(t) << endl;

    } catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
} catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}


double expression(vector<Token> &t){
    Token tk = get_token(t);
    double lval = 0;
    if(tk.kind == NUMBER){
        lval = tk.value;
        tk = get_token(t);
        if(tk.kind != WS && tk.kind!= NUMBER){
            if(tk.kind == '+'){
                return lval + expression(t);
            } else if(tk.kind == '-'){
                return lval - expression(t);
            }
        }else if (tk.kind == NUMBER){
            throw runtime_error("Invalid expression");
        }else if (tk.kind == WS){
            return lval;
        }
    }
    return lval;
}

Token get_token(vector<Token> &t)
{
    static int i = 0, head = 0, tail = t.size() - 1;
    if(i > tail) return Token(WS);
    return t[i++];
}


