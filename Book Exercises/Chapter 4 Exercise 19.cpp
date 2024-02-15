/**
 * Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

int randi();
vector<string> names = {"Aaron", "Abby", "Alex", "Alice", "Angel", "Barbara", "Bart", "Becky", "Bill", "Billy", "Bob", "Carl", "Catherine", "Cathy", "Catherine", "Charlie", "Daisy", "Dan", "Dana", "Dana", "David", "Eddie", "Eddie", "Edgar", "Edna", "Eve", "Felix", "Fiona", "Fiora", "Frank", "Franklin", "George", "Gerald", "Gina", "Gloria", "Grace", "Hank", "Handy", "Hannah", "Holly", "Hulk", "Irena", "Irene", "Ivan", "Ivanka", "Ivy", "Jack", "Jacky", "Jill", "Jilly", "Joe", "John", "Karen", "Karl", "Kathy", "Katherine", "Katie", "Lance", "Larry", "Lars", "Linda", "Liz", "Mandy", "Mary", "Mike", "Molly", "Molinda", "Nancy", "Nate", "Nathen", "Nick", "Nina", "Olive", "Oliver", "Olivia", "Oscar", "Ozzy", "Patty", "Paul", "Paulina", "Peggy", "Penelope", "Quincy", "Quintisha", "Queens", "Quinn", "Quinncy", "Ranold", "Randy", "Ren", "Rita", "Sally", "Steve", "Sue", "Terry", "Tina", "Tom", "Ulysses", "Ursula", "Vicky", "Victor", "Victoria", "Victorina", "Vince", "Walker", "Walter", "Wen", "Wendy", "Wendina", "Xander", "Xanderal", "Xanders", "Xena", "Xenador", "Yolanda", "Yolandaska", "Yola", "Yvonne", "Yvonnka", "Zach", "Zachery", "Zanders", "Zoe", "Zoesha", "Zoezoe"};
const int MAX_NAMES = names.size()-1;
const int MAX_SCORES = 100;
vector<string> namedata;
vector<int> scoredata;
bool valid(string name);
int main(){
    cout << names.size() - 1 << " names in the database" << endl;
    cout << "Enter a name and a score" << endl;
    
    while(valid ( names[randi()])){
        scoredata.push_back(randi());
    }
    cout << "Entered names and scores:\n";
    for(int i = 0; i < scoredata.size(); i++){
        cout << namedata[i] << " " << scoredata[i] << endl;
    }
    return 0;
}

int randi(){
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(0, 100);
    return dist(mt);
}

bool valid(string name)
{
    if(name == "NoName"){
        return false;
    }

    for(int i = 0; i < namedata.size(); i++){
        if(namedata[i] == name){
            cout << name << " is already in the database" << endl;
            return false;
        }
    }
    namedata.push_back(name);
    return true;
}
