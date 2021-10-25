//============================================================================
// Name        : file_io_practice.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

	ifstream inputFile;
	inputFile.open("/Users/macadmin/eclipse-workspace/file_io_practice/input_file.txt", ios::in);

	if (! inputFile.is_open())
	{
		cout << "Error: file is not open" << endl;
		return 4;
	}

	string inputString, city, state, zip, cityOut, stateOut;
	ofstream outputFile;
	getline(inputFile, inputString);
	outputFile.open("outputFile.txt", ios::app);
	while (! inputFile.eof())
	{
		// parsing input file
		//getline(inputFile, inputString);
		city = inputString.substr(0,15);
		state = inputString.substr(15, 2);
		zip = inputString.substr(17, 5);
		getline(inputFile, inputString);

		// modifying the input

		cityOut = city;
		stateOut = state;
		cityOut[0] = tolower(city[0]);
		stateOut[0] = tolower(state[0]);
		stateOut[1] = tolower(state[1]);

		cout << cityOut << stateOut << endl;

		// writing the output file

		outputFile << cityOut << stateOut << zip << endl;

		//getline(inputFile, inputString);
	}

	outputFile << "----------------------" << endl;
	inputFile.close();
	outputFile.close();



	return 0;
}
