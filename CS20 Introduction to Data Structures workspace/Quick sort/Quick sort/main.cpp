//
//  main.cpp
//  Quick sort
//
//  Created by Mahdi Khaliki on 12/10/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//


#include <iostream>
using namespace std;

int split(int a[], int low, int high) {
    int x = a[low];
    bool highTurn = true;
    
    while (low < high) {
        if (highTurn) {
            if (a[high] < x) {
                a[low++] = a[high];
                highTurn = false;
            }
            else high--;
        }
        else {
            if (a[low] > x) {
                a[high--] = a[low];
                highTurn = true;
            }
            else low++;
        }
    }
    a[low] = x;
    return low;
}

void quickSort1(int nums[], int start, int end) {
    if (start >= end) return;
    
    int mid = split(nums, start, end);
    cout << "{ " << flush;
    for (int i = 0; i < 12; i++) {
        cout << nums[i] << flush;
        if (i != 11) cout << ", " << flush;
        else cout << " }" << endl;
    }
    cout << "return value = " << mid << endl;
    
    quickSort1(nums,start,mid-1);
    quickSort1(nums,mid+1,end);
}

// quicksort
void quicksort(int nums[], int len) {
    quickSort1(nums,0,len-1);
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << flush;
        if (i != n-1) cout << ", " << flush;
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void fixheap(int a[], int left, int right) {
    int x;
    x = a[left];
    
    int i ,j;
    for (i = left, j = 2*i + 1; j <= right; i = j, j = 2*i + 1) {
        
        if (j < right && a[j+1] > a[j]) j++;
        
        if (x >= a[j]) break;
        
        a[i] = a[j];
    }
    a[i] =  x;
}

void heapSort(int  a[], int n) {
    if (n > 1) {
        for (int left = n/2-1; left >= 0; left--) {
            fixheap(a,left,n-1);
            printArray(a, n);
        }
        
        swap(a[0], a[n-1]);
        
        for (int right = n-2;  right >= 1; right--) {
            fixheap(a,0,right);
            printArray(a, n);
            swap(a[0], a[right]);
        }
    }
}

int main() {
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    heapSort(nums, 7);
    return 0;
}
