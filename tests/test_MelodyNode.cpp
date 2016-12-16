// test_MelodyNode.cpp
// MelodyNode test file
// By: Ari Brown
// Nov. 28, 2016

#include <iostream>
using namespace std;

#include "../include/MelodyNode.h"

// compile: clang++ -Wall -Wextra melody.cpp score.cpp otherfuncs.cpp termfuncs.cpp note.cpp test_MelodyNode.cpp -o test_MelodyNode

int main ()
{
	cout << "Creating two default melodyNodes" << endl;
	MelodyNode melNodeDad;
	MelodyNode melNodeMom;
	melNodeDad.print();
	melNodeMom.print();
	melNodeDad.print_parents();
	melNodeMom.print_parents();

	cout << "Creating overloaded melodyNode" << endl;
	MelodyNode my_melodyNode(&melNodeMom, &melNodeDad);
	my_melodyNode.print();
	my_melodyNode.print_children();

	cout << "Printing dad's children:" << endl;
	melNodeDad.print_children();
	cout << "Printing mom's children:" << endl;
	melNodeMom.print_children();

	cout << "Getting mom:" << endl;
	cout << my_melodyNode.get_mom() << endl;

	cout << "Getting dad:" << endl;
	cout << my_melodyNode.get_dad() << endl;

	cout << "Get fitness:" << endl;
	cout << my_melodyNode.get_fitness() << endl;

	cout << "Get Melody:" << endl;
	my_melodyNode.get_melody()->print_melody();

	cout << "Setting parents to NULL:" << endl;
	my_melodyNode.set_parents_NULL();

	my_melodyNode.print();

	return 0;
}