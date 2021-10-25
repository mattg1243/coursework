#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int bar(int a)
{
    return a * 1.5;
}

void foo(int& a)
{
    a = bar(a);
}

int spam(int a, int& b)
{
    float c = a * .5;
    b = a * 3;
    return c;
}

void eggs(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

void bacon(int a)
{
    a = 0;
}

void ham(int& a, int b)
{
    static int c;
    
    a += c;
    b += c++;
}

void showArea(double &r) {
    double area = 2 * M_PI * r;
    cout << area << endl;
}

int main() {
/*
    int x = 1;
    int y = 2;
    
    bacon(x);

    cout << x << "    " << y << endl;

    foo(y);

    cout << x << "  post foo  " << y << endl; 

    x = spam(x, y);

    cout << x << "  post spam  " << y << endl;

    eggs(x,y);

    cout << x << "  post eggs  " << y << endl;

    for (int i = 0; i < 3; i++) {
        ham(x,y);
    }

    cout << x << "  final  " << y << endl;

    */



}