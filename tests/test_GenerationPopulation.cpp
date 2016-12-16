// test_GenerationPopulation.cpp
// Test file for a generation
// By: Ari Brown
// Nov. 28, 2016

// compile: clang++ -Wall -Wextra melody.cpp test_GenerationPopulation.cpp GenerationPopulation.cpp MelodyNode.cpp otherfuncs.cpp termfuncs.cpp score.cpp note.cpp -o test_generationPopulation

#include<iostream>
using namespace std;

#include "../include/GenerationPopulation.h"
#include "../include/parameters/constants.h"
#include "../include/parameters/options.h"

int main ()
{
	GenerationPopulation gen0;
	gen0.print();

	cout << "Creating new gen using constructor:" << endl;

	GenerationPopulation gen1(gen0);
	gen1.print();

	return 0;
}
