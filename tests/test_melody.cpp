// test_melody.cpp
// Melody class test file
// By: Ari Brown
// Nov. 28, 2016

// compile:  clang++ -Wall -Wextra melody.cpp test_melody.cpp otherfuncs.cpp termfuncs.cpp note.cpp -o test_melody

#include<iostream>
using namespace std;

#include "../include/termfuncs.h"
#include "../include/melody.h"
#include "../include/note.h"

int main ()
{
	Melody my_melody;
	my_melody.print_melody(); cout << endl;


	Melody second_melody(my_melody);
	cout << "COPY CONSTRUCTOR (identical): " << endl;
	second_melody.print_melody(); cout << endl;

	Melody third_melody;
	third_melody = my_melody;
	cout << "ASSIGNMENT OPERATOR (identical): " << endl;
	third_melody.print_melody(); cout << endl;

	/*my_melody.smooth_by_average(0);
	cout << "SMOOTHING BY AVERAGE: " << endl;
	my_melody.print_melody(); cout << endl;*/

	Note *note = my_melody.note_at(3);
	note->print_note(); cout << endl;

	Melody parent_melody;

	cout << "CREATING MELODY CHILD - from these two:" << endl;
	cout << "mom: "; second_melody.print_melody(); cout << endl;
	cout << "dad: "; parent_melody.print_melody(); cout << endl;
	cout << "--------- child ---------" << endl;
	Melody child_melody(second_melody, parent_melody);
	child_melody.print_melody(); cout << endl;

	return 0;
}
