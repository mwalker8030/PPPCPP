/**
 * Let's consider a slightly different question: Once you have checked a set of arguments and found an error, what should you do? Sometimes you can return an "error value." For example:
 * Test this program with a variety of values. Print out the values of area1, area2, area3 and ratio. Insert more tests until all errors are caught. How do you know that you caught all errors? This is not a trick question; in this particular example you can give a valid argument for having caught all errors.
*/

#include <iostream>

using namespace std;

char ask_user(string question);
int area(int a, int b);
int f(int a, int b, int c);
int framed_area(int a, int b);
int main(){
    int x = 0;
    int y = 0;
    int z = 0;
    char answer = ' ';
    while(answer != 'n'){
        cout << "Enter three integers\n";
        cin >> x >> y >> z;
        f(x,y,z);
        answer = ask_user("Do you want to continue");
    }
    return 0;
}

//ask user for a yes-or-no answer;
//return 'b' to indicate a bad answer (not yes or no)

char ask_user(string question){
    cout << question << "?(yes or no)\n";
    string answer = " ";
    cin >> answer;
    if(answer == "y" || answer == "yes") return 'y';
    if(answer == "n" || answer == "no") return 'n';
    return 'b'; // 'b' for a "bad answer"
}

//calculate area of a rectangle;
//return -1 to indicate a bad argument
int area(int length, int width)
{
    if(length<=0 || width <= 0) return -1;
    return length*width;
}

int f(int x, int y, int z){
    int area1 = area(x,y);
    if(area1<=0) { cout << "non-positive area"; return 0;}
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/double(area1)/area3;
    //...
    cout << "area1 = " << area1 << "\narea2 = " << area2 << "\narea3 = " << area3 << "\nratio = " << ratio << endl;
    return 0;
}

int framed_area(int x, int y) {
    constexpr int frame_width = 2;
    if(x-frame_width<=0 || y-frame_width<=0){
        cout << "non-positive area() argument called by framed_area()";
        return 0;
    }
    return area(x-frame_width,y-frame_width);
}