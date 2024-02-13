/**
 * Wite a program to play a number guessing game. The user thinks of a number between 1 
 * and 100 and your program asks questions to figure out what the number is (e.g., "is 
 * the number you are thinking of less than 50?"). Your program should be able to 
 * identify the number ater asking no more than seven questions. Hint: Use the < and <= 
 * operators and the if-else construct.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int max_v = 100, min_v = 1;

void guess_v(int v1, int q1, int count, int min_guess, int max_guess);
int main() {
    srand(time(0));
    int random_num = rand() % (max_v - min_v + 1) + min_v;
    int guess = 0;
    int question = max_v / 2;
    cout << "I'm thinking of a number between 1 and 100. What is it?" << endl;
    guess_v(100, question, 0, min_v, max_v);
}

void guess_v(int v1, int q1, int count, int min_guess, int max_guess)
{
    if(count == 7) {
        cout << "game over, it was " << v1 << endl;
        return;
    }
    count++;
    cout << " is the number " << q1 << "? ";

    if(v1 == q1){
        cout << "Yes! Congrats, you got it in " << count << " tries!" << endl;
    } else {
        cout << "No\nis the number you are thinking of less than " << q1 << ": ";
        if(v1 < q1) {
            cout << "Yes less than " << q1 << endl;
            max_guess = q1;
            q1 = min_guess + (max_guess - min_guess) / 2;
        } else {
            cout << "no, its more than " << q1 << endl;
            min_guess = q1;
            q1 = min_guess + (max_guess - min_guess)/2;
        }
        guess_v(v1, q1, count, min_guess, max_guess);
    }
}
