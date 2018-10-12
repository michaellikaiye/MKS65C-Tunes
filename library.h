/* Add song nodes. */
/* Search for a song given song and artist name (return a pointer). */
/* Search for an artist. */
/* Print out all the entries under a certain letter. */
/* Print out all the songs of a certain artist */
/* Print out the entire library. */
/* Shuffle - print out a series of randomly chosen songs. */
/* Delete a song */
/* Clear the library. */

//dont know if necessary
struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
} song_node;

struct song_node *table[27];

struct song_node *searchS(char *song, char *artist);
struct song_node *searchA(char *artist);
void print_letters(char letter);
void print_songs(char *artist);
void print_all();
void print_shuffle();
void delete(char *song);
void clear();
