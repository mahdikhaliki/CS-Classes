//
//  main.cpp
//  Midterm programs
//
//  Created by Mahdi Khaliki on 3/14/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Lab #2
int sumElements(int a[], int n) { // Array indexing
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int sumElements2(int *a, int n) { // Pointer notation/base + offset
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(a + i);
    }
    return sum;
}

int sumElements3(int *a, int n) { // Direct pointer access
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(a++);
    }
    return sum;
}

// Lab #4
char *strCopy(char t[], char s[]) { // Array Indexing
    int i = 0;
    while ((t[i] = s[i])) {
        i++;
    }
    return t;
}

char *strCopy2(char *t, char *s) {
    char *p = t;
    while ((*(t++) = *(s++)));
    return p;
}

// strlen()
int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int strlen2(char *s) {
    int i = 0;
    while(*(s + i) != '\0') {
        i++;
    }
    return i;
}

// Move Hare
void MoveHare(int &position) {
    static int a[10] = {6,6,2,2,0,0,0,-1,-5,-5};
    position += a[rand() % 10];
    if (position < 0) {
        position = 0;
    }
    else if (position > 70) {
        position = 70;
    }
}


int main(int argc, char *argv[]) {
    int a[5] = {1,2,3,4,5}, i = 0, position = 0;
    char t[25] = "Brown";
    char s[50] = "Bounce up to the sky";
    char *p1 = NULL;
//    cout << sumElements3(a, 5) << endl;
//    cout << strCopy2(t, s) << endl;
//    cout << strlen(t) << endl;
    
    // Lab 5 Random
//    int seed = 0;
//    if (argc > 1) {
//        seed = atoi(argv[1]);
//        if (seed > 0) {
//            srand(seed);
//        }
//        else if(seed < 0) {
//            srand(time(NULL));
//        }
//    }
    
    // strtok()
    p1 = strtok(s, " ,;.\n");
    while(p1 != NULL) {
        cout << p1 << endl;
        p1 = strtok(NULL, " ,;.\n");
    }
    
    for (i = 0; i < 10; i++) {
        cout << position << '\t' << flush;
        MoveHare(position);
    }
}
