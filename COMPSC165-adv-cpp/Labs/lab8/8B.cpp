#include <iostream>

using namespace std;

class Integer {

    private:
    
        int* p;

    public:
        // constructors
        Integer() {
            p = new int;
            *p = 0;
        }

        Integer(int n) {
            p = new int;
            *p = n;
        }
        // destructor
        ~Integer() {
            delete p;
        }
        // mutators
        void setNum(int n) { 
            *p = n;
        }
        //accessors
        int getNum() {
            return *p;
        }

};

int main() {

    Integer i;
    cout << i.getNum() << endl;

    Integer j(4);
    cout << j.getNum() << endl;
    j.setNum(8);
    cout << j.getNum() << endl;

    return 0;

}