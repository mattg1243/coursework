#include <iostream>

using namespace std;


class Integer {
    
    private:
        int* i;

    public:
    
        Integer() { i = new int; *i = 0; }

        ~Integer() { delete i; }

        void set(int j) { *i=j; }

        int get() const { return *i; }

        Integer& operator=(const Integer& j) { 

            if (this == &j) {
                return *this;
            }

            *i = *(j.i);
            return *this;

         }


};


int main() {

    Integer a, b;

    a.set(99);
    b=a;

    cout << "a = " << a.get() << endl;
    cout << "b = " << b.get() << endl;

    return 0;
}