/**
 * Redo the "Bulls and Cows" game from exercise 12 in chapter 5 to use four letters instead rather than four digits.
*/
#include <iostream>
#include <random>

using namespace std;

int randi();
void fill(vector<char> &abc);
bool check(vector<char> &abc, vector<char> &ans);
bool count(vector<pair<bool, bool>> result);
string plural(int n);
vector<char> abc(4), ans(4);

int main(){
    cout << "Welcome to the game of Bulls and Cows!" << endl;
    fill(abc);
    bool wrong = true;
    cout << "Here are the four numbers you have to guess: " << endl;
    while(wrong) {
        cout << "Enter your guess: ";
        for(int i = 0; i < 4; i++) {
            cin >> ans[i];
        }
        wrong = check(abc, ans);
    }

}

int randi(){
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(0, 9);
    return dist(mt);
}

void fill(vector<char> &abc){
    for(int i = 0; i < 4; i++){
        abc[i] = randi() + 'a';
    }
    #if 0
    cout << abc[0] << " " << abc[1] << " " << abc[2] << " " << abc[3] << endl;
    #endif
}

bool check(vector<char> &abc, vector<char> &ans){
    vector<pair<bool, bool>> ans_check(4, pair(false,false));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(abc[i] == ans[j]){
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
        } else if (result[i].first && !result[i].second) {
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
