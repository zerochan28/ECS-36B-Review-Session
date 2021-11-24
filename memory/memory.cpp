// ECS 36B Review Session
// Linhao Chen (hghchen@ucdavis.edu)
#include <iostream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

int main() {
    int i = 3;
    int *ptr = &i;
    int &ref = i;

    cout << ref << endl;

    *ptr = 20;

    cout << i << endl;

    // Address
    cout << &i << endl;
    cout << ptr << endl;
    cout << &ref << endl;
    cout << &ptr << endl;
    
    ref = 30;

    cout << ref << endl;
    cout << i << endl;
    cout << *ptr << endl;

    return 0;
}
