#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string inFileName, outFileName, inStr;
    string dir = "/Users/macadmin/Coding Projects/School/adv-cpp/A1/";
    ifstream inputFile;
    ofstream outputFile;

    cout << "Please enter the name of the file you would like to copy : \n";
    getline(cin, inFileName);

    cout << "Now enter the name of the file you would like to copy to/create : \n";
    getline(cin, outFileName);

    inputFile.open(dir + inFileName);
    outputFile.open(outFileName);

    while (! inputFile.is_open()) {
        
        cout << "Error opening input file; please enter a valid file name : ";
        getline(cin, inFileName);
    }

    if (! outputFile.is_open()) {
        
        cout << "Error writing to file; check access permissions \n";
        return 4;
    } 


    while (! inputFile.eof()) {
       
        getline(inputFile, inStr);
        outputFile << inStr << endl;
    }

    inputFile.close();
    outputFile.close();
}