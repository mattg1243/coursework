#include <iostream>

using namespace std;

struct Month {

    double totalRain;
    double highTemp;
    double lowTemp;

};

double totalRainfall(Month [3]);
double findLowestTemp(Month [3]);
double findHighestTemp(Month [3]);


int main() {

    Month seasonArr[3];
    double rainInput, highTempInput, lowTempInput;

    for (int i = 0; i < 3; i++) {

        cout << "Enter the total rainfall for month " << i + 1 << ": ";
        cin >> rainInput;
        cout << "Enter the high temperature for month " << i + 1 << ": ";
        cin >> highTempInput;
        cout << "Enter the low temperature for month " << i + 1 << ": ";
        cin >> lowTempInput;

        seasonArr[i] = { rainInput, highTempInput, lowTempInput };

    }

    cout << "The total rainfall for all three months is " << totalRainfall(seasonArr) << ".\n";
    cout << "The average rainfall is " << totalRainfall(seasonArr) / 3 << ".\n";
    cout << "The highest high temperature is " << findHighestTemp(seasonArr) << ".\n";
    cout << "The lowest low temperature is " << findLowestTemp(seasonArr) << ".\n";


    return 0;
}

double totalRainfall(Month arr[3]) {

    double sum = 0;

    for (int i = 0; i < 3; i++) {

        sum += arr[i].totalRain;

    }

    return sum;
}

double findLowestTemp(Month arr[3]) {

    double lowest = 9999;

    for (int i = 0; i < 3; i++) {

        if (arr[i].lowTemp < lowest) {
            lowest = arr[i].lowTemp;
        }
    }

    return lowest;
}

double findHighestTemp(Month arr[3]) {

    double highest = 0;

    for (int i = 0; i < 3; i++) {

        if (arr[i].highTemp > highest) {
            highest = arr[i].highTemp;
        }
    }

    return highest;
}
