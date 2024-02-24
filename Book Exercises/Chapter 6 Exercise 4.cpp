/**
 * 4. Define a class Name_value that holds a string and a value. Rework Exercise 19 in chapter 4 to use a Vector<Name_Value> instead of vectors.

 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

int randi();
vector<string> names = {"Aaron", "Abby", "Alex", "Alice", "Angel", "Barbara", "Bart", "Becky", "Bill", "Billy", "Bob", "Carl", "Catherine", "Cathy", "Catherine", "Charlie", "Daisy", "Dan", "Dana", "Dana", "David", "Eddie", "Eddie", "Edgar", "Edna", "Eve", "Felix", "Fiona", "Fiora", "Frank", "Franklin", "George", "Gerald", "Gina", "Gloria", "Grace", "Hank", "Handy", "Hannah", "Holly", "Hulk", "Irena", "Irene", "Ivan", "Ivanka", "Ivy", "Jack", "Jacky", "Jill", "Jilly", "Joe", "John", "Karen", "Karl", "Kathy", "Katherine", "Katie", "Lance", "Larry", "Lars", "Linda", "Liz", "Mandy", "Mary", "Mike", "Molly", "Molinda", "Nancy", "Nate", "Nathen", "Nick", "Nina", "Olive", "Oliver", "Olivia", "Oscar", "Ozzy", "Patty", "Paul", "Paulina", "Peggy", "Penelope", "Quincy", "Quintisha", "Queens", "Quinn", "Quinncy", "Ranold", "Randy", "Ren", "Rita", "Sally", "Steve", "Sue", "Terry", "Tina", "Tom", "Ulysses", "Ursula", "Vicky", "Victor", "Victoria", "Victorina", "Vince", "Walker", "Walter", "Wen", "Wendy", "Wendina", "Xander", "Xanderal", "Xanders", "Xena", "Xenador", "Yolanda", "Yolandaska", "Yola", "Yvonne", "Yvonnka", "Zach", "Zachery", "Zanders", "Zoe", "Zoesha", "Zoezoe"};
class Name_value{
    public:
        string name;
        int score;
        Name_value(string name, int score){
            this->name = name;
            this->score = score;
        }
};
const int MAX_NAMES = names.size()-1;
const int MAX_SCORES = 100;
vector<string> namedata;
vector<int> scoredata;
bool valid(vector<Name_value> &nv);
int main(){
    vector<Name_value> nv;
    cout << names.size() - 1 << " names in the database" << endl;
    cout << "Enter a name and a score" << endl;
    valid(nv);
    cout << "Entered names and scores:\n";
    for(int i = 0; i < nv.size(); i++){
        cout << nv[i].name << " " << nv[i].score << endl;
    }
    return 0;
}

int randi(){
    static mt19937 mt(random_device{}());
    static uniform_int_distribution<int> dist(0, 100);
    return dist(mt);
}

bool valid(vector<Name_value> &nv){
    int i = randi();
    string name = names[i];
    nv.push_back(Name_value(name, i));
    while(true){
        i = randi();
        name = names[i];
        for(int i = 0; i < nv.size(); i++){
            if(nv[i].name == name){
                cout << name << " is already in the database" << endl;
                return false;
            }
        }
        nv.push_back(Name_value(name, i));
    }

    return false;
}
