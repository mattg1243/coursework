#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double score1, score2, score3, score4, score5;

void getScore(double&);
int findLowest(double, double, double, double, double);
void calcAverage(double, double, double, double, double);


int main() {

    getScore(score1);
    getScore(score2);
    getScore(score3);
    getScore(score4);
    getScore(score5);
    calcAverage(score1, score2, score3, score4, score5);

}


void getScore(double& refparam) {

    double input;

    cout << "Enter score: ";

    cin >> input;

    while (input <= 0 || input >= 100) {

        cout << "Error: invalid score\nScores must be between 0 and 100\n";
        cout << "Enter the test score: ";
        cin >> input;

    }

    refparam = input;

}

int findLowest(double score1, double score2, double score3, double score4, double score5){
    
    int lowest = 100;
    int scores[] = {score1, score2, score3, score4, score5};

    for (int i = 0; i < 5; i++) {

        if (scores[i] < lowest) {
            lowest = scores[i];
        }

    }

    return lowest;

}

void calcAverage(double score1, double score2, double score3, double score4, double score5){
    
    int scores[] = {score1, score2, score3, score4, score5};
    int lowest = findLowest(score1, score2, score3, score4, score5);
    int sum = 0;    

    for (int i = 0; i < 5; i++) {
        if (scores[i] != lowest) {
            sum += scores[i];
        }
    }

    double avg = sum / 4.0;
    cout << "The average is " << setprecision(1) << fixed << avg << endl;

}