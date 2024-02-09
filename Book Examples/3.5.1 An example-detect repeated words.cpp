#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    string prev = " ";         // previous word; initialized to “not a word”
    string current;         // current word
    while (cin>>current){   // while there are more words to read
        if(prev == current) {   // check if the word is the same as prev
            if(prev == current)
                cout << "repeated word: " << current << '\n';
            prev = current;
        }
    }
}