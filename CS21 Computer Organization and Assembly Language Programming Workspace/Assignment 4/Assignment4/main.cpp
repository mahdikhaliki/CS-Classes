//
//  main.cpp
//  Assignment4
//

#include <iostream>
using namespace std;

void Exercise1() {
        string s = "ABCDEFG";
        int i = 0;
        cout << s << endl;              // Print original DONE
        while(s[i]) {                   // While the pointer is not at the null
                s[i++] += 32;
        }
        
        cout << s << endl;
}

void Exercise2() {
        string s = "in a  hole in the  ground there lived a hobbit";
        char prev = ' ';
        int i = 0;
        
        while(s[i]) {
                if (prev == ' ' && s[i] != ' ') {
                        s[i] -= 32;
                        prev = s[i++];
                }
                else {
                        prev = s[i++];
                }
        }
        cout << s << endl;
}

void Exercise3() {
        string s = "in a  Hole in the  Ground there Lived a hobbit";
        char prev = '\0';
        int i = 0;
        
        while(s[i]) {
                if ((prev == ' ' || prev == '\0') && s[i] >= 97) {
                        s[i] -= 32;
                        prev = s[i++];
                }
                else {
                        prev = s[i++];
                }
        }
        cout << s << endl;
}



int main() {
        Exercise2();
//        Exercise3();
        char s[50];

        
        
        return 0;
}
