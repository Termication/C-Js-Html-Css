#include <iostream>
using namespace std;

void getJudgeData(double &score)
{
    do {
        cout << "Enter judge's score: ";
        cin >> score;
    } while (score < 0 || score > 10);
}

double calcScore(double score1, double score2, double score3, double score4, double score5)
{
    double highest = score1;
    double lowest = score1;

    // Find the highest and lowest scores
    if (score2 > highest) {
        highest = score2;
    }
    else if (score2 < lowest) {
        lowest = score2;
    }

    if (score3 > highest) {
        highest = score3;
    }
    else if (score3 < lowest) {
        lowest = score3;
    }

    if (score4 > highest) {
        highest = score4;
    }
    else if (score4 < lowest) {
        lowest = score4;
    }

    if (score5 > highest) {
        highest = score5;
    }
    else if (score5 < lowest) {
        lowest = score5;
    }

    double sum = score1 + score2 + score3 + score4 + score5 - highest - lowest;
    double average = sum / 3.0;
    return average;
}

double findLowestScore(double score1, double score2, double score3, double score4, double score5)
{
    double lowest = score1;

    if (score2 < lowest) {
        lowest = score2;
    }

    if (score3 < lowest) {
        lowest = score3;
    }

    if (score4 < lowest) {
        lowest = score4;
    }

    if (score5 < lowest) {
        lowest = score5;
    }

    return lowest;
}

double findHighestScore(double score1, double score2, double score3, double score4, double score5)
{
    double highest = score1;

    if (score2 > highest) {
        highest = score2;
    }

    if (score3 > highest) {
        highest = score3;
    }

    if (score4 > highest) {
        highest = score4;
    }

    if (score5 > highest) {
        highest = score5;
    }

    return highest;
}

void displayOutput(double finalScore, double lowestScore, double highestScore)
{
    cout << "Contestant's final score: " << finalScore << std::endl;
    cout << endl;
    cout << "Lowest score: " << lowestScore << std::endl;
    cout << endl;
    cout << "Highest score: " << highestScore << std::endl;
}


int main()
{
    double score1, score2, score3, score4, score5;
    double finalScore;

    getJudgeData(score1);
    getJudgeData(score2);
    getJudgeData(score3);
    getJudgeData(score4);
    getJudgeData(score5);

    finalScore = calcScore(score1, score2, score3, score4, score5);

    double lowestScore = findLowestScore(score1, score2, score3, score4, score5);

    double highestScore = findHighestScore(score1, score2, score3, score4, score5);

    displayOutput(finalScore, lowestScore, highestScore);

}
