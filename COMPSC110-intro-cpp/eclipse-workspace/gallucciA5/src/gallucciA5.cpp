//============================================================================
// Name        : gallucciA5.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


int main() {

	// part 1

	ifstream inputFile1;
	ofstream outputFile1;
	inputFile1.open("/Users/macadmin/Desktop/SS21/COMSC110/Coding Assignments/A5/a5data1.txt", ios::in);

	if (! inputFile1.is_open())
	{
		cout << "Error opening file" << endl;
		return 4;
	}

	string inputString, fname, lname, restaurant, rating;
	float ratingAvg, ratingSum = 0;
	int ratingCount = 0;
	getline(inputFile1, inputString);		//gets the raters name
	fname = inputString.substr(0, 15);
	lname = inputString.substr(15, 20);
	cout << "Rater: " << fname << lname;
	getline(inputFile1, inputString);		//gets the first restaurant name

	while (! inputFile1.eof())
	{
		restaurant = inputString.substr(0, 15);
		int rating = stoi(inputString.substr(15, 1));
		ratingSum = ratingSum + rating;
		cout << "Restaurant:  " << restaurant << endl;
		cout << "Rating:  " << rating << endl;
		getline(inputFile1, inputString);
		ratingCount++;
	}

	ratingAvg = ratingSum/ratingCount;
	cout << "The average rating is:  " << ratingAvg <<endl;
	cout << "-------------------------" << endl;


	inputFile1.close();


	// part 2

	ifstream inputFile2;
	ofstream outputFile2;
	inputFile2.open("/Users/macadmin/Desktop/SS21/COMSC110/Coding Assignments/A5/a5data2.txt", ios::in);
	outputFile2.open("A5out.txt", ios::out);


	if (! inputFile2.is_open())
	{
		cout << "Error opening file 2" << endl;
		return 4;
	}

	string inputstring2, empFname, empLname;
	float hoursWorked, payRate, payTotal;
	getline(inputFile2, inputString);
	empFname = inputString.substr(0, 10);
	empLname = inputString.substr(10, 10);
	hoursWorked = stof(inputString.substr(25, 5));
	payRate = stof(inputString.substr(20, 5));
	payTotal = payRate * hoursWorked;
	outputFile2 << empFname << empLname << setprecision(2) << fixed << payTotal << endl;
	cout << empFname << empLname << "$ " << setprecision(2) << fixed << payRate << "   "  << hoursWorked << "   " << "$ " << payTotal << endl;
	getline(inputFile2, inputString);

	while (! inputFile2.eof())
	{
		empFname = inputString.substr(0, 10);
		empLname = inputString.substr(10, 10);
		hoursWorked = stof(inputString.substr(25, 5));
		payRate = stof(inputString.substr(20, 5));
		payTotal = payRate * hoursWorked;
		outputFile2 << setw(10) << empFname << setw(10) << empLname << setw(6) << setprecision(2) << fixed << payTotal << endl;

		cout << empFname << empLname << "$ " << setprecision(2) << fixed << payRate << "   "  << hoursWorked << "   " << "$ " << payTotal << endl;

		getline(inputFile2, inputString);
	}

	inputFile2.close();
	outputFile2.close();

	return 0;
}
