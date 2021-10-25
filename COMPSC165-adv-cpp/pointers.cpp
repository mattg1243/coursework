#include <iostream>

using namespace std;

int* expander(int*, int);

int main() {

    int ogarr[] = {5, 6, 4, 2, 7};

    int* newptr = expander(ogarr, 5);

    for(int i = 0; i < 10; i++) {

        cout << *( newptr + i ) << " ";

    }

    delete [] newptr;

    return 0;
}

int* expander(int ogarr[], int size) {

    int* newarr = new int [size*2];

    for (int i = 0; i < size; i++) {

        *( newarr + i ) = ogarr[i];

    }

    return newarr;

}