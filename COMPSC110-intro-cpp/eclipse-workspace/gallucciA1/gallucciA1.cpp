//============================================================================
// Name: gallucciA1.cpp
// Author: Matt Gallucci
// Version:
// Copyright:
// Description : Assignment 1
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main(){
	//variables:
	//part 1:
	float days_worked;
	float hours_worked;
	//float avg_hours = (hours_worked / days_worked);  this didn't work for some reason...

	//part 2:
	float deg_f;
	//float deg_c = (deg_f - 32) * 5/9;  this didn't work either, probably for the same reason

	//part 3:
	int id_num;
	string item1;
	float price1;
	string item2;
	float price2;
	string item3;
	float price3;
	//float subTotal = price1 + price2 + price3;
	//float tax = subTotal * .0925;
	//float total = subTotal + tax;

	//functionality:
	//part 1:
	cout << "How many days did you work last week?" << endl;
	cin >> days_worked;
	cout << "How many hours total did you work last week?" << endl;
	cin >> hours_worked;
	cout << "You averaged " << hours_worked / days_worked << " hours per day last week." << endl;

	//part 2:
	cout << "Enter a temperature, in Fahrenheit:" << endl;
	cin >> deg_f;
	cout << "That is " << (deg_f - 32) * 5/9 << " in C." << endl;

	//part 3:
	cout << "Enter your student ID number:" << endl;
	cin >> id_num;
	cout << "Enter the first item type:" << endl;
	cin >> item1;
	cout << "Enter the first item cost:" << endl;
	cin >> price1;
	cout << "Enter the second item type:" << endl;
	cin >> item2;
	cout << "Enter the second item cost:" << endl;
	cin >> price2;
	cout << "Enter the third item type:" << endl;
	cin >> item3;
	cout << "Enter the third item cost:" << endl;
	cin >> price3;

	float subTotal = price1 + price2 + price3;
	float tax = subTotal * .0925;
	float total = subTotal + tax;

	cout << "----------------Receipt for " << id_num << "------------------ " << endl;
	cout << item1 << " " << price1 << endl;
	cout << item2 << " " << price2 << endl;
	cout << item3 << " " << price3 << endl;
	cout << "Subtotal: " << subTotal << endl;
	cout << "Tax: " << tax << endl;
	cout << "Total: " << total << endl;
	cout << "----------------------------------------------------- " << endl;

	return 0;

};
