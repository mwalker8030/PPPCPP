/**
 *     12. Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The program has a vector of four different integers in the range 0 to 9 and it is the user’s task to discover those numbers by repeated guess. Say the number to be guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1 cow” because the user got one digit(1) right and in the right position ( a bull) and one digit (3) right but in the wrong position (a cow). The guessing continues until the user gets four bulls, that is , has the four digits correct and in the correct order.
*/
#include <iostream>
#include <random>

using namespace std;

int randi();
void fill(vector<int> &num);
bool check(vector<int> &num, vector<int> &ans);
bool count(vector<pair<bool, bool>> result);
string plural(int n);
vector<int> num(4), ans(4);

int main(){
    cout << "Welcome to the game of Bulls and Cows!" << endl;
    fill(num);
    bool wrong = true;
    cout << "Here are the four numbers you have to guess: " << endl;
    while(wrong) {
        cout << "Enter your guess: ";
        for(int i = 0; i < 4; i++) {
            cin >> ans[i];
        }
        wrong = check(num, ans);
    }

}

int randi(){
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(0, 9);
    return dist(mt);
}

void fill(vector<int> &num){
    for(int i = 0; i < 4; i++){
        num[i] = randi();
    }
    #if 0
    cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << endl;
    #endif
}

bool check(vector<int> &num, vector<int> &ans){
    vector<pair<bool, bool>> ans_check(4, pair(false,false));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(num[i] == ans[j]){
                ans_check[i].first = true;
                ans_check[i].second = (i == j);
            }
        }
    }

    return !count(ans_check);
}

bool count(vector<pair<bool, bool>> result)
{
    int bulls = 0, cows = 0;
    for(int i = 0; i < 4; i++){
        if(result[i].first && result[i].second){
            bulls++;
        } else if (result[i].first &&!result[i].second) {
            cows++;
        }
    }
    cout << bulls << " Bull" << plural(bulls);;
    cout << " and " << cows << " Cow" << plural(cows) << endl;
    if(bulls == 4){
        cout << "Congrats! You got all four digits correct in the correct order!" << endl;
        return true;
    }else {
        fill(result.begin(), result.end(), pair(false, false));
        return false;
    }
}

string plural(int n)
{
     if(n > 1) return "s";
    return string();
}
