/**
 * 3. Add a factorial operator: use a suffix ! Operator to represent “factorial.” For example, the expression 7! Means 7*6*5*4*3*2*1. Make ! Bind tighter than * and /; that is, 7 * 8! Means 7*(8!) rather than (7*8)!. Begin by modifying the grammar to account for a higher-level operator. To agree with the standard mathematical definition of factorial, let 0! Evaluate to 1. Hint: the calculator functions deal with doubles, but factorial is defined only for ints, so just for x!, assign the x to an int and calculate the factorial of that int.
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
double fact(vector<Token>& t);
double primary(vector<Token>& t);
bool check_whole_number(double val);
double factorial(double n);

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
    double lval = fact(t);
    log("\nTerm: lval = " + to_string(lval));
    Token tk = t[0].get_token(t);
    while(true){
        log("\nTerm: Token: " + string(1, tk.kind));
        pause();
        switch(tk.kind){
            case '*':
                log("\nTerm: Multiplication: " + to_string(lval));
                lval *= fact(t);
                log("\nTerm: Equals: " + to_string(lval));
                tk = t[0].get_token(t);
                break;
            case '/':
            {
                log("\nTerm: Division: " + to_string(lval));
                double d = fact(t);
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

double fact(vector<Token>& t){
    double lval = primary(t);
    Token tk = t[0].get_token(t);
    while(true){
        switch(tk.kind){
            case '!':{
                check_whole_number(lval) ? lval = factorial(lval) : throw runtime_error("Factorial not defined for non-integers");
                tk = t[0].get_token(t);
                break;
            }
            default:
                if(tk.kind != WS && tk.kind != NUMBER){
                    t[0].return_token();
                }
                return lval;
        }
    }
}

bool check_whole_number(double val){
    if(val == floor(val)){
        return true;
    }
    return false;
}

double factorial(double val) {
    if(val <= 1){return 1;}
    return val * factorial(val - 1);
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
        case '{':{
            double d = expression(t);
            tk = t[0].get_token(t);
            log("\nPrimary: Next Token: " + string(1, tk.kind));
            if(tk.kind!= '}'){
                throw runtime_error("'}' expected");
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
