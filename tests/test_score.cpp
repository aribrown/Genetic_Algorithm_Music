// test_score.cpp
// Scoring functions test file
// By: Ari Brown
// Nov. 28, 2016

// compile:  clang++ -Wall -Wextra melody.cpp score.cpp test_score.cpp otherfuncs.cpp termfuncs.cpp note.cpp -o test_score

#include<iostream>
using namespace std;

#include "../include/melody.h"
#include "../include/score.h"

int main ()
{
	Melody mel1;
	mel1.print_melody(); cout << endl;

	Score scorer(&mel1);
	int score = scorer.get_score();
	cout << "Score: " << score << endl;

	return 0;
}