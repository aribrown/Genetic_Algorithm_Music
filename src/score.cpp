// score.cpp
// Scoring function implementation for genetic algorithm
// 	for music composition
// By: Ari Brown
// Nov. 28, 2016

#include<iostream>
using namespace std;

#include "../include/parameters/options.h"
#include "../include/score.h"
#include "../include/melody.h"
#include "../include/note.h"
#include "../include/otherfuncs.h"
#include "../include/parameters/constants.h"
#include <cstdlib>
#include <cmath>

/* Score class default constructor 
Args: None
Return: None
*/
Score::Score()
{
	chord_progression = new int[10];
	progression_count = 0;
	progression_cap = 10;
}

/* scores a melody line using all scoring helper functions
Args: a pointer to a Melody
Return: none
*/
Score::Score(Melody *melody)
{
	chord_progression = new int[10];
	progression_count = 0;
	progression_cap = 10;

	calculate(melody);
}

/* reinitalize, pass in new melody to score
Args: a pointer to a melody
Return: none
*/
void Score::reinitialize(Melody *melody)
{
	delete [] chord_progression;

	chord_progression = new int[10];
	progression_count = 0;
	progression_cap = 10;

	calculate(melody);
}

/* calculate the melody's score
Args: pointer to a Melody
Return: none
*/
void Score::calculate(Melody *melody)
{
	total_score = 0;
	total_score += analyze_diatonic_fit(melody);
	total_score += analyze_voice_leading(melody);
	total_score += analyze_smoothness(melody);
	total_score += analyze_chords(melody);

	// must be called *after* the chord identifier
	total_score += analyze_chord_progression(melody); 
}

/* Score class destructor
Args: None
Return: None
*/
Score::~Score()
{
	// delete heap allocated memory
	delete [] chord_progression;
}

/* Get the calculated score for a melody
Args: None
Return: integer score
*/
int Score::get_score()
{
	return total_score;
}

/* assigns subscore based on how many notes fit in the key
	Weight of importance of diatonic notes is defined in constants.h
Args: pointer to a Melody
Return: integer subscore
*/
int Score::analyze_diatonic_fit(Melody *melody)
{
	int score = 0;
	int mel_size = melody->get_size();

	for (int i = 0; i < mel_size; i++)
	{
		// make sure the note isn't a rest
		if (!melody->note_at(i)->get_rest())
		{
			int scale_degree = melody->note_at(i)->get_scale_degree();
			if (is_diatonic(scale_degree))
			{
				score += DIATONIC_WEIGHT;
			}
		}
	}
	return score;
}

/* Assign subscore to melody based on the presence of chords in the melody
Args: pointer to a Melody
Return: integer subscore
*/
int Score::analyze_chords(Melody *melody)
{	
	int score = 0;

	int mel_size = melody->get_size();
	int current_note = 0;
	while (current_note < mel_size)
	{
		// divide into window of scale degrees
		int window[CHORD_WINDOW];
		int window_count = 0;
		int iterator = 0;
		while (window_count < CHORD_WINDOW)
		{
			if (current_note + iterator < mel_size)
			{
				// check if rest
				if(!melody->note_at(iterator)->get_rest())
				{
					window[window_count] = 
					melody->
					note_at(current_note + iterator)
					->get_scale_degree();
					window_count++;
					iterator++;
				}
				else
				{
					iterator++;
				}
			}
			else
			{
				window[window_count] = -1; // some non-match
				window_count++;
			}
		}

		
		bool chord_found = false;

		// check for all chords given the window
		if (tally_matches(one_chord, 3, window, 1))
			{score += ONE_CHORD_POINTS; chord_found = true;}
		if (tally_matches(two_chord, 3, window, 2))
			{score += TWO_CHORD_POINTS; chord_found = true;}
		if (tally_matches(three_chord, 3, window, 3))
			{score += THREE_CHORD_POINTS; chord_found = true;}
		if (tally_matches(four_chord, 3, window, 4))
			{score += FOUR_CHORD_POINTS; chord_found = true;}
		if (tally_matches(five_chord, 3, window, 5))
			{score += FIVE_CHORD_POINTS; chord_found = true;}
		if (tally_matches(six_chord, 3, window, 6))
			{score += SIX_CHORD_POINTS; chord_found = true;}
		if (tally_matches(seven_chord, 3, window, 7))
			{score += SEVEN_CHORD_POINTS; chord_found = true;}


		// if a chord was found
		if (chord_found) {
			current_note += CHORD_WINDOW;
		}
		else // otherwise, adjust window note by note
		{
			current_note++;
		}
	}

	return score;
}

