/**
 *     13. The program is a bit tedious because the answer is hard-coded into the program. Make a version where the user can play repeatedly (without stopping and restarting the program) and each game has a new set of four digits.
*/
#include <iostream>
#include <random>

using namespace std;

int randi();
void fill(vector<int> &num);
bool check(vector<int> &num, vector<int> &ans);
bool count(vector<pair<bool, bool>> result);
void play();
string plural(int n);
vector<int> num(4), ans(4);

int main(){
    cout << "Welcome to the game of Bulls and Cows!" << endl;
    bool playagain = true;
    char ch = 'y';
    while(playagain){
        play();
        cout << "Play again? (y/n): ";
        cin >> ch;
        if(ch == 'y'){ playagain = true; }
        else { playagain = false; }
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

void play()
{
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
