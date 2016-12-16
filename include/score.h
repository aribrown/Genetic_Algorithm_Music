// score.h
// Scoring class definition for genetic algorithm
// 	for music composition
// By: Ari Brown
// Nov. 28, 2016

#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include "melody.h"

class Score {

	public:
		// constructor computes score from melody pointer
		Score(Melody *melody);

		// default constructor/destructor
		Score(); 
		~Score();

		// pass in a new melody to calculate score
		void reinitialize(Melody *melody);

		// get the resulting score
		int get_score();

	private:
		// the score
		int total_score;

		// array for scoring progression of chords detected,
		// filled as chords are found
		int *chord_progression;

		// array data
		int progression_cap;
		int progression_count;

		// ensure the array can hold amount of chords
		void ensure_capacity();

		// calculates the melody's score, with helper functions
		void calculate(Melody *melody);

			// diatonic fitness
			int analyze_diatonic_fit(Melody *melody);

			// chord matches (with helper functions)
			int analyze_chords(Melody *melody); 
			bool tally_matches(const int chord_pitches[], 
				int chord_size, 
				int possible_chord[], int chord_num);
			bool chord_match(const int chord[], int chord_size, 
				int possible_chord[], 
				int possible_chord_size);

			// analyze smooth voice leading, regardless of 
			// octave
			int analyze_voice_leading(Melody *melody);

			// analyze smoothness with octave
			int analyze_smoothness(Melody *melody);

			// analyze chord progression for favored patterns
			int analyze_chord_progression(Melody *melody);

};

#endif