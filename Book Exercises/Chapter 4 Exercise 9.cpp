/**
 * Try to calculate the number of rice grains that the inventor asked for in exercise 
 * 8. You'll find that the number is so large that it won't fit in an int or a 
 * double. What is the largest number of squares for which you can calculate the exect 
 * number of grains (using an int)? What is the largest number of squares for which 
 * you can calculate the approximate number of grains (using a double)?
 */

//int max value is -2147483647
//double max value is 1.84467e+19
#include <iostream>
#include <utility>

using namespace std;

const vector<double> ms_goals = {1000, 1000000, 1000000000};
int main(){
    double square = 1;
    double grains = 1;
    double total_grains = grains;
    double goal = 0;

    vector<pair<double, double>> current_reward = {{square, grains}};
    vector<pair<double, double>> ms;

    while (square < 64){
        square++;
        grains *= 2;
        current_reward.emplace_back(square, grains);
        total_grains += grains;
        if(total_grains >= ms_goals[goal]){
            goal++;
            ms.emplace_back(square, total_grains);
        }
    }

    for(double i = 0; i < current_reward.size(); i++){
        cout << "Square: " << current_reward[i].first << " grains: " << current_reward[i].second << "\n";
    }
    for(pair<double, double> g : ms){
        cout << "milestone reached at square: " << g.first << " total grains: " << g.second << "\n";
    }
    cout << "Total grains: " << total_grains << "\n";
}