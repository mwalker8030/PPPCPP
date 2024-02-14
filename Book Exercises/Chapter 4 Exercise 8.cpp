/**
 * There is an old story that the emperor wanted to thank the inventor of the game of 
 * chess and asked the inventor to name his reward. The inventor asked for one grain of 
 * rice for the first square, 2 for the second, 4 for the third, and so on, doubling 
 * for each of the 64 squares. That may sound modest, but there wasn't that much rice 
 * in the empire! Write a program to calculate how many squares are required to give 
 * the inventor at least 1000 grains of rice, at least 1000000 grains, and at least 
 * 1000000000 grains. You'll need a loop, of course, and probably an int to keep track 
 * of which square we're on, and an int to keep the number of grains on the current 
 * square. and an int to keep track of the number of grains on all previous squares. We 
 * suggest that you write out the value of all your variables for each iteration of the 
 * loop so that you can see what's going on.
 */

#include <iostream>
#include <utility>

using namespace std;

const vector<int> ms_goals = {1000, 1000000, 1000000000};
int main(){
    int square = 1;
    int grains = 1;
    int total_grains = grains;
    int goal = 0;

    vector<pair<int, int>> current_reward = {{square, grains}};
    vector<pair<int, int>> ms;

    while (square < 64 && ms.size() < ms_goals.size()){
        square++;
        grains *= 2;
        current_reward.emplace_back(square, grains);
        total_grains += grains;
        if(total_grains >= ms_goals[goal]){
            goal++;
            ms.emplace_back(square, total_grains);
        }
    }

    for(int i = 0; i < current_reward.size(); i++){
        cout << "Square: " << current_reward[i].first << " grains: " << current_reward[i].second << "\n";
    }
    for(pair<int, int> g : ms){
        cout << "milestone reached at square: " << g.first << " total grains: " << g.second << "\n";
    }
    cout << "Total grains: " << total_grains << "\n";
}