/**
 * Try this:
 * 
 * 	Write a program that “bleeps” out words that you don’t like; That is, you read in 
 * words using cin and print them again on cout. If a word is among a few you have 
 * defined, you write out BLEEP instead of that word. Start with one “disliked word” 
 * such as
 * 
 * 	string disliked = “Broccoli”;
 * 
 * When that works, add a few more.
*/

#include <iostream>

using namespace std;

int main(){
    string nonos = "Broccoli";
    vector<string> dic;

    for(string temp; cin >> temp;){
        dic.push_back(temp);
    }

    sort(dic.begin(), dic.end());
    
    for(int i = 0; i < dic.size(); i++){
        if (i == 0 || dic[i] != dic[i-1]){
            if(dic[i]!= nonos){
                cout << dic[i] << "\n";
            } else {
                cout << "BLEEP\n";
            }
        }
    } 
}