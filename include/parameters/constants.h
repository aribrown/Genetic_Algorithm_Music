// constants.h
// Constant definitions for Genetic Algorithm
// By: Ari Brown
// Nov. 28, 2016

#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

////////////////////////////////////////////////////////////////
//////////////////////// MUSIC THEORY //////////////////////////
////////////////////////////////////////////////////////////////

//// notes ////
enum NotePitches 
{
        C,
        CS,
        D,
        DS,
        E,
        F,
        FS,
        G,
        GS,
        A,
        AS,
        B,
        TOTAL_PITCHES
};

// quarter note length
const float QUARTER = 0.25;

// chordal structures defined by scale degrees (0-11)
const int one_chord [] = {0, 4, 7};
const int two_chord [] = {2, 5, 9};
const int three_chord [] = {4, 7, 11};
const int four_chord [] = {5, 9, 0};
const int five_chord []  = {7, 11, 2};
const int six_chord [] = {9, 0, 4};
const int seven_chord [] = {11, 2, 5};

// patterns of chords defined by chord number (1-7)
const int CHORD_PATTERN_AMOUNT = 12;
const int chord_patterns [CHORD_PATTERN_AMOUNT][3] = {

        // resolving on tonic
        {4, 5, 1},
        {2, 5, 1},
        {6, 5, 1},
        {1, 5, 1},
        {5, 5, 1},

        // resolving on dominant
        {1, 5, 5},
        {1, 4, 5},
        {1, 2, 5},
        {6, 4, 5},
        {1, 1, 5},

        // predominant
        {6, 4, 2},

        // other
        {1, 2, 3}
};

////////////////////////////////////////////////////////////////
//////////////////////// CHANCES ///////////////////////////////
////////////////////////////////////////////////////////////////

const float CHANCE_OF_REST = 0.1;

// make sure that these add to 1
const float CHANCE_OF_LONG_SHORT = 0.3;
const float CHANCE_OF_SHORT_LONG = 0.1;
const float CHANCE_OF_SPLIT_EVEN = 0.6;

const float SMOOTHING_CHANCE = 0.3;
const float RHYTHMIC_REDISTRIBUTION_CHANCE = 0.4;
const float NOTE_MUTATION_CHANCE = 0.8;

const int SMOOTHING_ATTEMPTS = 10;
const int RHYTHMIC_REDISTRIBUTION_ATTEMPTS = 10;
const int NOTE_MUTATION_ATTEMPTS = 40;

////////////////////////////////////////////////////////////////
//////////////////////// SCORING ///////////////////////////////
////////////////////////////////////////////////////////////////

// points assigned to notes in the key
const int DIATONIC_WEIGHT = 1;

// points assigned to recognizing a chord progression
const int CHORD_PROGRESSION_REWARD = 20;

// points assigned to recognizing each type of chord
const int ONE_CHORD_POINTS = 5;
const int TWO_CHORD_POINTS = 4;
const int THREE_CHORD_POINTS = 1;
const int FOUR_CHORD_POINTS = 4;
const int FIVE_CHORD_POINTS = 5;
const int SIX_CHORD_POINTS = 4;
const int SEVEN_CHORD_POINTS = 1;

// points assigned if melody starts/ends on tonic note
const int TONIC_ENDPOINTS = 3;

// points assigned to smoothness based on relative pitch
const int VOICE_LEADING_POINTS = 0;

// points assigned to smoothness based on absolute pitch
const int SMOOTHNESS_POINTS = 1;

////////////////////////////////////////////////////////////////
//////////////////////// OTHER PARAMETERS //////////////////////
////////////////////////////////////////////////////////////////

const float PROG_POW_BASE = 2.0;

// mutation of melody by smoothing random segment
const int SMOOTHING_WINDOW = 4; 

// window used to combine melody segments in breeding
const int ALLELE_WINDOW = 10;

// amount of times one note can be altered rhythmically
const int RHYTHMIC_ALTERATIONS = 5;


// amount notes looked at to identify three note chord
const int CHORD_WINDOW = 4; 
// amount of notes that don't have to match in window
const int CHORD_ERRORS = 1; 
// amount of notes that have to be distinct in window
const int DISTINCT_NOTES = 3; 


const int MAX_CHILDREN = 40; // max amount of children a MelodyNode can have

const int ELITIST_SIZE = 3; // num top notes in pick_from_best

const int MIDI_CORRECTION = 24; // offset to midi numbers

// "roulette" is only option right now
const std::string CHOOSE_MODE = "roulette";

// enable all debugging print statements
const bool DEBUG_MODE = false;

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#endif
