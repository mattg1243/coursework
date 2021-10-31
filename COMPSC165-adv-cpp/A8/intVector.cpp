#include <iostream>
#include <vector>

using namespace std;

class intVector {

    private:
    int* numbers;
    int length;

    public:
    // constructors
    intVector() {
        numbers = nullptr;
        length = 0;
    }

    intVector(int i, int j) {
        length = 2;
        int arr[2] = { i, j };
        numbers = new int[2];
        
        for (int i = 0; i < length; i++) {
                *( numbers + i ) = arr[i];
        }
    }
    // destructor
    ~intVector() {
        delete [] numbers;
    }
    // accessors
    int at(int pos) {
        return numbers[pos];
    }
    int size() {
        return length;
    }
    //mutators
    void push_back(int val) {
        if (length > 0) {
            int newarr[length + 1];
            
            for (int i = 0; i < length; i++) {
                *( newarr + i ) = numbers[i];
            }

            newarr[length] = val;
            
            numbers = new int[length + 1];

            for (int i = 0; i <= length; i++) {
                *( numbers + i ) = newarr[i];
            }
            
            length++;

        }
    }


};

int main() {

    intVector test(1, 2);



    cout << test.at(0) << endl;
    cout << "size test : " << test.size() << endl;
    test.push_back(3);
    test.push_back(4);
    cout << "size test : " << test.size() << endl;
    cout << "pushback test : " << endl;
    for (int i = 0; i<test.size(); i++) {
        cout << test.at(i) << endl;
    }

    return 0;
}