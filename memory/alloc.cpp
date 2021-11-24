// ECS 36B Review Session
// Linhao Chen (hghchen@ucdavis.edu)
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
using namespace std;

int main() {
    int *new_pointer = new int(1);
    int *malloc_pointer = (int *)malloc(sizeof(int)*1);
    int *calloc_pointer = (int *)calloc(1, sizeof(int));

    memset(malloc_pointer,'\0',sizeof(int));

    *malloc_pointer = 2;
    *calloc_pointer = 3;
    int stack_int = 4;

    cout << &stack_int << endl;
    cout << new_pointer << endl;
    cout << malloc_pointer << endl;
    cout << calloc_pointer << endl;

    cout << *new_pointer << endl;
    cout << *malloc_pointer << endl;
    cout << *calloc_pointer << endl;
    cout << stack_int << endl;

    free(malloc_pointer);
    free(calloc_pointer);
    delete(new_pointer);

    return 0;
}
