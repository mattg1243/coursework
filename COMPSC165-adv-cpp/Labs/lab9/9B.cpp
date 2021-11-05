#include <iostream>

using namespace std;


class Integer {
    
    private:
    int* i;

    public:
    Integer() { i = new int; *i = 0; }
    Integer(const Integer& right ) {

        i = new int;
        *i = *(right.i);

    }
    ~Integer() { delete i; }
    // mutator
    void set(int j) { *i=j; }
    // accessor
    int get() const { return *i; }
    // operator overloads
    Integer& operator=(const Integer& j) { 

        if (this == &j) {
            return *this;
        }

        *i = *(j.i);
        return *this;

        }

    bool operator==(const Integer& j) { 

        if (*i == *(j.i)) {
            return true;
        }
        else { return false; }
        }

    bool operator<(const Integer& j) { 

        if (*i < *(j.i)) {
            return true;
        }
        else { return false; }
        }

    friend ostream& operator<<(ostream&, const Integer&);

};

ostream& operator<<(ostream& o, const Integer& arg) {

    o << *(arg.i);
    return o;

}

int main() {

    Integer a, b;

    a.set(99);
    b=a;
    b.set(27);

    cout << "a = " << a.get() << endl;
    cout << "b = " << b.get() << endl;
    cout << "Are they the same? ";
    if(a==b){
        
        cout << "Yes\n";

    }
    else {
        
        cout << "No\n";
        
    }
    cout << "Stream OL : " << a << endl;

    return 0;
}