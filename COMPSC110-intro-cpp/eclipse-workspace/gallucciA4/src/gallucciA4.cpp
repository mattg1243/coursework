//============================================================================
// Name        : gallucciA4.cpp
// Author      : Matt Gallucci
// Version     : One of One
// Copyright   : DontStealMyCode®
// Description : A menu and some programs
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;


float tempConvert(float f) {		// converts argument from F to C

	float tempC;
	tempC = (f - 32) * 5/9;

	return tempC;
}


int main() {

//		-- starting menu --

	string menu_select;
	char menu_select_char;

	while (menu_select_char != 'x')
	{
		cout << "Which service are you interested in?" << endl;
		cout << "A.  " << "Temperature conversion, from F to C" << endl;
		cout << "B.  " << "Number Guessing Game" << endl;
		cout << "C.  " << "Draw a rectangle" << endl;
		cout << "D.  " << "Temperature table, F to C" << endl;
		cout << "E.  " << "Car names voting" << endl;
		cout << "X.  " << "Exit" << endl;

		getline(cin, menu_select);
		menu_select_char = tolower(menu_select[0]);

//		-- temperature conversion --

		if (menu_select_char == 'a')
		{
			string deg_f_str;

			cout << "Enter a temperature, in Fahrenheit:" << endl;
			getline(cin, deg_f_str);
			float deg_f = stof(deg_f_str);
			if (tempConvert(deg_f) == 0)
			{
				cout << "That is 0 degrees C." << endl;
			}
			else
			{
				float deg_c = tempConvert(deg_f);
				cout << "That is " << setprecision(2) << fixed << deg_c << " degrees C." << endl;
			}
		}

//			-- guessing game --

		else if (menu_select_char == 'b')
		{
			srand(time(0));
			int answer_seed = rand();
			int answer = (answer_seed % 100) + 1;
			string guess_str;
			int guess;
			int guess_count = 0;

			cout << "Guess a number between 1 and 100:  " << endl;
			getline(cin, guess_str);
			guess = stoi(guess_str);
			guess_count++;

			while (guess != answer)
			{
				if (guess > answer)
				{
					guess_count++;
					cout << "Try a lower number: " << endl;
					getline(cin, guess_str);
					guess = stoi(guess_str);
				}

				if (guess < answer)
				{
					guess_count++;
					cout << "Try a higher number: " << endl;
					getline(cin, guess_str);
					guess = stoi(guess_str);
				}
			}

			cout << "You guessed it in " << guess_count << " tries. Not bad." << endl;

		}

//		-- drawing a rectangle --

		else if (menu_select_char == 'c')
		{
			int height, width, h, w;
			string height_str, width_str;

			cout << "Please enter a height for your rectangle: " << endl;
			getline(cin, height_str);
			height = stoi(height_str);
			cout << "Now enter a width: " << endl;
			getline(cin, width_str);
			width = stoi(width_str);
			cout <<  "Heres your rectangle!\n" << endl;

			for (h = 1; h <= height; h++)
			{
				for (w = 1; w <= width; w++)
				{
					cout << "*";
				}
				cout << "\n";
			}
		}

//		-- temperature table --

		else if (menu_select_char == 'd')
		{
			float fh, cent;
			int f;

			cout << endl;
			cout << "Fahrenheit " << setw(15) << "Centigrade" << endl;
			cout << "--------------------------" << endl;

			for (f = 0; fh <= 220; fh += 10)
			{
				cent = (fh - 32) * 5/9;
				cout << setw(3) << left << int(fh) << right << setw(23) << setprecision(2) << fixed  << cent << endl;
			}
		}

//		-- car names voting --

		else if (menu_select_char == 'e')
		{
			string choice = "";
			string winner = "";
			int mustang_vote = 0;
			int camaro_vote = 0;
			int chevelle_vote = 0;

			while (mustang_vote < 3 and camaro_vote < 3 and chevelle_vote < 3)
			{
				cout << "Which muscle car is your favorite, Camaro, Mustang, or Chevelle?" << endl;
				getline(cin, choice);

				while (choice != "camaro" and choice != "mustang" and choice != "chevelle")
				{
					cout << "Invalid vote, please select one of the cars as your vote:" << endl;
					getline(cin, choice);
				}

				if (choice == "mustang")
				{
					mustang_vote++;
					cout << "---Vote recorded---" << endl;
					if (mustang_vote == 3)
					{
						winner = "Mustang";
					}
				}

				else if (choice == "camaro")
				{
					camaro_vote++;
					cout << "---Vote recorded---" << endl;
					if (camaro_vote == 3)
					{
						winner = "Camaro";
					}
				}

				else if (choice == "chevelle")
				{
					chevelle_vote++;
					cout << "---Vote recorded---" << endl;
					if (chevelle_vote == 3)
					{
						winner = "Chevelle";
					}
				}
			}

			cout << "" << endl;
			cout << "And the winner is the " << winner << " with 3 votes!" << endl;
			cout << "Vote totals:" << endl;
			cout << setw(15) << left << "   Mustang:" << right << setw(15) << fixed << mustang_vote << endl;
			cout << setw(15) << left << "   Camaro:" << right << setw(15) << camaro_vote << endl;
			cout << setw(15) << left << "   Chevelle:" << right << setw(15) << chevelle_vote << endl;

		}

		cout << "" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++" << endl;
		cout << "" << endl;

	}

	return 0;

}
