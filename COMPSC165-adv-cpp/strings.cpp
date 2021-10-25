#include <cctype>
#include <iostream>

using namespace std;

void lower(char*);
void upper(char*);
void reverse(char*);


int main() {
    
    char str[127];
    cout << "Enter a string up to 127 characters : ";
    cin.getline(str, 126);

    reverse(str);
    cout << str << endl;
    lower(str);
    cout << str << endl;
    upper(str);
    cout << str << endl;

}


void reverse(char* str) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (isupper(str[i])) {
            
            str[i] = tolower(str[i]);

        }

        else if (islower(str[i])) {
            
            str[i] = toupper(str[i]);
            
        }
    }
}


void lower(char* str) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (isupper(str[i])) {

            str[i] = tolower(str[i]);

        }
    }
}


void upper(char* str) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (islower(str[i])) {

            str[i] = toupper(str[i]);

        }
    }
}