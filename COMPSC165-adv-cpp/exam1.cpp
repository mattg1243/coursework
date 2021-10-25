#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

// Write a function that accepts an array of doubles and it's length as arguments.  
// The function should return the average of the values in the array.

int charCounter(const char* str, char search) {

    int counter = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == search) {
            
            counter++;
            
        }

    }

    return counter;

}

int main() {

    char str[10] = {'h', 'e', 'l', 'l', 'o'};

    cout << charCounter(str, 'l') << endl;

}