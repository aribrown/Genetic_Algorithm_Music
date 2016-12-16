// test_GenerationQueue.cpp
// Test file for a queue of generations
// By: Ari Brown
// Nov. 28, 2016

// compile: clang++ -Wall -Wextra melody.cpp test_GenerationQueue.cpp GenerationQueue.cpp GenerationPopulation.cpp otherfuncs.cpp termfuncs.cpp note.cpp -o test_generationQueue


#include<iostream>
using namespace std;

#include "../include/termfuncs.h"
#include "../include/melody.h"
#include "../include/GenerationQueue.h"
#include "../include/GenerationPopulation.h"

int main ()
{
	GenerationPopulation gen1;
	MelodyNode mel1;
	gen1.insertAtBack(mel1);
	/*cout << "GEN1:" << endl;
	gen1.print();*/

	GenerationPopulation gen2;
	MelodyNode mel2;
	gen2.insertAtBack(mel2);
	gen2.insertAtBack(mel1);
	/*cout << "GEN2:" << endl;
	gen2.print();*/

	GenerationPopulation gen3;
	MelodyNode mel3;
	gen3.insertAtBack(mel3);
	gen3.insertAtBack(mel1);
	/*cout << "GEN3:" << endl;
	gen3.print();*/

	GenerationPopulation gen4;
	MelodyNode mel4;
	gen4.insertAtBack(mel4);
	gen4.insertAtBack(mel1);
	cout << "GEN4:" << endl;
	gen4.print();

	// add these generations to the queue
	GenerationQueue queue;
	queue.insertAtBack(gen1);
	queue.print();
	queue.insertAtBack(gen2);
	queue.print();
	queue.insertAtBack(gen3);
	queue.print();

	// should destroy the oldest
	// (GENERATIONS_SAVED = 3 in constants.h)
	/*queue.insertAtBack(gen4);
	queue.print();
	queue.insertAtBack(gen1);
	queue.print();
	*/
	cout << "RETURN 0" << endl;
	return 0;
}
