#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void fillVector(vector<float>&);
void sortVector(vector<float>&);
void printVector(vector<float>&);

int main() {

    vector <float> vec;

    fillVector(vec);
    sortVector(vec);
    printVector(vec);

}

// function definitions 

void fillVector(vector<float>& vec) {
        
        string vElem;

        for (int i = 0; i < 5; i++) 
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> vElem;
            vec.push_back(stof(vElem));
        }
    }

void printVector(vector<float>& vec) {

    for (float e : vec) {
        cout << e << ' ';
    }

}

void sortVector(vector<float>& vec) {

    for (int startScan = 0; startScan < vec.size(); startScan++) {

        int i = startScan;
        int minIndex = startScan;
        float minVal = vec[minIndex];

        for (i; i < vec.size(); i++) {

            if (vec[i] < minVal) {
                minVal = vec[i];
                minIndex = i;
            }

        }

    vec[minIndex] = vec[startScan];
    vec[startScan] = minVal;

    } 
}