#include <iostream>
#include <fstream>

using namespace std;

int arrayToFile(string, int [], int);
int fileToArray(string, int [], int);

int main() {

    int arr[5] = { 5, 5, 7, 10, 9 };
    int readArr[5] = { 0, 0, 0, 0, 0 };

    arrayToFile("binfile.dat", arr, 5);
    fileToArray("binfile.dat", readArr, 5);

    cout << "The source array : ";
    for (int i = 0; i < 5; i++) {
            cout << readArr[i] << " ";
        }

    cout << "\nThe destination array : ";
    for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
    cout << endl;

    return 0;
}


int arrayToFile(string fname, int arr[], int size) {

    fstream file;
    file.open(fname, ios::out | ios::binary);

    if (file.is_open()) {
        
        file.write(reinterpret_cast<char*>(arr), size * 4);
        file.close();
        return 0;

    } else {
        
        return -1;

    }
}

int fileToArray(string fname, int arr[], int size) {

    fstream file;
    file.open(fname, ios::in | ios::binary);

    if (file.is_open()) {
        
        file.read(reinterpret_cast<char*>(arr), size * 4);
        file.close();
        return 0;

    } else {
        
        return -1;

    }
}