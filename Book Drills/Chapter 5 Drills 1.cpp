/**
 * Below are 25 code fragments. Each is meant to be inserted into this "scaffolding";
 * Each has zero or more errors. Your task is to find and remove all errors in each program. When you have removed those bugs, the resulting program will compile, run, and write "Success!"
 *  Even if you think you have spotted an error,you still need to enter the (original, unimproved) program fragment and test if; you may have guessed wrong about what the error is, or there may be more errors in a fragment than you spotted. Also, one purpose of this drill is to give you a feel for how your compiler reacts to different kinds of errors. Do not enter the scaffolding 25 times -- that's a job for cut and paste or some similar "mechanical" technique. Do not fix problems by simply deleting a statement; repair them by changing, adding, or deleting a few characters.
 * 
 * 1. Cout << "Success!\n";
 * 2. cout << "Success!\n;
 * 3. cout << "Success" << !\n"
 * 4. cout << success << '\n';
 * 5. string res = 7; vector<int> v(10); vI5] = res; cout << "Success!\n";
 * 6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout < "Success!\n";
 * 7. if (cond) cout < "Success! \n"; else cout << "Fail! \n" ;
 * 8. bool c= false; if (c) cout << "Success! \n"; else cout < "Fail! \n" ;
 * 9. string s = "ape"; boo c = "fool" <s; if (c) cout < "Success!\n" ;
 * 10. string s = "ape"; if (s=="fool") cout < "Success!\n" ;
 * 11. string s = "ape"; if (s=="fool") cout < "Success!\n";
 * 12. string s = "ape"; if (s+"fool") cout < "Success! \n";
 * 13. vector<char> v(5); for (int i=0; O<v.size(); ++i) ; cout << "Success! \n";
 * 14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success! \n";
 * 15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[il;
 * 16. if (true) then cout < "Success!\n"; else cout << "Faill!\n";
 * 17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
 * 18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << slil;
 * 19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
 * 20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
 * 21. int x = 2; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n" ;
 * 22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[il;
*/

#include <iostream>

using namespace std;

void keep_window_open(); // Declaration for the keep_window_open function

int main() try{
    /**
     * 1. Cout << "Success!\n"; -- c is capitalized
     * 2. cout << "Success!\n; -- string is not properly terminated
     * 3. cout << "Success" << !\n" -- string is not properly opened
     * 4. cout << success << '\n'; -- success is undefined
     * 5. string res = 7; vector<int> v(10); v[5]=res;cout<<"Success!\n";
     *      -- there is no conversion from int to string and vice versa
     * 6. vector<int>v(10); v(5)=7; if(v(5)!= 7) cout << "Success!\n";
     *      -- cannot assign to an element in that way
     * 7. if(cond) cout < "Success!\n"; else cout << "Fai!\n";
     *     -- cout is undefined and not a boolean type for sure
     * 8. bool c = false; if(c) cout << "Success!\n"; else cout << "Fai!\n"
     *      -- c is always false
     * 9. string s="ape";boo c="fool"<s; if (c) cout << "Success!\n" ;
     *      -- boo is not a type
     * 10. string s = "ape"; if (s=="fool") cout << "Success!\n";
     *      -- s will never be equal to "fool"
     * 11. string s = "ape"; if (s=="fool") cout < "Success!\n";
     *      -- typo after cout '<' should be <<
     * 12. string s = "ape"; if (s+"fool") cout < "Success!\n";
     *      -- typo after cout '<' should be <<
     * 13. vector<char>v(5); for (int i=0; 0<v.size(); ++i); cout << "Success!\n";
     *      -- infinite loop
     * 14.vector<char>v(5);for(int i=0; i<=v.size(); ++i); cout << "Success!\n";
     *      -- out of bunds error
     * 15. string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];
     *      -- out of bounds error
     * 16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
     *      -- then is not a keyword
     * 17. int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";
     *      -- c will never equal 2000
     * 18. string s = "Success!\n" for(int i = 0; i < 10; ++i) cout << s[i];
     *     -- out of bounds error
     * 19. vector v(5); for(int i=0; i<=v.size(); ++i); cout << "Success!\n";
     *      -- out of bounds error
     * 20. int i = 0; int j = 9; while (i < 10) ++j; if(j<i) cout << "Success!\n";
     *      -- j will never be less than i
     * 21. int x = 2; double d = 5/(x-2); if (d == 2*x+0.5) cout << "Success!\n";
     *      -- dividing by zero and d will never equal 2*x+0.5
     * 22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
     *      -- string may not have a template argument
     * 23. int i=0; while(i<10) ++j; if(j<i) cout << "Success!\n";
     *      -- infinite loop
     * 24. int x = 4; double d = 5/(x-2); if(d=2*x+0.5) cout << "Success!\n";
     *      -- cannot use an assignment operator within a if statement
     * 25. cin << "Sucess!\n"; -- cin is an output stream
    */
    /* Insert code here */
    keep_window_open();
    return 0;
} catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
} catch(...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

/**
 * used to keep the window open until the user presses a key.
*/
void keep_window_open()
{
    char ch;
    cin >> ch;
    return;
}
