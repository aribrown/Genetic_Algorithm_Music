// test_note.cpp
// Note class test file
// By: Ari Brown
// Nov. 28, 2016

// compile:  clang++ -Wall -Wextra note.cpp test_note.cpp termfuncs.cpp otherfuncs.cpp -o test_note

#include <iostream>
using namespace std;

#include "../include/note.h"
#include "../include/otherfuncs.h"
#include "../include/parameters/constants.h"

int main ()
{
        cout << "KEY: " << pitch_to_string(KEY) << endl << endl;

        cout << "Note: ";
        Note my_note;
        my_note.print_note();
        cout << endl;

        cout << "Get key num: " << my_note.get_key_num() << endl;
        cout << "Get duration: " << my_note.get_duration() << endl;
        cout << "Get scale degree: " << my_note.get_scale_degree() << endl;
        cout << "Get pitch: " << my_note.get_pitch() << endl;
        cout << "Get diatonic: " << my_note.get_diatonic() << endl;

        cout << endl << "POSSIBLE MUTATIONS: " << endl;
        my_note.mutate(1);
        cout << "half step up: "; my_note.print_note(); cout << endl;
        my_note.mutate(2);
        cout << "half step down: "; my_note.print_note(); cout << endl;
        my_note.mutate(3);
        cout << "whole step up: "; my_note.print_note(); cout << endl;
        my_note.mutate(4);
        cout << "whole step down: "; my_note.print_note(); cout << endl;
        my_note.mutate(5);
        cout << "octave up: "; my_note.print_note(); cout << endl;
        my_note.mutate(6);
        cout << "octave down: "; my_note.print_note(); cout << endl;
        my_note.mutate(7);
        cout << "flip rest: "; my_note.print_note(); cout << endl;

        cout << endl << "Transpose octave: " << endl;
        my_note.transpose_oct("up");
        cout << "octave up: "; my_note.print_note(); cout << endl;
        my_note.transpose_oct("down");
        cout << "octave down: "; my_note.print_note(); cout << endl;
        

        return 0;       
}

