#include <iostream>
#include <fstream>

using namespace std;

int main() {
/*
    int x = 10, y = 8, z = 7, i = 6;

    while(i > 0 && z > 0)
{
    z -= 2;
     if(i % 2 == 0)
        continue;
    --i;
}

    cout << "x == " << x << "    y == " << y << "    z == " << z << "    i == " << i << endl;

}
*/
int x = 10;
int y = 8;
int z = -1; 
int i = 6;

for (;;)
{
    x = y;
     if(i == 9)
        break;
    z++;
    i++;
}
cout << "x == " << x << "    y == " << y << "    z == " << z << "    i == " << i << endl;
}