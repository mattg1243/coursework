#include <iostream>
#include <string>

using namespace std;

struct Dog {

    string name;
    double age;
    string breed;

};

int main() {
    double test;
    Dog kennel[2] = {   
                        { "Jack", 3, "German Shepherd" },
                        { "McLovin", 13, "Bulldog"  }       
                    };

    for (int i; i < 2; i++) {
        cout << kennel[i].name << "  " << kennel[i].age << "  " << kennel[i].breed << endl;

    };
    cout << sizeof(test) << endl;
    
    return 0;
}