#include <iostream>

using namespace std;

class Foo {

    protected:
    int x, y;

    public:
    Foo() { x=0; y=0; }
    Foo(int a, int b) { x=a; y=b; }
    void setX(int a) { x=a; }
    void setY(int b) { y=b; }
    int getX() const { return x; }
    int getY() const { return y; }

};

class Bar : public Foo {

    private:
    int z;

    public:
    Bar(int a, int b, int c) : Foo(a, b) { z = c; }
    void setZ(int a) { z=a; }
    int getZ() const { return z; }
    double getAverage() { return (getX() + getY() + z)/3; }
    int getSum() { return getX() + getY() + z; }

};

int main() {

    Bar b(8, 6, 5);

    cout << "Average : " << b.getAverage() << endl;
    cout << "Sum : " << b.getSum() << endl;

    return 0;
}
