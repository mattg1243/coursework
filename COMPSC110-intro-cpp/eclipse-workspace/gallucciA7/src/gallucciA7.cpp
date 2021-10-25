//============================================================================
// Name        : gallucciA7.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//float hoursWorked;
float ovHours;


float calcRegPay(float hours, float rate);
float calcOvPay (float hours, float rate);
float calcTax(float pay, float taxRate);
int getIntegerFromUser(string message, int lower, int upper);

bool testA7part2();

const float BASE_TAX_RATE = .04;

int main() {

// part 1

	ifstream inputFile;
	inputFile.open("/Users/macadmin/Desktop/SS21/COMSC110/Coding Assignments/A7/a7data.txt", ios::in);

	if(! inputFile.is_open())
	{
		cout << "Error opening file" << endl;
		return 4;
	}

	string name, hoursWorkedStr, payRateStr, inputStr;
	float hoursWorkedF, payRateF, grossPay, netPay, taxPaid;
	getline(inputFile, inputStr);
	name = inputStr.substr(0, 20);
	payRateStr = inputStr.substr(20, 5);
	hoursWorkedStr = inputStr.substr(25, 5);
	hoursWorkedF = stof(hoursWorkedStr);
	payRateF = stof(payRateStr);

	cout << "Part 1:\n\n";
	cout << setw(20) << left << "Name" << setw(12) << "Hours" << setw(12) << "Rate" << setw(12) << "Reg Pay" << setw(12) << "OV Pay" <<
			setw(12) << "Gross Pay" << setw(12) << "Tax" << setw(12) << "Net Pay" << endl;

	cout << "---------------------------------------------------------------------------------------------------\n";


	while(! inputFile.eof())
	{
		name = inputStr.substr(0, 20);
		payRateStr = inputStr.substr(20, 5);
		hoursWorkedStr = inputStr.substr(25, 5);
		hoursWorkedF = stof(hoursWorkedStr);
		payRateF = stof(payRateStr);
		grossPay = calcRegPay(hoursWorkedF, payRateF) + calcOvPay(hoursWorkedF, payRateF);
		taxPaid = calcTax(grossPay, BASE_TAX_RATE);
		netPay = grossPay - taxPaid;

		getline(inputFile, inputStr);
		cout << name << setw(12) << left << setprecision(2) << fixed << hoursWorkedStr << setw(12) << payRateStr << setw(12) << calcRegPay(hoursWorkedF, payRateF) <<
				setw(12) << calcOvPay(hoursWorkedF, payRateF) << setw(12) << grossPay << setw(12) << taxPaid << netPay << endl;

	}

	inputFile.close();
	cout << "---------------------------------------------------------------------------------------------------\n\n";


// part 2

	cout << "Part 2: \n\n";

	if (testA7part2())
	{
		cout << "\nMy program works, trust me\n";
	}
	else
	{
		cout << "\nI messed up somewhere\n";
	}

	return 0;
}

float calcRegPay(float hours, float rate)
{
	if (hours > 40)
	{
		hours = hours - (hours - 40);
	}


	float regPay = hours * rate;
	return regPay;
}

float calcOvPay (float hours, float rate)
{

	if (hours > 40)
	{
		hours = hours - 40;
		return hours * (rate * 1.5);
	}
	else
	{
		return 0;
	}

}

float calcTax (float pay, float taxRate)
{

	if (pay < 100.0)
	{
		taxRate = BASE_TAX_RATE - .02;
	}
	else if (pay >= 100.0 and pay <= 600.0)
	{
		taxRate = BASE_TAX_RATE;
	}
	else
	{
		taxRate = BASE_TAX_RATE + .04;
	}


	return pay * taxRate;

}

int getIntegerFromUser(string message, int lower, int upper)
{

	string usrInputStr;
	int usrInputInt;
	cout << message << endl;
	getline(cin, usrInputStr);
	usrInputInt = stoi(usrInputStr);

	while (usrInputInt < lower or usrInputInt > upper)
	{
		cout << "Invalid input: " << message << endl;
		getline(cin, usrInputStr);
		usrInputInt = stoi(usrInputStr);
	}

	return usrInputInt;

}

double getDoubleFromUser(string message, double lower, double upper)
{

	string usrInputStr;
	double usrInputD;
	cout << message << endl;
	getline(cin, usrInputStr);
	usrInputD = stod(usrInputStr);

	while (usrInputD < lower or usrInputD > upper)
	{
		cout << "Invalid input: " << message << endl;
		getline(cin, usrInputStr);
		usrInputD = stod(usrInputStr);
	}

	return usrInputD;

}

string getStringFromUser(string message)
{
	cout << message << endl;

	string userInput;
	int strLen;
	getline(cin, userInput);
	strLen = userInput.length();

	while (strLen == 0)
	{
		cout << "Invalid input: please enter a string" << endl;
		getline(cin, userInput);
	}

	return userInput;

}

bool testA7part2()
{
	string message = "enter an integer in the range 5 to 10 inclusive";
	int i = getIntegerFromUser (message, 5, 10);
	if (i >= 5 and i <= 10)
	{
		message = "enter a double in the range 5.1 to 5.5 inclusive";
		double d = getDoubleFromUser (message, 5.1, 5.5);
		if (d >= 5.1 and d <= 5.5)
		{
			message = "enter your favorite book's title";
			string s = getStringFromUser (message);
			if (s.length() > 0)
			{
				return true;
			}
		}
	}
	return false;
}

