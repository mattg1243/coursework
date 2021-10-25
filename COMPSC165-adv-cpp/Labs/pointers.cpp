#include <iostream>

using namespace std;

int main() {

    // * indirection operator
    // & address operator (same as reference operator)

    int x;

    int* xptr;
    int *yptr;
    int * zptr;

    xptr = &x; // xptr now holds the address in memory of int x

    cout << xptr << " " << &x << endl;
    
    // Arrays with pointers

    int vals[] = { 4, 7, 11 };
    int* valptr = vals;

    cout << vals << endl;  // when no index is given, the memory address is returned
    cout << *vals << endl; // when using the indirection, the value stored in that address is returned (derefernced)

    cout << *(valptr + 1) << endl; // this will return 7, pointer notation
    cout << valptr[1] << endl;  // because this is essentially the same as how an array variable is already stored it works

    // looping through an array using a pointer 

    for (int i = 0; i < 3; i++) {
        cout << * ( valptr + i ) << endl;
    }


    // easy so far
    
    return 0;
}