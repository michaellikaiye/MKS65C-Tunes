#ifndef LIB_H
#define LIB_H

struct song_node *table[27];

/* Sets up table with null values */
void setup();

/* Add song nodes. */
void add(char song[100], char artist[100]);

/* Search for a song given song and artist name (return a pointer). */
struct song_node *searchS(char song[100], char artist[100]);

/* Search for an artist. */
struct song_node *searchA(char artist[100]);

/* Print out all the entries under a certain letter. */
void print_letters(char letter);

/* Print out all the songs of a certain artist */
void print_songs(char artist[100]);

/* Print out the entire library. */
void print_all();

/* Shuffle - print out a series of randomly chosen songs. */
void print_shuffle();

/* Delete a song */
void remove_song(char song[100], char artist[100]);

/* Clear the library. */
void clear_library();

#endif
