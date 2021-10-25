//============================================================================
// Name        : gallucciA9.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void errorMsg(int line[], string dept[]);
int errorCount = 0;


int main() {

	cout << "------------------------------Part 1-----------------------------\n\n";

	ifstream data1;
	data1.open("/Users/macadmin/Desktop/SS21/COMSC110/Coding Assignments/A9/a9data1.txt", ios::in);

	if (! data1.is_open())
	{
		cout << "Error opening file\n";
	}

	string inputStr, monthStr, tempStr;
	int monthInt, tempInt;

	int sumArr[12] = {0}, countArr[12] = {0}, yearlyTotal = 0, totalSum = 0;
	float totalAvg;
	string monthNames[12] = {"January", "February", "March", "April", "May", "June" , "July", "August",
			"September", "October", "November", "December"};

	getline(data1, inputStr);

	while (! data1.eof())
	{
		monthStr = inputStr.substr(0,2);
		tempStr = inputStr.substr(2,3);
		monthInt = (stoi(monthStr) - 1);
		tempInt = stoi(tempStr);
		sumArr[monthInt] += tempInt;
		totalSum += tempInt;
		countArr[monthInt]++;
		yearlyTotal++;
		getline(data1, inputStr);
	}

	totalAvg = static_cast<float> (totalSum) / yearlyTotal;

	data1.close();

	cout << setw(15) << left << "Month" << setw(30) << "Number of Temperatures" << setw(10) << "Average Temperature" << endl;
	cout << "-----------------------------------------------------------------\n";

	for (int month=0;month<12;month++)
	{
		cout << setw(25) << left << monthNames[month] << setw(28) << countArr[month] << sumArr[month] / countArr[month] << endl;
		cout << "-----------------------------------------------------------------\n";
	}
	cout << "Yearly total: " << yearlyTotal << "  Average overall: " << setprecision(2) << fixed << totalAvg << endl;
	cout << "\n------------------------------Part 2-----------------------------\n\n";

	ifstream data2;
	data2.open("/Users/macadmin/Desktop/SS21/COMSC110/Coding Assignments/A9/a9data2.txt", ios::in);

	if (! data2.is_open())
	{
		cout << "Error opening file\n";
	}

	string deptNames[11] = {"Mathematics", "Physics", "Biology", "Computer Science", "Accounting", "Art History",
			"Political Science", "US History", "English Literature", "Engineering", "Psychology"};

	string deptAbb[11] = {"MATH ", "PHYS ", "BIO  ", "COMSC", "ACCY ", "ARTH ", "POLS ", "USHST", "ELIT ", "ENGR ", "PSYC "};

	int majorCounts[11] = {0}, i = 0, lineCount = 1;

	string inputStr2, inputDept, outputDept, studentName;

	int errorLine[100];
	string missingDept[100];

	getline(data2, inputStr2);

	while (! data2.eof())
	{
		studentName = inputStr2.substr(0, 20);
		inputDept = inputStr2.substr(20, 5);
		//cout << "\nStudent : " << studentName << "  department-" << inputDept << "-" << endl;
		for (i = 0;i < 11; i++)
		{
			if (deptAbb[i] == inputDept)
			{
				outputDept = deptNames[i];
				majorCounts[i]++;
				break;
			}
		}
		if (i == 11)
		{
			errorCount++;
			errorLine[errorCount - 1] = lineCount;
			missingDept[errorCount - 1] = inputDept;
			outputDept = "*** Error: see below ***";
		}
		cout << "Student : " << studentName << " |  Department : " << outputDept << endl;
		getline(data2, inputStr2);
		lineCount++;
	}

	if (errorCount != 0)
	{
		errorMsg(errorLine, missingDept);
	}

	cout << "-----------------------------------------------------------------\n";
	cout << setw(34) << left << "Department Names" << "Number of Majors\n";
	cout << "-----------------------------------------------------------------\n";

	for (int j = 0; j < 11; j++)
	{
		cout << setw(31) << left << deptNames[j] << "|" << setw(11) << right << majorCounts[j] << endl;
	}
	cout << "-----------------------------------------------------------------\n";
	return 0;
}

void errorMsg(int line[], string dept[]){
	for (int i = 0; i < errorCount; i++)
	{
		cout << "-----------------------------------------------------------------\n";
		cout << "Invalid department data in line " << line[i] << " of the input file\n'" << dept[i] << "' is not a valid department.\n";
	}
}
