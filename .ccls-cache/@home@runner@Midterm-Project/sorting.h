#ifndef sorting_h
#define sorting_h

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

inline void display(pair<string, int>* a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout << setw(5) << a[i]->first << " " << setw(8) << a[i]->second<<" Baht"<<endl;
    }
    cout << endl;
}

inline void swap(pair<string, int>*& a, pair<string, int>*& b) {
    pair<string, int>* temp;
    temp = a;
    a = b;
    b = temp;
}

void sorting(pair<string, int>* a[], int n) {
    int i, j;
    int sorted;

    for (j = 0; j < n - 1; j++) {
        sorted = 0;
        for (i = 0; i < n - 1; i++) {
            if (a[i]->second < a[i + 1]->second) {
                swap(a[i], a[i + 1]);
                sorted = 1;
            }
        }
        if (sorted == 0)
            break;
    }
}

#endif
