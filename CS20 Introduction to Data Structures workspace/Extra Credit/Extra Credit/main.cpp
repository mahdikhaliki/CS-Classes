//
//  main.cpp
//  Extra Credit
//
//  Created by Mahdi Khaliki on 9/19/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include <iostream>
using namespace std;

int count = 0;

long long int f1(int n, int &count) {
    count++;
    if (n-- == 0) return 1;
    return f1(n, count)+ f1(n, count);
}


long long  int f2(int n, int &count) {
    count++;
    if (n-- == 0) return 1;
    return f2(n, count)*2;
}


long long  int f3(int n, int &count) {
    count++;
    if (n == 0) return 1;
    if (n % 2 == 1) return  f3(n-1, count)*2;
    n /= 2;
    return f3(n, count)*f3(n, count) ;
}


long long  int f4(int n, int &count) {
    count++;
    if (n == 0) return 1;
    if (n % 2 == 1) return f4(n-1, count)*2;
    long long int temp = f4(n/2, count);
    return temp*temp;
}

int main(int argc, const char * argv[]) {
    int count = 0;
    for (int i = 0; i < 36; i++) {
        //cout << "reset" << endl;
        f4(i, count);
        cout << count << endl;
        count = 0;
    }
    return 0;
}
