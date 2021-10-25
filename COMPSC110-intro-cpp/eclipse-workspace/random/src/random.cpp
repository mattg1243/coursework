//============================================================================
// Name        : random.cpp
// Author      : Matt Gallucci
// Version     :
// Copyright   : DontStealMyCode®
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int i;
	int count = 1;
	cout << "Enter a number you would like to count up to: " << endl;
	cin >> i;

	while (count <= i)
	{
		cout << count << endl;
		count++;
	}


	return 0;
}
