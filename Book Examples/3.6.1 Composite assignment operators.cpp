#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
    int num_words = 0;
    string prev = " ";         // previous word; initialized to “not a word”
    string current;         // current word
    while (cin>>current){   // while there are more words to read
        num_words++;
        if(prev == current) {   // check if the word is the same as prev
            if(prev == current)
                cout << "word number " << num_words << "repeated word: " << current << '\n';
            prev = current;
        }
    }
}