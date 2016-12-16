// test_generation.cpp
#include <iostream>
using namespace std;

#include "../include/Generation.h"
#include "../include/parameters/constants.h"

// compile: clang++ -Wall -Wextra test_generation.cpp Generation.cpp melody.cpp note.cpp termfuncs.cpp -o test_generation

int main ()
{
	Generation g(INIT_POPULATION_SIZE);
	
	g.score_all();
	g.display_melodies();

	EvolutionSpecs specs;
	specs.rhythmic_chance = INIT_RHYTHMIC_REDISTRIBUTION_CHANCE;
	specs.rhythmic_rate = INIT_RHYTHMIC_REDISTRIBUTION_RATE;
	specs.smooth_chance = INIT_SMOOTHING_CHANCE;
	specs.smooth_rate = INIT_SMOOTHING_RATE;
	specs.theme_chance = INIT_THEMATIC_GENERATION_CHANCE;
	specs.theme_rate = INIT_THEMATIC_GENERATION_RATE;
	specs.note_chance = INIT_NOTE_MUTATION_CHANCE;
	specs.note_rate = INIT_NOTE_MUTATION_RATE;

	cout << "NEXT GEN: " << endl;
	Generation *next_gen = g.create_next_gen(INIT_POPULATION_SIZE, specs);
	next_gen->score_all();
	next_gen->display_melodies();


}