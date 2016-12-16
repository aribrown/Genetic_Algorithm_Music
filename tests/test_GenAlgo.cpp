// test_GenAlgo.cpp
// Genetic Algorithm test file
// By: Ari Brown
// Nov. 28, 2016

// compile:  clang++ -Wall -Wextra GenAlgo.cpp melody.cpp score.cpp GenerationPopulation.cpp GenerationQueue.cpp test_GenAlgo.cpp otherfuncs.cpp termfuncs.cpp note.cpp melody2midi.cpp -o test_GenAlgo


#include <iostream>
using namespace std;

#include "../include/GenAlgo.h"

int main ()
{
	GenAlgo my_algorithm;
	
	my_algorithm.run();

	return 0;
}