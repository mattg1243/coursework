//============================================================================
// Name        : gallucciA2.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Coding Assignment 2
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {

	//part 1:
	float principal, interestRate, interestCompAnn, interestCompDaily;
	cout << "Enter principal: " << endl;
	cin >> principal;
	cout << "Enter interest rate: " << endl;
	cin >> interestRate;
	float interestRatePer = interestRate / 100;
	cout << "For a loan of" << setw(34) << "$" << setw(8) << setprecision(2) << fixed << principal << endl;
	cout << "With a rate of" << setw(41) << setprecision(2) << fixed << interestRate << " %" << endl;
	interestCompAnn = principal * interestRatePer;
	cout << "The interest, compounded annually, is" << setw(10) << "$" << setw(8) << setprecision(2) << fixed << interestCompAnn << endl;
	cout << "The balance at the end of the year would be" << setw(4) << "$" << setw(8) << right << setprecision(2) << fixed << interestCompAnn + principal << endl;
	interestCompDaily = principal * pow((1 + interestRatePer / 365), 365) - principal;
	cout << "The interest, compounded daily, is" << setw(13) << "$" << setw(8) << setprecision(2) << fixed << interestCompDaily << endl;
	cout << "The balance at the end of the year would be" << setw(4) << "$" << setw(8) << right << setprecision(2) << fixed << interestCompDaily + principal << endl;
	cout << "-------------------------------------------------------" << endl;


	//part 2:
	float height, width, diagonal;
	cout << "How tall is your screen? (in inches)" << endl;
	cin >> height;
	cout << "How wide is your screen? (also in inches)" << endl;
	cin >> width;
	diagonal = sqrt(pow(height, 2) + pow(width, 2));
	cout << "Your screen size is " << setprecision(1) << fixed << diagonal << " inches." << endl;
	cout << "-------------------------------------------------------" << endl;


	//part 3:
	float tankCost, milesDriven;
	cout << "How much does is cost to fill your gas tank?" << endl;
	cin >> tankCost;
	cout << "How many miles does that last you?" << endl;
	cin >> milesDriven;
	cout << "Cost of gas:" << setw(4) << "$" << setw(8) << setprecision(2) << fixed << tankCost << endl;
	cout << "Miles driven:" << setw(11) << milesDriven << endl;
	cout << "Cost per mile:" << setw(2) << "$" << setw(8) << tankCost / milesDriven << endl;
	cout << "-------------------------------------------------------" << endl;


	//part 4:
	int hScore = 0;
	int uScore = 0;
	string playSignal;
	cout << "Welcome to the Craps table. Type R to roll the dice or Q to walk away" << endl;
	cin >> playSignal;
	while (playSignal == "R" or playSignal == "r")
	{
		srand(time(0));
		int d1 = rand();
		int d2 = rand();
		int d3 = rand();
		int d4 = rand();
		int dice1 = (d1 % 6) + 1;
		int dice2 = (d2 % 6) + 1;
		int rollValue = dice1 + dice2;
		cout << "You rolled a " << dice1 << " and a " << dice2 << " for a total of " << rollValue << endl;
		if (rollValue == 7 or rollValue == 11)
		{
			cout << "---You win!---" << endl;
			uScore++;
		}
		else if (rollValue == 2 or rollValue == 3 or rollValue == 11)
		{

			cout << "---You lose---" << endl;
			hScore++;
		}
		else
		{
			int point = rollValue;
			cout << "The point to be made is " << point << endl;
			int dice3 = (d3 % 6) + 1;
			int dice4 = (d4 % 6) + 1;
			rollValue = dice3 + dice4;
			cout << "You rolled a " << dice3 << " and a " << dice4 << " for a total of " << rollValue << endl;
			if (rollValue == point)
			{
				cout << "---You win!---" << endl;
				uScore++;
			}
			else
			{
				cout << "---You lose---" << endl;
				hScore++;
			}

		}

		cout << "Your score: " << uScore << endl;
		cout << "House's score: " << hScore << endl;
		cout << "That was fun, type R to play again or Q to quit" << endl;
		cin >> playSignal;
		cout << "" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "" << endl;
	}

	cout << "Enjoy the rest of the casino" << endl;


	return 0;
}
