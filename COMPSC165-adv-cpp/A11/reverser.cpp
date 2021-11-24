#include <iostream>

using namespace std;

void reverser(string s) { 

    if (s.length() == 0) { return; }

    cout << s[s.length() - 1];
    reverser(s.substr(0, s.length() - 1));

}

int main() {

    string str;

    cout << "Enter a string to reverse : ";
    getline(cin, str);
    reverser(str);
    cout << endl;

}