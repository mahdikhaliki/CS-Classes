//
//  main.cpp
//  Midterm
//
//  Created by Mahdi Khaliki on 10/24/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int c = 0;

void f() {
    int n;
    cin >> n;
    if (n > 0) {
        f();
        cout << n*n << " ";
    }
    else cout << "X ";
}

bool mystery(string w) {
    stack<char> stk;
    int i;
    for (i = 0; i < w.length() && w[i] == 'a'; i++) {
        stk.push('X');
        stk.push('X');
    }
    for (; i < w.length();i++)
        if (w[i] != 'b' || stk.empty())
            return false;
        else
            stk.pop();
    return stk.empty();
}

void g(int a[], int n) {
    c++;
    if (n <= 1) return;
    c++;
    if (a[0] > a[1])
        swap(a[0], a[1]);
    g(a+1,n-1);
}
void h(int a[], int n) {
    c++;
    if (n <= 1) return;
    g(a,n);
    h(a,n-1);
}

int main(int argc, const char * argv[]) {
    string s[4] = {"", "a", "b", "ab"};
    int a[6] = {1, 2, 3, 4, 5, 6};
//    for (int i = 0; i < 4; i++)
//        cout << mystery(s[i]) << endl;
//    f();
    
//    stack<int> stk;
//    queue<int> q;
//    for (int i = 0; i < 5; i++) {
//        stk.push(i);
//    }
//    while (!stk.empty()) {
//        q.push(stk.top());
//        stk.pop();
//    }
//    for (int i = 0; i < 5; i++) {
//        cout << q.front() << endl;
//        q.pop();
//    }
    
    h(a, 6);
    cout << c << endl;
}


