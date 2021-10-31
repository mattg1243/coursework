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

    intVector(int val, int n) {
        length = n;
        numbers = new int[n];
        
        for (int i = 0; i < n; i++) {
                *( numbers + i ) = val;
        }
    }
    // destructor
    ~intVector() {
        delete [] numbers;
    }
    // accessors
    int& at(int pos) const {
        return numbers[pos];
    }
    int size() const {
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

        } else {
            numbers = new int[1];
            numbers[0] = val;
        }
        
        length++;
    }


};

int main() {

    intVector defConst;
    defConst.push_back(8);
    defConst.push_back(6);
    defConst.push_back(7);

    for (int i = 0; i < defConst.size(); i++) {
        cout << defConst.at(i) << " ";
    }
    cout << "\n";

    defConst.at(1) = 0;

    for (int i = 0; i < defConst.size(); i++) {
        cout << defConst.at(i) << " ";
    }
    cout << "\n";

    intVector ovConst(9, 5);

    for (int i = 0; i < ovConst.size(); i++) {
        cout << ovConst.at(i) << " ";
    }

    return 0;
}