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
#define LOG false                //log output
#define PAUSE false             //pause program
class Token{
    public:
        char kind;
        double value;
        Token(char k, double v): kind(k), value(v){i = 0; head = i; tail = i;}
        Token(char k): kind(k){
            i = 0;
            if(k >= '0' && k <= '9'){
                value = k - '0';
                kind = NUMBER;
            } else {
                kind = k;
            }
        }
        void set_head(){head = 0;}
        void set_tail(vector<Token> &t){tail = t.size();}

        Token get_token(vector<Token>& t){
            if(i == t.size()){
                return Token(WS);
            }
            return t[i++];
        }
        void return_token(){
            if(i == 0){
                return;
            }
            i--;
        }
        void print() const{
            if(kind == NUMBER) cout << value;
            else cout << kind;
        }

        void reset(vector<Token> &t){
            i = 0;
            head = 0;
            tail = 0;
            t.clear();
        }
    private:
    static int i, head, tail;
};

class Token_stream{
    public:
        Token get();
        void putback(Token t);
    private:

};


int Token::i = 0;
int Token::head = 0;
int Token::tail = 0;

map<char,int> precedence;

void log(string s);

double expression(vector<Token>& t);
double term(vector<Token>& t);
double primary(vector<Token>& t);

void pause();

void intotoken(vector<Token>& t);

string temp;
int main() try {
    vector<Token> t;
#if !AUTO
#if FIN
    intotoken(t);
#else 
#endif
#endif
    while(!t.empty()) {
        for(const auto& token : t) { 
            token.print();
        }
        cout << " = " << expression(t) << endl;
        t[0].reset(t);
        cout << "Enter empty expression to exit: \n";
        intotoken(t);
    }
} catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
} catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}


double expression(vector<Token> &t){
    
    double lval = term(t);
    log("\nExpression: lval = " + to_string(lval));
    Token tk = t[0].get_token(t);
    log("\nExpression: Token: " + string(1, tk.kind));
    while(true){
        pause();
        log("\nExpression loop Token: " + string(1, tk.kind));
        switch(tk.kind){
            case '+':
                log("\nExpression: Plus: " + to_string(lval));
                lval += term(t);
                log("\nExpression: Equals: " + to_string(lval));
                tk = t[0].get_token(t);
                break;
            case '-':
                log("\nExpression: Minus: " + to_string(lval));
                lval -= term(t);
                log("\nExpression: Equals: " + to_string(lval));
                tk = t[0].get_token(t);
                break;
            default:
                t[0].return_token();
                return lval;
        }
    }
}

double term(vector<Token>& t){
    log("\nTerm : ");
    double lval = primary(t);
    log("\nTerm: lval = " + to_string(lval));
    Token tk = t[0].get_token(t);
    while(true){
        log("\nTerm: Token: " + string(1, tk.kind));
        pause();
        switch(tk.kind){
            case '*':
                log("\nTerm: Multiplication: " + to_string(lval));
                lval *= primary(t);
                log("\nTerm: Equals: " + to_string(lval));
                tk = t[0].get_token(t);
                break;
            case '/':
            {
                log("\nTerm: Division: " + to_string(lval));
                double d = primary(t);
                if(d == 0){
                    throw runtime_error("Division by zero");
                }
                lval /= d;
                log("\nTerm: Equals: " + to_string(lval));
                tk = t[0].get_token(t);
                break;
            }
            default:
                if(tk.kind != WS && tk.kind != NUMBER){
                    t[0].return_token();
                }
                log( "\nTerm: Returning: " + to_string(lval));
                return lval;
        }
    }
}


double primary(vector<Token>& t){
    Token tk = t[0].get_token(t);
    log("\nPrimary: Token: " + string(1, tk.kind));
    switch(tk.kind){
        case '(': {
            double d = expression(t);
            tk = t[0].get_token(t);
            log("\nPrimary: Next Token: " + string(1, tk.kind));
            if(tk.kind != ')'){
                throw runtime_error("')' expected");
            }
            return d;
        }
        case NUMBER:
            log("\nPrimary: Number: " + to_string(tk.value));
            return tk.value;
        default:
            throw runtime_error("Primary expected");
    }
}

void log(string s){
#if LOG    
    cout << s << endl;
#endif    
}

void pause() {
#if PAUSE    
    getline(cin, temp);
#endif    
}

void intotoken(vector<Token> &t){
    char c;
    double buffer;
    while(cin >> noskipws >> c){
        if(c == WS) break;
        if(c >= '0' && c <= '9'){
            cin.putback(c);
            cin >> buffer;
            t.push_back(Token(NUMBER, buffer));
            continue;
        }
        if(isspace(c)) continue;
        t.push_back(Token(c));
    }
}
