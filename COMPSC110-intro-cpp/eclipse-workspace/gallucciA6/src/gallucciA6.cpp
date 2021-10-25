//============================================================================
// Name        : gallucciA6.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

//		part 1 prototypes

float calcCircumference(float r);
float calcArea(float r);
void displayColumnHeader();

//		part 2 functions / global counting variable

int calcReorder(int inventory, int reorderPoint);
void displayColumnHeader();
void displayItemReorderCount();

int itemsNeeded = 0;

int main() {

	//	part 1

	string radStr;
	float radF;

	cout << "Enter a radius to calculate the circumference and area of the circle: " << endl;
	getline(cin, radStr);
	radF = stof(radStr);

	while (radF >= 0)
	{
		cout << "The circumference of this circle is " << setprecision(2) << fixed << calcCircumference(radF) << endl;
		cout << "The area of this circle is " << setprecision(2) << fixed << calcArea(radF) << endl;
		cout << "Enter another radius or if you would like to exit, enter a negative number: " << endl;
		getline(cin, radStr);
		radF = stof(radStr);
	}

	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";


	//	part 2


	ifstream inputFile;
	inputFile.open("/Users/macadmin/Desktop/SS21/COMSC110/Coding Assignments/A6/a6data.txt");

	if (! inputFile.is_open())
	{
		cout << "Error opening file" << endl;
		return 4;
	}

	string inputStr, item, countStr, reorderStr, action;
	int countInt, reorderInt;

	getline(inputFile, inputStr);

	item = inputStr.substr(0,15);
	countStr = inputStr.substr(15, 3);
	reorderStr = inputStr.substr(18, 3);
	countInt = stoi(countStr);
	reorderInt = stoi(reorderStr);

	displayColumnHeader();

	while (! inputFile.eof())
	{
		if (calcReorder(countInt, reorderInt) == 0)
		{
			action = "none";
		}
		else
		{
			string calcReorderStr = to_string(calcReorder(countInt, reorderInt));
			action = "order " + calcReorderStr;
		}
		item = inputStr.substr(0,15);
		countStr = inputStr.substr(15, 3);
		reorderStr = inputStr.substr(18, 3);
		countInt = stoi(countStr);
		reorderInt = stoi(reorderStr);
		cout << setw(15) << left << item  << "|  " << setw(12) << countInt << "|  " << setw(10) << reorderInt << "|  " << setw(9) << right << action << endl;
		getline(inputFile, inputStr);
	}

	cout << "--------------------------------------------------------\n";
	cout << "Items requiring reorder: " + to_string(itemsNeeded / 2);	// had to divide by 2 since I call the function twice causing the variable to increment twice



	return 0;

}



float calcCircumference(float r)
{
	return 2 * (3.14159 * r);
}

float calcArea(float r)
{
	return 3.14159 * (r * r);
}


int calcReorder (int inventory, int reorderPoint)
{
	int itemsToOrder;
	static_cast <float> (itemsToOrder);

	if(inventory >= reorderPoint)
	{
		return 0;
	}
	else
	{
		itemsToOrder = reorderPoint - inventory;
		itemsNeeded++;
		return itemsToOrder;
	}

}

void displayColumnHeader()
{
	cout << setw(15) << left << "Item";
	cout << setw(12) << "Inventory";
	cout << setw(12) << "Reorder Point";
	cout << setw(15) << right << "Action" << endl;
	cout << "--------------------------------------------------------" << endl;
}

void displayItemReorderCount()
{
	cout << "Number of items requiring an order: " << itemsNeeded << endl;
}













