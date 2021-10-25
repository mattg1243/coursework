//============================================================================
// Name: gallucciA3.cpp
// Author: Matt Gallucci
// Version:
// Copyright:
// Description : Assignment 3
//============================================================================

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{

//part 1
	float i = 1;
	while (i <= 10)
	{
		cout << "The square root of " << i << " is " << sqrt(i) << endl;
		i++;
	}

	cout << "---------------------------------" << endl;

//part 2: i'm sure there's a better way to do this but it works
	int n = 10;
	int sum = 0;
	while (n <= 20)
	{
		sum += n;
		n++;
	}
	cout << sum << endl;

	cout << "---------------------------------" << endl;

//part 3:
	int low, high;

	cout << "Enter the lower end of a range of numbers you'd like to add: " << endl;
	cin >> low;
	cout << "Now enter the upper end number: " << endl;
	cin >> high;

	int count = low;  //10
	int sum1 = 0;
	while (count <= high)
	{
		//count++;
		//sum1 = sum1 + (count + 1);
		sum1 += count;
		count++;

	}
	cout << "Lower bounds: " << low << endl;
	cout << "Upper bounds: " << high << endl;
	cout << "Then sum of this range of intergers is " << sum1 << endl;

	cout << "---------------------------------" << endl;

//part 4:
	string user_input;

	cout << "Please enter either dagny, hank, or francisco: " << endl;
	cin >> user_input;

	while (user_input != "dagny" and user_input != "hank" and user_input != "francisco")
	{
		cout << "Invalid input. Please enter either Dagny, Hank, or Francisco: " << endl;
		cin >> user_input;
	}
	cout << "success!" << endl;

	cout << "---------------------------------" << endl;

//part 5:
	int choice;
	cout << "Please enter either a 1, 2, or 3: " << endl;
	cin >> choice;

	while (choice > -1)
	{
		if (choice < 1 or choice > 3)
		{
			cout << "Invalid input: Please enter one of the 3 choices" << endl;
			cin >> choice;
		}

		if (choice >=1 and choice <= 3)
		{
			if (choice == 1)
			{
				cout << "Abigail" << endl;
				cin >> choice;
			}
			else if (choice == 2)
			{
				cout << "Bobby" << endl;
				cin >> choice;
			}
			else if (choice == 3)
			{
				cout << "Charmaine" << endl;
				cin >> choice;
			}
		}
	}

	cout << "---------------------------------" << endl;

	return 0;
}