bool Score::tally_matches(const int chord_pitches[], int chord_size, 
	int possible_chord[], int chord_num)
{
	bool success = false;
	// if the chord matches, skip over the current window
	if (chord_match(chord_pitches, chord_size, 
		possible_chord, CHORD_WINDOW))
	{
		success = true;

		// add the chord to the progression array
		ensure_capacity();
		chord_progression[progression_count] = chord_num;
		progression_count++;
	}
	return success;
}

/* Searches for a chord in a ceratin window of notes
	Note: table of used notes allocated to search for
		unique notes (same note can't be repeated to make chord)
Args: array specifying the chord scale degrees (ints), size of chord (int),
	array of scale degrees to search in (ints), 
	and the size of that array (int)
Return: boolean whether found
*/ 
bool Score::chord_match(const int chord[], int chord_size,
 int possible_chord[], int possible_chord_size)
{
	int matches = 0;
	bool used [3] = {false, false, false};

	for (int i = 0; i < possible_chord_size; i++)
	{
		bool found = false;
		for (int j = 0; j < chord_size; j++)
		{
			if (chord[j] == possible_chord[i])
			{
				if( used[j] == false)
				{
					found = true;
					used[j] = true;
				}
			}
		}

		if (found)
		{
			matches++;
		}
	}

	// if enough notes matched in the window
	if (matches >= CHORD_WINDOW - CHORD_ERRORS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Assign subscore based on smoothness of scale degree
	changes regardless of octave
Args: pointer to a Melody
Return: integer subscore
*/
int Score::analyze_voice_leading(Melody *melody)
{
	int score = 0;
	int mel_size = melody->get_size();
	for (int i = 0; i < mel_size - 1; i++) // goes til 
		// second to last note
	{
		// whole or half steps, using the pitch number
		if (!melody->note_at(i)->get_rest() 
			&& !melody->note_at(i+1)->get_rest()
			&& abs(melody->note_at(i)->get_scale_degree()
			 - melody->note_at(i+1)->get_scale_degree()) <= 2)
		{
			score += VOICE_LEADING_POINTS;
		}

	}

	return score;
}

/* Assign subscore based on smoothness of note and octave
Args: pointer to a Melody
Return: integer subscore
*/
int Score::analyze_smoothness(Melody *melody)
{
	int score = 0;
	int mel_size = melody->get_size();
	for (int i = 0; i < mel_size - 1; i++) // goes til 
		// second to last note
	{
		// whole or half steps, using the keynum number
		if (!melody->note_at(i)->get_rest() 
			&& !melody->note_at(i+1)->get_rest()
			&& abs(melody->note_at(i)->get_key_num()
			 - melody->note_at(i+1)->get_key_num()) <= 2)
		{
			score += SMOOTHNESS_POINTS;
		}

	}

	return score;
}

/* Assign subscore based on the progression of chords
	Note: must be called *after* analyze_chords() has already been called,
		analyze_chords() fills the chord progression array
Args: none
Return: integer subscore
*/
int Score::analyze_chord_progression(Melody *melody)
{
	int score = 0;

	// check start and end notes
	if (melody->note_at(0)->get_scale_degree() == 0 
		&& !melody->note_at(0)->get_rest()) 
		{score += TONIC_ENDPOINTS;}
	if (melody->note_at(melody->get_size() - 1)->
		get_scale_degree() == 0 && !melody->
		note_at(melody->get_size() - 1)->get_rest()) 
		{score += TONIC_ENDPOINTS;}

	int num_matches = 0;
	// split into 3-chord windows to check against defined progressions
	for (int i = 0; i < progression_count - 2; i++)
	{
		int window [3] = {chord_progression[i], 
			chord_progression[i+1],
			chord_progression[i+2]};

		for (int j = 0; j < CHORD_PATTERN_AMOUNT; j++)
		{
			if (window[0] == chord_patterns[j][0]
				&& window[1] == chord_patterns[j][1]
				&& window[2] == chord_patterns[j][2])
			{
				score += 
				(CHORD_PROGRESSION_REWARD 
					* pow(PROG_POW_BASE, num_matches));
				num_matches++;
			}
		}
	}
	return score;
}

/* Expand array that stores progression of chords, if needed
Args: none
Return: none
*/
void Score::ensure_capacity()
{
	if (progression_count == progression_cap)
	{
		 // temporary sequence twice the size
        	int *temp = new int[progression_cap*2];

	        // copy everything over
	        for (int i = 0; i < progression_count; i++)
	        {
	                temp[i] = chord_progression[i]; 
	        }
	        
	        // delete the old sequence
	        delete [] chord_progression;

	        // update capacity
	        progression_cap = progression_cap*2;
	        
	        // update pointer
	        chord_progression = temp;	
	}
}
